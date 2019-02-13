#include <sys/sem.h>
#include <sys/mysem.h>
#include <nanvix/hal.h>
#include <nanvix/klib.h>

PUBLIC int sys_semop(int semid, int op){

	kprintf("Entree Semop");
	int val_return;
	disable_interrupts();
	if (op < 0) {
		
		val_return = down(semid);
	
	} else if (op > 0) {
	
		val_return = up(semid);
	}
	
	else {
	
		val_return = -1;
	}
	
	enable_interrupts();

	kprintf("Sortie Semop val_return=%d", val_return);
	return val_return;

}
