/*
 * CTAMemory.h
 *
 *  Created on: Sep 8, 2013
 *      Author: dunlap
 */

#ifndef CTAMEMORY_H_
#define CTAMEMORY_H_

#include "Memory.h"

class CTAMemory {
public:
	static const int CACHE_BYTES = 64;
	CTAMemory();
	CTAMemory(Memory* mem);

	void write(unsigned int address, registertype value);
	registertype read(unsigned int address);

private:
	Memory* mem;
	registertype cache[ CACHE_BYTES / sizeof(registertype) / 2]; // [0] = mem addr, [1] = cached value
	unsigned int addr[ CACHE_BYTES / sizeof(registertype) / 2];

	int cache_length = CACHE_BYTES / sizeof(registertype) / 2;
	int cache_spot;
};

#endif /* CTAMEMORY_H_ */
