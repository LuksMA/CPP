#include <iostream>
#include <vector>
#include "IComparator.h"
#include "LesserComprataor.h"
#include "GreaterComprataor.h"
#include "SortingAlgo.h"

using namespace std;

int main()
{
    vector<int> arr = {1,5,2,4,3};
    SortingAlgo obj;

	IComparator * pComp = new LesserComprataor();
	obj.sort(arr, pComp);
	for (int var = 0; var < 5; ++var) {
		std::cout<<arr[var]<<" ";
	}
	std::cout<<std::endl;
	delete pComp;
	pComp = nullptr;

	pComp = new GreaterComprataor();
	obj.sort(arr, pComp);
	for (int var = 0; var < 5; ++var) {
		std::cout<<arr[var]<<" ";
	}
	std::cout<<std::endl;
	delete pComp;
	pComp = nullptr;
}
