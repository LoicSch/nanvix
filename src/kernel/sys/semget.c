#include <sys/sem.h>
#include <sys/mysem.h>

PUBLIC int sys_semget(unsigned key){

	struct semaphore *s = FIRST_SEM;
	int semid = 0;
	
	while (s->key != key && s<= LAST_SEM) {
		
		semid++;
		s++;
	}
	
	if (s <= LAST_SEM) {
		
		return semid;
		
	} else {
	
		semid  = create(0, key);
		return semid;
		
	}

}
