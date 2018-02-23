#include "pch.h"
#include "PreCalculatedPrimeTable.h"

bool PreCalculatedPrimeTable::IsPrime(int n) const {
	return 0 <= n && n < is_prime_size_ && is_prime_[n];
}

int PreCalculatedPrimeTable::GetNextPrime(int p) const {
	for (int n = p + 1; n < is_prime_size_; n++) {
		if (is_prime_[n]) return n;
	}

	return -1;
}

void PreCalculatedPrimeTable::CalculatePrimesUpTo(int max) {
	::std::fill(is_prime_, is_prime_ + is_prime_size_, true);
	is_prime_[0] = is_prime_[1] = false;

	// Checks every candidate for prime number (we know that 2 is the only even
	// prime).
	for (int i = 2; i*i <= max; i += i % 2 + 1) {
		if (!is_prime_[i]) continue;

		// Marks all multiples of i (except i itself) as non-prime.
		// We are starting here from i-th multiplier, because all smaller
		// complex numbers were already marked.
		for (int j = i * i; j <= max; j += i) {
			is_prime_[j] = false;
		}
	}
}