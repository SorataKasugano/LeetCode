#pragma once
/*
190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it? */

typedef unsigned int uint32_t;

uint32_t reverseBits(uint32_t n) {
	// 1.
	uint32_t ret = 0;
	for (int i = 31;i >= 0;i--, n >>= 1) ret |= (n & 1) << i;
	return ret;
	// 2.
	//uint32_t ret = 0;
	//for (int i = 0;i < 32;i++, n >>= 1)
	//{
	//	ret << 1;
	//	ret |= n & 1;
	//}
	//return ret;
}