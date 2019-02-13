#include <sys/sem.h>
#include <sys/mysem.h>
#include <nanvix/klib.h>

PUBLIC int sys_semctl(int semid, int cmd, int val){

	kprintf("Entree Semctl");
	int val_return;
	struct semaphore *s;
	switch(cmd){
		case GETVAL:
			s = (&semtab[semid]);
			if(s->valid){
				val_return = s->value;
			} else {
				val_return = -1;
			}
			break;
		case SETVAL:
			s = (&semtab[semid]);
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
	kprintf("Sortie Smctl val_return=%d",val_return);
	return val_return;
}