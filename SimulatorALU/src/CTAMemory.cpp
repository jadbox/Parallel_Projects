/*
 * CTAMemory.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: dunlap
 */

#include "CTAMemory.h"
#include <iostream>

CTAMemory::~CTAMemory() {
	delete mem;
}

void CTAMemory::fillCache(unsigned int cache_index) {
	mem_cache_index = cache_index;
	int offset = 0;
	if(cache_index+cache_length > mem->MEM_SIZE) offset = (cache_index+cache_length) - mem->MEM_SIZE;

	for(int i=0; i < cache_length-offset; i++)
		cache[i] = mem->read(i+mem_cache_index);

	//std::cout << "cache flush" << std::endl;
}

CTAMemory::CTAMemory() {
	mem = new Memory();
	fillCache(0);
}

CTAMemory::CTAMemory(Memory* memory):mem(memory) {
	fillCache(0);
}

void CTAMemory::write(unsigned int address, registertype value) {
	if(address < mem_cache_index || address > mem_cache_index+cache_length)
		fillCache(address);
	//else std::cout << "in cache" << std::endl;
	cache[address-mem_cache_index]=value;
}

registertype CTAMemory::read(unsigned int address) {
	if(address < mem_cache_index || address > mem_cache_index+cache_length)
		fillCache(address);
	//else std::cout << "in cache" << std::endl;
	return cache[address-mem_cache_index];
}
