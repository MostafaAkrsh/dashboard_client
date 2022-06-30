#include "cudacode.cuh"

__global__ void test_kernel(void) {
	printf("Hello, world!");

}

	QString wrapper()
	{
		test_kernel << <1, 1 >> > ();
		return "Cuda GPU is working";
	}
