/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeam

Data: 9/19/2013

*/


#include "ParallelTeam.h"
#include <iostream>
#include <string>
#include <stdlib.h>   // Declaration for exit() and rand()
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
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
	time_t start_time = time(NULL);

	pid_t t;
	for(int i = 0; i < n; i++) {
		t = fork();
		if(t < 0) {
			cout << "error spawning process" << endl;
			_exit(1);
		}
		else if(t==0) { // CHILD PROCESS
			struct tm *tm;
			time_t now = time(0);
			tm = localtime (&now);

			srand(i * time(NULL)); // pick a random number in a system range
			int x = 1 + rand() % 7; // random number constraint
			sleep(x); // child process sleep for x seconds
			cout << "Child says: my process is ending. PPID:" << getppid() << ", PID:" << getpid() << ", sleep time:" << x << ", ";
			printf ("Launched %04d-%02d-%02d %02d:%02d:%02d\n",
			        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
			        tm->tm_hour, tm->tm_min, tm->tm_sec);
			_exit(0); // exit the child process
		}
		else if(t > 0) {

			pids.push_back(t);
		}
	}

	if(t > 0) { // PARENT PROCESS
		int status;
		for(int i = 0; i < n; i++) {
			pid_t wid = waitpid(-1, &status, 0); // waitpid(-1...) signifies to wait until any child process ends
			cout << "Parent says: my child process #" << wid << " ended. Second Duration: " << (time(NULL) - start_time) << endl;
		}
	}
}

