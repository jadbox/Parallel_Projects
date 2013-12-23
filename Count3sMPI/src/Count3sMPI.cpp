
////////////////////////////////////////////////////////

#include "Count3sMPI.h"
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    lengthProc = size/numProcs;

    if (rank == RootProcess) {
        for (int p=0; p < numProcs-1; p++) {
            MPI_Send(a, lengthProc, MPI_INT, p+1, tag, MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(a, lengthProc, MPI_INT, RootProcess, tag, MPI_COMM_WORLD, &status);
    }

    //generates local count
    for (int i=0; i < lengthProc; i++) {
        if (a[i] == 3)
            localCount++;
        cout << localCount << endl;
    }

    //reduce count
    MPI_Reduce(&localCount, &globalCount, 1, MPI_INT, MPI_SUM, RootProcess, MPI_COMM_WORLD);

    //prints total count
    if (rank == RootProcess)
        cout << "Number of 3's : " << globalCount << endl;

    //terminates program
    MPI_Finalize();
    return 0;
}
