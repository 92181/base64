#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "b64.h"

static void benchmark(),intermediate();

int main()
{
	// Encodes & Decodes String;
	unsigned char k[27]="Many hands make light work.",l[36],m[27];
	
	b64_encode(k,l,k+27);write(1,l,36);

	write(1,"\n",1);
	
	b64_decode(l,m,l+36);write(1,m,27);
	
	write(1,"\n",1);

	// Encodes (Padding);
	unsigned char z[4]="Ma",u[4];
	
	b64_encode(z,u,z+2);write(1,u,4);write(1,"\n",1);

	// Encode & Decode Intermediate;
	intermediate();

	// Start Benchmark;
	benchmark();
	
	return 0;
};

// Intermediate Demo;
static void intermediate()
{
	// Encode & Decode Intermediate (6-Bit Decimals);
	unsigned char k[]="Man",l=sizeof(k)-1,z=ceil((float)l/3),a[z*4],m[z*3];

	b64i_encode(k,a,k+l);printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);

	b64i_decode(a,m,a+z*4);write(1,m,l);write(1,"\n",1);
};

// Benchmark;
static void benchmark()
{
	struct timespec s,e;clock_gettime(1,&s);

	unsigned int n=0,c=0;unsigned char m[27],l[36]="TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu";

	while(n<10000000)
	{
		b64_decode(l,m,l+36);c=c*m[2]+1;

		n+=1;
	};

	clock_gettime(1,&e);

	// Print Time;
	long x=e.tv_sec-s.tv_sec,z=e.tv_nsec-s.tv_nsec;

	if(z<0) 
	{
		x-=1;z+=1000000000;
	};

	printf("Time: %lu.%09ld (S), Checksum: %d\n",x,z,c);
};