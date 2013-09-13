/*
 * ParallelTeam.cpp
 *
 *  Created on: Sep 12, 2013
 *      Author: dunlap
 */
#include <iostream>
#include <string>

#include "ParallelTeam.h"
#include <unistd.h>
#include <sys/types.h>'
#include <stdlib.h>   // Declaration for exit()

using namespace std;

ParallelTeam::ParallelTeam():pids() {
	// TODO Auto-generated constructor stub

}

ParallelTeam::~ParallelTeam() {
	// TODO Auto-generated destructor stub
}

void ParallelTeam::createProcessTeam(int n) {
	// create process
	for(int i = 0; i < n; i++) {
		pid_t t = fork();
		if(t < 0) {
			exit(1);
		}
	}
}

