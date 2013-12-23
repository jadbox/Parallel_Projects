/*

Name: Jonathan Dunlap & Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Final

Data: 12/22/2013

*/
#include <iostream>
#include "ThreadTeam.h"
#include "ProcessTeam.h"
#include "CUDATeam.h"
#include "OpenCLTeam.h"
#include "SerialTeam.h"
#include "MPITeam.h"
#include <malloc/malloc.h>
#include "mpi.h"
using namespace std;


void entryFuncALU(void* entryProxy) {
	ProcessParams* entry = (ProcessParams*) entryProxy;

	BaseTeam* member = entry->obj;
	int* data = entry->data;

	int result = 0;
	for(int i = 0; i < entry->length; i++) {
		if(data[i] == 3) ++result;
	}

	member->lockSemaphoreInSet(0);
	member->result += result;
	member->unlockSemaphoreInSet(0);
}

void entryFuncGPU(void* entryProxy) {
	ProcessParams* entry = (ProcessParams*) entryProxy;
	//int index = (int) entry;
	BaseTeam* member = entry->obj;


	//if(data[index] == 3)
}

int main(int argc, char *argv[]) {
	cout << "Teams starting up" << endl; // prints
	MPI_Init(&argc, &argv);


	int data[] = {1, 5, 3, 8, 3, 3};
	int size = 6;

	int teams = 0;
	int teamMembers = 3;
    //========================
	BaseTeam **teamSet;
	teamSet = (BaseTeam **) calloc(teams,sizeof(BaseTeam *));
	teamSet[teams++] = new SerialTeam(data, size);
/*
	teamSet[teams++] = new OpenCLTeam();
	teamSet[teams++] = new ThreadTeam();
	teamSet[teams++] = new ProcessTeam();
	teamSet[teams++] = new MPITeam();
	teamSet[teams++] = new CUDATeam();
*/


	for(int i = 0; i < teams; i++) {
		teamSet[i]->createTeam(teamMembers);
		teamSet[i]->setEntryFunction(&entryFuncALU);
	}
	for(int i = 0; i < teams; i++) {
		teamSet[i]->startAllTeamMembers();
	}
	for(int i = 0; i < teams; i++) {
		teamSet[i]->waitForAllTeamMembers();
	}

	cout << "All teams have finished" << endl;
	for (int i=0; i < teams; i++) {
		cout << "TeamSet" << i << endl;
		cout << "Team Result: " << teamSet[i]->result << endl;
		cout << "Status: " << teamSet[i]->termStatus << endl;
		cout << "============" << endl;
	}

	return 0;
}
