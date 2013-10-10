/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeamProcessCount3

Data: 10/09/2013

*/
#ifndef PARALLELTEAM_H_
#define PARALLELTEAM_H_

#include <vector>
#include <unistd.h>
#include "Memory.h"
//#include <sys/types.h>

class ParallelTeam {
private:
	std::vector<pid_t> pids;
	int* _workList;
	int _workListSize;
	int workSegment;
	int* shmAddr;
	int shmPos;

public:
	ParallelTeam(int* workList, int workListSize);
	virtual ~ParallelTeam();

	Memory* createShm(int n);
	void createProcessTeam(int n);
	void childLogic(int i, Memory *mem);
	void onChildrenComplete(int n, Memory *mem);
};

#endif /* PARALLELTEAM_H_ */
