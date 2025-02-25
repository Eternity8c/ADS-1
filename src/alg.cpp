// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	if (value < 2)
		return false;
	for (uint64_t i = 2; i <= sqrt(value); i++) {
		if (value % i == 0) {
			return false;
		}
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	uint64_t col = 0;
	uint64_t candidat = 1;

	while (col < n) {
		candidat++;
		if (checkPrime(candidat)) {
			col++;
		}
	}
	return candidat;
}

uint64_t nextPrime(uint64_t value) {
	uint64_t candidat = value;

	for (uint64_t i = 0; ; i++) {
		candidat++;
		if (checkPrime(candidat)) {
			return candidat;
			break;
		}
	}
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t sum = 0;
	uint64_t candidat = 1;

	while (candidat < hbound) {
		candidat++;
		if (hbound != candidat) {
			if (checkPrime(candidat)) {
				sum += candidat;
			}
		}
	}
	return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	uint64_t col = 0;
	uint64_t candidat = lbound;

	while (candidat < hbound-2) {
		if (checkPrime(candidat) && checkPrime(candidat+2)) {
			col++;
		}
		candidat++;
	}
	return col;
}
