#include <sys/sem.h>
#include <nanvix/pm.h>
#include <nanvix/klib.h>
#include <nanvix/config.h>
#include <sys/mysem.h>
#include <nanvix/klib.h>

PUBLIC struct semaphore semtab[PROC_MAX];

void init_sem(){
	struct semaphore *s;

	for (s = FIRST_SEM; s <= LAST_SEM; s++)
	{
		s->valid = 0;
	}
}

/* Create a semaphore and initialize it with n */
int create(int n){
	struct semaphore *s = FIRST_SEM;
	int semid = 0;

	while(s->valid && s <= LAST_SEM){
		semid++;
		s++;
	}

	if(s <= LAST_SEM){
		s->valid = 1;
		s->key = semid;
		s->value = n;
		s->queue = NULL;

		return semid;		
	}
	else{
		return (-1);
	}
}

/* Test the semaphore value. If it's positive, then it decreased and the process follow its execution 
   else the process is bloqued in the waiting list */
int down (int semid){
	struct semaphore *s = semtab[semid];

	if(s->value > 0){
		s->value--;
	}
	else{
		sleep(s->queue, 0);
	}
	return 0;
}

/* Test the semaphore value. If it's nulle and there is a process in the waiting list, then the process 
   is debloqued. Else the value is increased */
int up(int semid){
	struct semaphore *s = semtab[semid];

	if(s->value == 0 && s->queue != NULL){
		wakeup(s->queue);
	}
	else{
		s->value++;
	}
	return 0;
}

/* destroy the semaphore */
int destroy(int semid){
	struct semaphore *s = semtab[semid];
	s->valid = 0;
	return 0;
}
