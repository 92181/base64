# Base64 Encoding & Decoding Library
I decided to write this Base64 encoding & decoding library to see how far I could take optimization of the internal algoritms and routines. It is also fairly compact but the priority lies with it's performance. This library is atleast in the top in terms of absolute performance. The library is single-threaded and written in C, it ofcourse has no dependencies.

# Usage
The library can be used, in a variety of cases, think about websocket handshakes, encoding and decoding links or images, strings of data and so on.
It can be easily included with #include "bs64.h". Examples can be found in example.c and the main logic can be found in bs64. This library only supports Little-Endian processors, however it can easily be modified to support Big-Endian.

```c
// The library can used as seen here, for more examples check example.c
unsigned char K[27]="Many hands make light work.",L[36];

be(K,L,K+27);while(i<36){printf("%c",L[i]);i+=1;};printf("\n");
```
