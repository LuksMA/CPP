#include<iostream>

using namespace std;
int main(){
    /// [](input_paramter_declaration)->returned_type {body_of_the_lambda_expression}(parameters)
    // Eg_01:
    int result01 = []() -> int { return 4; }();
    cout << result01 << endl;

    // Eg_02:
    int result02 = [](int input) -> int { return 2 * input; }(10);
    cout << result02 << endl;

    // Eg_03:
    int result03 = [](int a,int b) -> int { return a + b; }(2,4);
    cout << result03 << endl;

    // Eg_04: combine 01 and 03
    int result04 = [](int m, int n) -> int { return m + n; } ([](int a) -> int { return a; }(2),[](int a) -> int { return a; }(3));
    cout << result04 << endl;

    /// use more than once a lambda expression it, use a pointer to the lambda expression
    // Eg_05
    auto func = [](int a, int b) -> int { return a+b; };
    cout << func(2, 3) << endl;




}
