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

void child(int i, Memory* mem) {
	//shmdt()
	cout << "child " << i;
}

int main() {
	cout << "Starting up!" << endl;

	int n = 5;// number of threads
	int shm = shmget(IPC_PRIVATE, n*sizeof(int), IPC_CREAT);
	int* ptr = (int*) shmat(shm, NULL, 0);
	cout << "mem alloc" << endl;
	Memory* mem = new Memory(ptr, n);
	cout << "ParallelTeam" << endl;
	ParallelTeam pt;
	pt.createProcessTeam(5, &child, mem);

	////delete mem; // delay parent thread // should be
	//shmdt(ptr);
	//shmctl(shm, IPC_RMID, 0);

	return 0;
}
