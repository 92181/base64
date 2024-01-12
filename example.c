#include <stdio.h>
#include "bs64.h"

// compile with: gcc example.c -o example, run with: ./example

unsigned int i=0;

int main()
{
    // Encodes string (K) and outputs (L) results.
    unsigned char K[27]="Many hands make light work.",L[36];be(K,L,K+27);while(i<36){printf("%c",L[i]);i+=1;};printf("\n");
    
    // Decodes string (N) and outputs (M) results.
    unsigned char N[36]="TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu",M[27];bd(N,M,N+36);i=0;while(i<27){printf("%c",M[i]);i+=1;};printf("\n");

    // Encodes string (Z) and outputs (U) results with padding. Make the array's have the right size (Z and U).
    unsigned char Z[64]="Ma",U[4];bs(Z,U,Z+2);i=0;while(i<4){printf("%c",U[i]);i+=1;};printf("\n");
}