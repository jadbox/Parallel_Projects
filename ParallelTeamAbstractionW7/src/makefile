MPICC = mpic++ -cxx=clang
CUDA = /usr/local/cuda
NVCC = $(CUDA)/bin/nvcc -ccbin /usr/bin/clang -m64

all: pt

pt: kernal.o
		$(MPICC) -m64 -o count3Teams -L$(CUDA)/lib kernal.o -MD MainProgram.cpp -lcudart -lcuda 

kernal.o:
	$(NVCC) -arch=sm_20 -c kernal.cu -o kernal.o

clean:
	rm -rf *o count3Teams
