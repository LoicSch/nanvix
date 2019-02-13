#include <sys/sem.h>
#include <sys/mysem.h>

PUBLIC int sys_semctl(int semid, int cmd, int val){
	int val_return;
	switch(cmd){
		case GETVAL:
			struct semaphore *s = semtab[semid];
			if(s->valid){
				val_return = s->value;
			} else {
				val_return = -1;
			}
			break;
		case SETVAL:
			struct semaphore *s = semtab[semid];
			if(s->valid){
				s->value = val;
				val_return = 0;	
			} else {
				val_return = -1;
			}
			break;
		case IPC_RMID:
			val_return = destroy(semid);
			break;
		default:
			val_return = -1;
			break;
	}
	return val_return;
}