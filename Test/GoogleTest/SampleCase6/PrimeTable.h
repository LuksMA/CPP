#pragma once
class PrimeTable
{
public:
	PrimeTable();
	virtual ~PrimeTable();
	virtual bool IsPrime(int n) const = 0;   // Returns true iff n is a prime number.
	virtual int GetNextPrime(int p) const = 0; 
};

