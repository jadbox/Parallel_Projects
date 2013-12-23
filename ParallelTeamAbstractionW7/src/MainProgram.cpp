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

// This is the entry function used for
// ProcessTeam, SerialTeam, ThreadTeam, MPITeam
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
	delete entry;
}
// This is the entry function designated for the CUDA team
void entryFuncCUDA(void* entryProxy) {
	ProcessParams* entry = (ProcessParams*) entryProxy;
	BaseTeam* member = entry->obj;

	int result = run_kernel(entry->data, entry->length);
	member->lockSemaphoreInSet(0);
	member->result += result;
	member->unlockSemaphoreInSet(0);
	delete entry;
}

// Used for the OpenCL implementation
void entryFuncOpenCL(void* entryProxy) {
	ProcessParams* entry = (ProcessParams*) entryProxy;
	BaseTeam* member = entry->obj;

	//UNCOMMENT once linking CLKernal.cl into project: hack to not conflict
	//count3CUDA(entry->data, entry->length);
	delete entry;
}

// Starting point for our application
int main(int argc, char *argv[]) {
	cout << "The program is starting up!" << endl;

	// Initialize MPI which is needed for MPITeam
	MPI_Init(&argc, &argv);

	// Source array for data to count the 3s into
	int data[] = {1, 5, 3, 8, 3, 3, 35, 237, 95, 326, 623, 532, 3, 4543, 3};
	int size = 15;

	int teams = 0; // initialized value, set belo
    //==========Create Teams==============
	BaseTeam **teamSet;
	teamSet = (BaseTeam **) calloc(teams,sizeof(BaseTeam *));
	teamSet[teams++] = new SerialTeam(data, size);
	teamSet[teams++] = new ThreadTeam(data, size);
	teamSet[teams++] = new ProcessTeam(data, size);
	teamSet[teams++] = new MPITeam(data, size);
	teamSet[teams++] = new OpenCLTeam(data, size); // second to last is OpenGL
	teamSet[teams++] = new CUDATeam(data, size); // last team is CUDA

	// Set the number of members to use per team
	int teamMembers = 3;
	// Create all the team members
	for(int i = 0; i < teams; i++) {
		teamSet[i]->createTeam(teamMembers);
	}

	// set the entry function for all teams except special GPU teams
	for(int i = 0; i < teams-2; i++) {
		teamSet[i]->setEntryFunction(&entryFuncALU);
	}
	// set the OpenCL start function
	teamSet[teams-2]->setEntryFunction(&entryFuncOpenCL);
	// set the CUDA start function
	teamSet[teams-1]->setEntryFunction(&entryFuncCUDA);

	// start all the team members
	for(int i = 0; i < teams; i++) {
		teamSet[i]->startAllTeamMembers();
	}
	// wait for all team members to complete
	for(int i = 0; i < teams; i++) {
		teamSet[i]->waitForAllTeamMembers();
	}

	// Cleanup and display results
	// The timed results are sent to the output from within the team
	cout << "All teams have finished" << endl;
	for (int i=0; i < teams; i++) {
		cout << "TeamSet" << i << endl;
		cout << "Team Result: " << teamSet[i]->result << endl;
		cout << "Status: " << teamSet[i]->termStatus << endl;
		cout << "============" << endl;
	}

	// ANNNNDDDD... we're done!
	return 0;
}
