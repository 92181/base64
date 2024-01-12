#include <stdio.h>
#include <time.h>
#include "bs64.h"

// compile with: gcc benchmark.c -o benchmark, run with: ./benchmark

int avg(int s[],int l){int t=0,i=l;while(i!=0){i-=1;t+=s[i];};return t/l;};int low(int s[],int l){int t,i=0,p;t=s[0];while(i!=l){i+=1;p=s[i];if(t>p){t=p;};};return t;};

unsigned int i=0,j[9999],*b=j+9999,*o=j;struct timespec j0,j1;

int main()
{
    unsigned char K[27]="Many hands make light work.",L[36];

    do{timespec_get(&j0,1);be(K,L,K+27);timespec_get(&j1,1);*o=j1.tv_nsec-j0.tv_nsec;o+=1;}while(o<b);
    while(i<36){printf("%c",L[i]);i+=1;};printf("\n");printf("Average Latency (ns): %d\n",avg(j,9999));printf("Lowest Latency (ns): %d\n",low(j,9998));


    unsigned char N[36]="TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu",M[27];o=j;

    do{timespec_get(&j0,1);be(N,M,N+27);timespec_get(&j1,1);*o=j1.tv_nsec-j0.tv_nsec;o+=1;}while(o<b);
    while(i<36){printf("%c",M[i]);i+=1;};printf("\n");printf("Average Latency (ns): %d\n",avg(j,9999));printf("Lowest Latency (ns): %d\n",low(j,9998));
};