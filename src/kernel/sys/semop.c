#include <sys/sem.h>
#include <sys/mysem.h>
#include <nanvix/hal.h>
#include <nanvix/klib.h>

PUBLIC int sys_semop(int semid, int op){

	int val_return;
	
	if (op < 0) {
		
		for (int i = 0; i < -op; ++i)
		{
			val_return = down(semid);
		}
	
	} else if (op > 0) {
		
		for (int i = 0; i < op; ++i)
		{
			val_return = up(semid);
		}
	}
	
	else {
	
		val_return = -1;
	}
	
	return val_return;

}
