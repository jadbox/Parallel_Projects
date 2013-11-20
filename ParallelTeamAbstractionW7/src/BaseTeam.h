/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/

#ifndef BASETEAM_H_
#define BASETEAM_H_

#include <time.h>
//shared memory
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
using namespace std;

typedef void (*executionEntryFunc)(void *);

class BaseTeam {
public:
	BaseTeam() {};
	virtual ~BaseTeam(){};

	//0 = Normal Termination, any other value = abnormal
	int termStatus;
	executionEntryFunc *startFuncs;

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
	//peform the lock() operation on a semaphore with the given index.
	virtual void lockSemaphoreInSet(int index);
	//perform the unlock() operation on a semaphore with the given index.
	virtual void unlockSemaphoreInSet(int index);
	//unlock all semaphores in the set.
	virtual void unlockSemaphoreSet();
	//permit all compute units to begin executing instructions.
	virtual void startAllTeamMembers() { startTime = time(NULL); }
	//wait until all compute units have completed execution instructions.
	virtual void waitForAllTeamMembers();
	// return the number of compute units in the team.
	virtual int getSizeOfTeam() { return numCompUnits; }
	//Configure the default function that should be called to begin program execution for each member of the Team.
	void setEntryFunction(executionEntryFunc startFunc);
	//configure the function that a specific team member should call in order to begin program execution.
	void setEntryFunction(int index, executionEntryFunc startFunc);
protected:
	//Semaphore ID
	int sem_id;
	//specified in createTeam()
	int numCompUnits;
	//start time for members
	time_t startTime;
	//calc total execution time for members
	time_t execTime;
};

#endif /* BASETEAM_H_ */
