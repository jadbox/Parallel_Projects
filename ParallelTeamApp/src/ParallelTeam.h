/*
 * ParallelTeam.h
 *
 *  Created on: Sep 12, 2013
 *      Author: dunlap
 */

#ifndef PARALLELTEAM_H_
#define PARALLELTEAM_H_

#include <vector>

class ParallelTeam {
private:
	std::vector<std::pid_t> pids;
public:
	ParallelTeam();
	virtual ~ParallelTeam();

	void createProcessTeam(int n);

};

#endif /* PARALLELTEAM_H_ */
