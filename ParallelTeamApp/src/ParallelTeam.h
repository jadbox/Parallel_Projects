/*
 * ParallelTeam.h
 *
 *  Created on: Sep 12, 2013
 *      Author: dunlap
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
