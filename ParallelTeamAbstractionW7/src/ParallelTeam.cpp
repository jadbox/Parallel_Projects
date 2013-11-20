/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Refactor ParallelTeam

Data: 11/19/2013

*/
#include <iostream>
#include "ThreadTeam.h"
#include "ProcessTeam.h"
#include "CUDATeam.h"
#include "MPITeam.h"
#include <malloc.h>
#include "mpi.h"
using namespace std;


void startFunc(void* x) {

}

int main(int argc, char *argv[]) {
	cout << "Teams starting up" << endl; // prints
	MPI_Init(&argc, &argv);

	int teams = 4;
	int teamMembers = 3;
    //========================
	BaseTeam **teamSet;
	teamSet = (BaseTeam **) calloc(teams,sizeof(BaseTeam *));
	teamSet[0] = new ThreadTeam();
	teamSet[1] = new ProcessTeam();
	teamSet[2] = new MPITeam();
	teamSet[3] = new CUDATeam();

	for(int i = 0; i < teams; i++) {
		teamSet[i]->createTeam(teamMembers);
		teamSet[i]->setEntryFunction(startFunc);
	}
	for(int i = 0; i < teams; i++) {
		teamSet[i]->startAllTeamMembers();
	}
	for(int i = 0; i < teams; i++) {
		teamSet[i]->waitForAllTeamMembers();
	}

	cout << "All teams have finished" << endl;
	for (int i=0; i < teams; i++) {
		cout << "TeamSet"<< i << ": " << teamSet[i]->termStatus << endl;
	}

	return 0;
}
