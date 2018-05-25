#include <iostream>
#include <vector>

using namespace std;

void Quicksort(unsigned int* pNumbers, unsigned int totalNumbers)
{
    int backIndex = totalNumbers - 1;

    for (unsigned int i = 0; i < backIndex ; i++)
    {
        if (pNumbers[i] != 0)
        {
            while (backIndex > i)
            {
                if (pNumbers[backIndex] == 0)
                {
                    pNumbers[i]         = 0;
                    pNumbers[backIndex] = 1;
                    break;
                }
                
                backIndex--;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    unsigned int numbers[1024];
    unsigned int numTestcases;
    unsigned int totalNumbers;
    
    cin >> numTestcases;
    
    for (unsigned int i = 0; i < numTestcases; i++)
    {
        cin >> totalNumbers;
        
        for (unsigned int j = 0; j < totalNumbers; j++)
        {
            cin >> numbers[j];
        }
        
        Quicksort(&numbers[0], totalNumbers);
        
        for (unsigned int j = 0; j < totalNumbers; j++)
        {
            cout << numbers[j] << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}

