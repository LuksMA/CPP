#pragma once
#include "PrimeTable.h"
class OnTheFlyPrimeTable : public PrimeTable
{
public:
	OnTheFlyPrimeTable();
	~OnTheFlyPrimeTable();
	virtual bool IsPrime(int n) const;
	virtual int GetNextPrime(int p) const;
};

