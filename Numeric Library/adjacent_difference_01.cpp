#include <iostream>
#include <functional>
#include <numeric>

int myop (int x, int y) {return x+y;}

int main () {
   int val[] = {10,20,30,50,60,70};
   int result[6];

   std::adjacent_difference (val, val+6, result);
   std::cout << "Default adjacent_difference: ";
   for (int i=0; i<6; i++) std::cout << result[i] << ' '; // 10, 10(20-10), 10(30-20), 20(50-30), 10(60-50),10(70-60)
   std::cout << '\n';

   std::adjacent_difference (val, val+6, result, std::multiplies<int>());
   std::cout << "Functional operation multiplies: ";
   for (int i=0; i<6; i++) std::cout << result[i] << ' '; //10, 200(10*20),500(30*20), 1500(50*30), 3000(60*50),4200(70-60)
   std::cout << '\n';

   std::adjacent_difference (val, val+6, result, myop);
   std::cout << "Custom function operation: ";
   for (int i=0; i<6; i++) std::cout << result[i] << ' '; //10, 30(20+10), 50(30+20), 80(50+30), 110(60+50),130(70+60)
   std::cout << '\n';
   return 0;
}


//Default adjacent_difference: 10 10 10 20 10 10
//Functional operation multiplies: 10 200 600 1500 3000 4200
//Custom function operation: 10 30 50 80 110 130
