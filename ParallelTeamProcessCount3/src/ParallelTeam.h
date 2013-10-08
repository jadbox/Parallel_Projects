/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeam

Data: 9/19/2013

*/
#ifndef PARALLELTEAM_H_
#define PARALLELTEAM_H_

#include <vector>
#include <unistd.h>
//#include <sys/types.h>

class ParallelTeam {
private:
	std::vector<pid_t> pids;
public:
	ParallelTeam();
	virtual ~ParallelTeam();

	void createProcessTeam(int n);

};

#endif /* PARALLELTEAM_H_ */
