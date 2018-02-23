#pragma once
#include "PrimeTable.h"
class PreCalculatedPrimeTable : public PrimeTable
{
public:
	explicit PreCalculatedPrimeTable(int max)
		: is_prime_size_(max + 1), is_prime_(new bool[max + 1]) {
		CalculatePrimesUpTo(max);
	}
	virtual ~PreCalculatedPrimeTable() { delete[] is_prime_; }

	virtual bool IsPrime(int n) const;
	virtual int GetNextPrime(int p) const;

private:
	void CalculatePrimesUpTo(int max);
	const int is_prime_size_;
	bool* const is_prime_;
	void operator=(const PreCalculatedPrimeTable& rhs);
};

