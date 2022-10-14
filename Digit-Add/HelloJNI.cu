#include <jni.h>        
#include <stdio.h>      
#include <math.h>
#include <stdlib.h>
#include "HelloJNI.h"
 

__global__ void add(jint *x, jint*y, jint *r, jint sz) 
{
	int i=threadIdx.x+blockIdx.x*blockDim.x;
	if(i<sz)
	{
   	jint z=((int)(*x/pow(10,i))%10)+((int)(*y/pow(10,i))%10);
	r[i]=z;	
	}  
}

void show(jint* r, jint sz)
{
	for(int i=sz-1;i>=0;i--)
	{
		printf("%d ",r[i]);
	}
}

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj, jint a, jint b) {
	jint sz=(int)log10(max(a,b))+1;
	jint* r;
	cudaMallocManaged(&r,sz*sizeof(jint));
	jint *a1;
	jint *b1;
	cudaMallocManaged(&a1,sizeof(jint));
	cudaMallocManaged(&b1,sizeof(jint));
	cudaMemcpy(a1,&a,sizeof(jint),cudaMemcpyHostToDevice);
	cudaMemcpy(b1,&b,sizeof(jint),cudaMemcpyHostToDevice);
	add<<<1,sz>>> (a1,b1,r,sz);
	cudaDeviceSynchronize();
	show(r,sz);
}