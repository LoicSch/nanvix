#include <nanvix/pm.h>

#define FIRST_SEM ((&semtab[0]))           /**< First semaphore. */
#define LAST_SEM ((&semtab[PROC_MAX - 1])) /**< Last semaphore.  */

/* Semaphore structure */
struct semaphore
{
	int valid; /* Is the process is valid ? */
	int key; /* Key associated to the semaphore */
	int val; /* Value of the semaphore */
	struct process **queue; /* Queue of process */
};

struct semaphore semtab[PROC_MAX];

void init_sem();
int create(int n);
int down (int semid);
int up(int semid);
int destroy(int semid);