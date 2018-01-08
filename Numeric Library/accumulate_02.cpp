#include <numeric>    // for accumulate
#include <vector>     // for vector
#include <functional> // for multiplies
#include <iostream>   // for cout


int main ()
{
    // Typedef for convenience.
    typedef std::vector<int, std::allocator<int> > vector;

    // Initialize a vector using an array of integers.
    const vector::value_type arr[] =
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector v1 (arr, arr + sizeof arr / sizeof *arr);

    // Accumulate sums and products.
    vector::value_type sum =
        std::accumulate (v1.begin (), v1.end (), 0);

    vector::value_type prod =
        std::accumulate (v1.begin (), v1.end (), 1,
                         std::multiplies<vector::value_type>());

    // Output the results.
    std::cout << "For the series: ";
    for (vector::iterator i = v1.begin (); i != v1.end (); ++i)
        std::cout << *i << " ";

    std::cout << "where N = " << v1.size ()
              << "\nThe sum = (N * N + N) / 2 = " << sum
              << "\nThe product = N! = " << prod << std::endl;

    return 0;
}


//For the series: 1 2 3 4 5 6 7 8 9 10 where N = 10
//The sum = (N * N + N) / 2 = 55
//The product = N! = 3628800
