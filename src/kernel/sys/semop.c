#include <sys/sem.h>
#include <sys/mysem.h>
#include <nanvix/hal.h>
#include <nanvix/klib.h>

PUBLIC int sys_semop(int semid, int op){

	//kprintf("Entree Semop");
	int val_return;
	int i = 0;
	
	if (op < 0) {
		
		while(i > op) {
			
			val_return = down(semid);
			i--;
		}
	
	} else if (op > 0) {
		
		i=0;
		
		while (i < op) {
	
			val_return = up(semid);
			i++;
		}
	}
	
	else {
	
		val_return = -1;
	}
	

	//kprintf("Sortie Semop val_return=%d", val_return);
	return val_return;

}
