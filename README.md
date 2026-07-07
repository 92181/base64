# Base64 Encoding & Decoding Library
I decided to write this Base64 encoding & decoding library to get to know more about bitwise operators and CPU endianness. I gradually improved it over time.

It is fairly compact but the priority lies with it's performance. This library is at the top in terms of performance, however this scalar approach has its limits and you will find better performance in a SIMD optimized library. It has no external dependencies.

Use cases:
* Websocket handshake
* Image/torrent links
* Compression (intermediate functions, to 6-bit decimals)
* A lot more

Additionally I added intermediate functions to convert ASCII to true 6-bit values (decimals), instead of immediatly converting to the Base64 alphabeth.
This is very useful for some light compression, albeit it can not be displayed as text.

## Usage
It can be easily included, various examples can be found in example.c file. 
Most functions are only suited for little-endian, however it could be modified to support big-endian.

```c
unsigned char K[27]="Many hands make light work.",L[36];

b64_encode(K,L,K+27);write(1,l,36);write(1,"\n",1);
```

Compile with:

```sh
gcc example.c -march=native -O2 -o example
```

## License

Public Domain.