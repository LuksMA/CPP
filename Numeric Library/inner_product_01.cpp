#include <iostream>
#include <functional>
#include <numeric>

int myaccumulator (int x, int y) {return x-y;}
int myproduct (int x, int y) {return x+y;}

int main () {
   int init = 100;
   int series1[] = {20,30,40};
   int series2[] = {1,2,3};

   std::cout << "Default inner_product: ";
   std::cout << std::inner_product(series1,series1+3,series2,0); // 20(20*1) + 60(30*2) + 120(40*3) = 200
   std::cout << '\n';

   std::cout << "Default inner_product 100: ";
   std::cout << std::inner_product(series1,series1+3,series2,init); // 20(20*1) + 60(30*2) + 120(40*3) + 100 = 300
   std::cout << '\n';

   std::cout << "Functional operations: ";
   std::cout << std::inner_product(series1,series1+3,series2,init, //100 - 20(20/1) - 15(30/2) - 13(40/3) = 52;
      std::minus<int>(),std::divides<int>());
   std::cout << '\n';

   std::cout << "Custom functions: ";
   std::cout << std::inner_product(series1,series1+3,series2,init, // 100 - 31(20+1) - 32(30+2) - 43(30+3) = 4;
      myaccumulator,myproduct);
   std::cout << '\n';

   return 0;
}

//Default inner_product: 200
//Default inner_product 100: 300
//Functional operations: 52
//Custom functions: 4
