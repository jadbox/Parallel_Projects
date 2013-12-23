#include <OpenCL/opencl.h>

// Header to make Clang compatible with OpenCL
#define __global __attribute__((address_space(1)))
// Defintion to match OpenCL kernal function
int get_global_id(int index);

// Kernal that implements count 3
__kernal void count3sCUDA(	__global const int arr*,
		__global const int length,
		__global int count) {
		int id = get_global_id(0);
		if( id < N ) {
        	if( a[id] == 3 )
				count++
		}
}

extern "C"
void count3CUDA(int arr*, int length) {
	cl.platform_id platform;
	clGetPlatformIDs ( 1 , &platform , NULL );
	//Find the gpu device
	cl.device_id device;
	clGetDeviceIDs ( platform , CL_DEVICE_TYPE_GPU,
			1,
			&device,
			NULL);
	// Create a context and command queue on that device.
	cl.context context = clCreateContext ( NULL,
			1 ,
			&device ,
			NULL, NULL, NULL);
	c1.command_queue queue = clCreateCommandQueue( context ,
			device,
			0 , NULL );
	// Perform runtime source compilation , and obtain kernel entry point .
	cl.program program = clCreateProgramWithSource ( context ,
			1 ,
			&source ,
			NULL, NULL );
	clBuildProgram ( program , 1 , &device , NULL, NULL, NULL );
	cl.kernel kernel = clCreateKernel ( program , "memset" , NULL );
	// Create a data buffer .
	cl.mem buffer = clCreateBuffer ( context ,
			CL_MEM_WRITE_ONLY,
			length *sizeof( cl_uint ) , NULL, NULL );
	// Launch the kernel . Let OpenCL pick the l o c a l work size .
	size_t global_work_size = length;
	clSetKernelArg ( kernel , 0 ,
			sizeof
			( buffer ) , (void) &buffer );
	clEnqueueNDRangeKernel( queue ,
			kernel ,
			1 ,
			// dimensions
			NULL,
			// i n i t i a l o f f s e t s
			&global_work_size ,
			// number of work items
			NULL,
			// work items per work group
			0 , NULL, NULL);
	// events
	clFinish ( queue );
	// 7. Look at the r e s u l t s via synchronous buffer map.
	cl_uint *ptr;
	ptr = ( cl_uint *) clEnqueueMapBuffer ( queue ,
			buffer ,
			CL_TRUE,
			CL_MAP
			READ,
			0 ,
			length
			
			sizeof
			( cl_uint ) ,
			0 , NULL, NULL, NULL );
	inti ;
	for( i =0; i<length; i++)
		printf ("%d_%d\n" , i , ptr [ i ] )
}