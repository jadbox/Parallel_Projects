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

using namespace std;

ParallelTeam::ParallelTeam():pids() {
	// TODO Auto-generated constructor stub
	cout << "ParallelTeam started";
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
			cout << "error spawning process";
			exit(1);
		}
		else if(t==0) {
			int x = 1 + rand() % 7;
			sleep(x*1000);
			cout << "Process ended";
			exit(0);
		}
		else if(t > 0) {
			pids.push_back(t);
		}
	}

	if(t > 0) {
		cout << "Parent: process ended";
		exit(0);
	}
}

