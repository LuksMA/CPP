#include <iostream>
#include <functional>
#include <numeric>

int myop (int x, int y) {return x+y+1;}

int main () {
   int val[] = {10,20,30,40,50};
   int result[5];

   std::partial_sum (val, val+5, result);
   std::cout << "Default partial_sum: ";
   for (int i=0; i<5; i++) std::cout << result[i] << ' '; // 10, 30(10+20), 60(10+20+30), 100(10+20+30+40), 150(10+20+30+40+50);
   std::cout << '\n';

   std::partial_sum (val, val+5, result, std::multiplies<int>());
   std::cout << "Functional operation multiplies: ";
   for (int i=0; i<5; i++) std::cout << result[i] << ' '; // 10, 20(10*20), 6000(10*20*30), 240000(10*20*30*40), 12000000(10*20*30*40*50);
   std::cout << '\n';

   std::partial_sum (val, val+5, result, myop);
   std::cout << "Custom function: ";
   for (int i=0; i<5; i++) std::cout << result[i] << ' ';  // 10, 31(10+20+1), 62(10+20+1+30+1), 103(10+20+1+30+1+40+1), 154(10+20+1+30+1+40+1+50+1);
   std::cout << '\n';
   return 0;
}

//Default partial_sum: 10 30 60 100 150
//Functional operation multiplies: 10 200 6000 240000 12000000
//Custom function: 10 31 62 103 154
