/*
 * CTAMemory.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: dunlap
 */

#include "CTAMemory.h"

CTAMemory::CTAMemory() {
	mem = new Memory();
	for(int i=0; i < cache_length; i+=1) addr[i] = 0;
	cache_spot = 0;
}
CTAMemory::CTAMemory(Memory* memory):mem(memory) {
	for(int i=0; i < cache_length; i+=1) addr[i] = 0;
	cache_spot = 0;
}

void CTAMemory::write(unsigned int address, registertype value) {
	registertype* spot = 0;
	for(int i=0; i < cache_length; i+=2) {
		unsigned int cv = addr[i];
		if(address == cv || cv == 0) {
			spot = cache+i;
			break;
		}
	}
//	/spot = value;
}

registertype CTAMemory::read(unsigned int address) {
	for(int i=0; i < cache_length; i+=2) {
		unsigned int cv = addr[i];
		if(address == cv) {
			return cache[i];
		}
		else if(address==0) {
			cache_spot = i;
			break;
		}
	}

	registertype a = mem->read(address);
	addr[cache_spot % cache_length] = a;
	cache_spot++;
	return a;
}
