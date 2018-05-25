#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// -----------------------------------------------------------------------
// Process the stock price array and figure out the way to maximize profit
// -----------------------------------------------------------------------
void ProcessStockPrices(unsigned int* pStockPricePerDay,
                        unsigned int numDays)
{
    unsigned int buyIndex      = 0;
    unsigned int traverseIndex = 0;
    bool         isProfit      = false;
    
    while (traverseIndex < numDays)
    {
        if ((traverseIndex + 1) < numDays)
        {
            // Figure out the first dip in the stock price from the array
            if (pStockPricePerDay[traverseIndex + 1] < pStockPricePerDay[traverseIndex])
            {
                // If the buyIndex and dipIndex are not adjacent it means we have valid (buy sell) indices
                if (buyIndex != traverseIndex)
                {
                    printf ("(%d %d) ", buyIndex, traverseIndex);
                    buyIndex = traverseIndex + 1;
                    isProfit = true;
                }
                else // if buyIndex and dipIndex are adjacent we simply treat the dipped value as the next buy index
                {
                    buyIndex = traverseIndex + 1;
                }
            }
            else // No Dip
            {
                if (pStockPricePerDay[buyIndex] > pStockPricePerDay[traverseIndex])
                {
                    buyIndex = traverseIndex;
                }
            }
        }
        
        traverseIndex++;
    }
    
    if (pStockPricePerDay[numDays - 1] > pStockPricePerDay[buyIndex])
    {
        printf ("(%d %d) ", buyIndex, numDays - 1);
        isProfit = true;
    }
    
    if (isProfit == false)
    {
        printf("No Profit");
    }
    
    printf("\n");
}

int main(void)
{
    unsigned int  numTestCases;
    unsigned int  numDays;
    // Test for:
    // { 100, 180, 260, 310, 40, 535, 895 }
    // { 100, 90,  80,  70,  60, 50,  40  }
    // { 10,  10,  10 }
    // { 1,   2,   3,   4,  1,  2,  3,  2,  1,  7,  6 }
    unsigned int* pStockPricePerDay = NULL;
    
    // printf("Number of test cases: ");
    scanf("%d", &numTestCases);
    
    while (numTestCases-- > 0)
    {
        // printf("Num Days: ");
        scanf("%d", &numDays);
        
        if (numDays > 0)
        {
            if (pStockPricePerDay != NULL)
            {
                free((void*)pStockPricePerDay);
            }
            
            pStockPricePerDay = (unsigned int*) malloc(sizeof(unsigned int) * numDays);
            
            for (unsigned int i = 0; i < numDays; i++)
            {
                // printf("Day %d: ", i+1);
                scanf("%d", &pStockPricePerDay[i]);
            }
            
            ProcessStockPrices(pStockPricePerDay, numDays);
        }
    }
    
    if (pStockPricePerDay != NULL)
    {
        free(pStockPricePerDay);
    }
    
    return 0;
}
