/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeam

Data: 10/06/2013

*/

#include <iostream>
#include "ParallelTeam.h"

#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;

int main() {
	cout << "Starting up!" << endl;

	unsigned int n = 5;// number of threads
	int shm = shmget(IPC_PRIVATE, n*sizeof(int), IPC_CREAT | SHM_R | SHM_W);
	int* ptr = (int*) shmat(shm, NULL, 0);
	cout << "mem alloc" << endl;
	Memory mem(ptr, n);
	cout << "ParallelTeam" << endl;

	int workData[] = {18, 41, 3, 914, 3, 3, 3, 3, 14, 3, 151, 3};
	int procsToSpawn = 3; // must be even divisible for the workData
	ParallelTeam pt(workData, 12);
	pt.createProcessTeam(procsToSpawn, &mem);

	//delete workData;
	//delete mem; // delay parent thread // should be
	shmdt(ptr);
	shmctl(shm, IPC_RMID, 0);

	return 0;
}
