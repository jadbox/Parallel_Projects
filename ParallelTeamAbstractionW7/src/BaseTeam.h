/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/

#ifndef BASETEAM_H_
#define BASETEAM_H_

#include <time.h>
//shared memory
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include "utils/HPTimer.h"
#include <iostream>
#include <Math.h>

#include <sys/types.h>  /* Primitive System Data Types */
#include <semaphore.h>  /* Semaphore */

using namespace std;



typedef void (*executionEntryFunc)(void *);

class BaseTeam {
public:
	BaseTeam(int* data, int length):data(data), length(length) {};
	virtual ~BaseTeam(){};

	//0 = Normal Termination, any other value = abnormal
	int termStatus;
	executionEntryFunc *startFuncs;

	// accumulated result
	int result;

	//virtual void setData(int* arr, int size);

	//create a team of n processing units of the given type.
	//For example createProcessTeam(100) creates a team of 100 processes.
	virtual void createTeam(int n);
	//create a set of semaphores where each team member can access the semaphore corresponding to its index.
	virtual void createSemaphoreSet(int n);
	//delete a set of semaphores and release all associated resources.
	virtual void deleteSemaphoreSet();
	//set the initial values for all semaphores in the set using the arrays.
	//Note this call is valid only before semaphores are put into use.
	virtual void setAllSemaphoresInSet(unsigned short *values);
	//perform the lock() operation on a semaphore with the given index.
	virtual void lockSemaphoreInSet(int index);
	//perform the unlock() operation on a semaphore with the given index.
	virtual void unlockSemaphoreInSet(int index);
	//unlock all semaphores in the set.
	virtual void unlockSemaphoreSet();
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers()=0;
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers()=0;
	// return the number of compute units in the team.
	virtual int getSizeOfTeam() { return numCompUnits; }
	//Configure the default function that should be called to begin program execution for each member of the Team.
	void setEntryFunction(executionEntryFunc startFunc);
	//configure the function that a specific team member should call in order to begin program execution.
	void setEntryFunction(int index, executionEntryFunc startFunc);
protected:
	// Mutex locks
	sem_t* mutexes;
	// termination statuses
	int* terminations;
	// start counting time
	void startTimer();
	//  stops the timer and displays time taken in output
	void stopAndDisplayTime();

	//Semaphore ID
	int sem_id;
	//specified in createTeam()
	int numCompUnits;
	//Pointer to array
	int *data;
	//start time for members
	double startTime;
	//calc total execution time for members
	//double execTime;
	int length;
};

struct ProcessParams {
	BaseTeam* obj;
	int* data;
	int length;
};

#endif /* BASETEAM_H_ */
