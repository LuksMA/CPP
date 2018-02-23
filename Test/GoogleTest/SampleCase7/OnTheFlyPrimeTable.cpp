#include "pch.h"
#include "OnTheFlyPrimeTable.h"


OnTheFlyPrimeTable::OnTheFlyPrimeTable()
{
}


OnTheFlyPrimeTable::~OnTheFlyPrimeTable()
{
}

bool OnTheFlyPrimeTable::IsPrime(int n) const {
	if (n <= 1) return false;

	for (int i = 2; i*i <= n; i++) {
		// n is divisible by an integer other than 1 and itself.
		if ((n % i) == 0) return false;
	}

	return true;
}

int OnTheFlyPrimeTable::GetNextPrime(int p) const {
	for (int n = p + 1; n > 0; n++) {
		if (IsPrime(n)) return n;
	}

	return -1;
}