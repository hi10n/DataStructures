
#include <iostream>
#include "commondefs.h"
#include "quicksort.h"

using namespace std;

// -------------------
// Program entry point
// -------------------
int main(int argc, const char * argv[])
{
    UINT numbers[]        = { 5, 6, 3, 1, 7, 2, 4, 10, 9, 8 };
    // UINT numbers[]        = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // UINT numbers[]        = { 10, 9, 8, 7, 60, 50, 4, 3, 2, 1 };
    // UINT numbers[]        = { 10, 90, 80, 70, 60, 50, 4, 3, 2, 1 };
    // UINT numbers[]        = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    // UINT numbers[]        = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
    // UINT numbers[]        = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };
    // UINT numbers[]        = { 1, 1, 1, 5, 4, 3, 2, 0, 0, 0 };
    // UINT numbers[]        = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
    UINT numbersCount     = (sizeof(numbers) / sizeof(UINT));
    Quicksort* pQuicksort = Quicksort::Create();

    cout << "After Quick sorting\n\n";

    pQuicksort->Sort(&numbers[0], numbersCount);
    PrintNumbers(&numbers[0], numbersCount);
    
    pQuicksort->Destroy();

    return 0;
}

// ----------------------
// Print the number array
// ----------------------
VOID PrintNumbers(UINT* pNumbers,       ///< Number array
                  UINT numbersCount)    ///< Element count in the array
{
    for (UINT i = 0; i < numbersCount; i++)
    {
        cout << pNumbers[i] << "\n";
    }
    
    cout << "\n";
}
