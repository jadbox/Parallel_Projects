/*
 * ParallelTeam.cpp
 *
 *  Created on: Sep 12, 2013
 *      Author: dunlap
 */


#include "ParallelTeam.h"
#include <iostream>
#include <string>
#include <stdlib.h>   // Declaration for exit() and rand()
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

using namespace std;

ParallelTeam::ParallelTeam():pids() {
	// TODO Auto-generated constructor stub
	cout << "ParallelTeam started" << endl;
}

ParallelTeam::~ParallelTeam() {
	// TODO Auto-generated destructor stub
}

void ParallelTeam::createProcessTeam(int n) {
	// create process
	pid_t t;
	for(int i = 0; i < n; i++) {
		t = fork();
		if(t < 0) {
			cout << "error spawning process" << endl;
			_exit(1);
		}
		else if(t==0) {
			srand(i * time(NULL));
			int x = 1 + rand() % 7;
			sleep(x);
			cout << "Process ended " << x << endl;
			_exit(0);
		}
		else if(t > 0) {

			pids.push_back(t);
		}
	}
	if(t > 0) {
		int status;
		for(int i = 0; i < n; i++) {
			//pid_t wid =
					waitpid(-1, &status, 0);
			cout << "Parent: process ended" << endl;
		}
	}
}

