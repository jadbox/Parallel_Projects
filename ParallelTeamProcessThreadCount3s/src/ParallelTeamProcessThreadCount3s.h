/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeamProcessThreadCount3

Data: 10/16/2013

*/
#ifndef PARALLELTEAM_H_
#define PARALLELTEAM_H_

#include <vector>
#include <unistd.h>
#include "Memory.h"
#include <pthread.h>
//#include <sys/types.h>

class ParallelTeam {
private:
	pthread_t * pthreads;

	int* _workList;
	int _workListSize;
	int workSegment;
	pthread_mutex_t mutex;

public:
	Memory *mem;
	int pthreadsSize;
	ParallelTeam(int* workList, int workListSize);
	virtual ~ParallelTeam();
	void childLogicWrapper();

	Memory* createShm(int n);
	void createProcessTeam(int n);
	void childLogic(int i);
	void onChildrenComplete(int n);
};

#endif /* PARALLELTEAM_H_ */
