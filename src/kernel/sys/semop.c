#include <sys/sem.h>
#include <sys/mysem.h>
#include <nanvix/hal.h>

PUBLIC int sys_semop(int semid, int op){
	disable_interrupts();
	if (op < 0) {
		
		return down(semid);
	
	} else if (op > 0) {
	
		return up(semid);
	}
	
	else {
	
		return -1;
	}
	enable_interrupts();
}
