#include <sys/sem.h>
#include <sys/mysem.h>
#include <nanvix/klib.h>

PUBLIC int sys_semget(unsigned key){

	kprintf("Entree semget");
	struct semaphore *s = FIRST_SEM;
	int semid = 0;
	
	while (s <= LAST_SEM && (!s->valid || s->key != key)) {
		
		semid++;
		s++;
	}
	
	if (s <= LAST_SEM) {
		
		return semid;
		
	} else {
	
		semid  = create(VAL_INIT, key);
		kprintf("Sortie semget semid=%d",semid);
		return semid;
		
	}

}
