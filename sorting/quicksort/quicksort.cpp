
#include <iostream>
#include "commondefs.h"
#include "quicksort.h"

using namespace std;

// -------------------
// Main method to sort
// -------------------
VOID Quicksort::Sort(UINT *pNumbers,
                     UINT numbersCount) const
{
    SortSubList(pNumbers, 0, numbersCount-1);
}

// ----------------------------------------------------------------------------------------------
// Recursive method to perform sorting of sublists - so that when the function returns the entire
// array will be sorted
// ----------------------------------------------------------------------------------------------
VOID Quicksort::SortSubList(UINT* pNumbers,             ///< Number array
                            UINT  leftIndex,            ///< Left element index of the sublist
                            UINT  rightIndex) const     ///< Right element index of the sublist
{
    BOOL     finalPositionFound = FALSE;
    UINT     finalPositionIdx   = leftIndex;
    UINT     leftIdxReduction   = leftIndex;
    UINT     rightIdxReduction  = rightIndex;
    SubLists sublist            = { 0 };
    
    // Perform the reduction step for the sublist
    while (finalPositionFound == FALSE)
    {
        INT  totalNumInSubList    = (rightIdxReduction - leftIdxReduction);
        BOOL rightToLeftReduction = FALSE;
        
        finalPositionFound = TRUE;
        
        if (totalNumInSubList > 0)
        {
            // Right to left searching for less
            for (UINT i = 0; i < totalNumInSubList; i++)
            {
                if (pNumbers[leftIdxReduction] > pNumbers[rightIdxReduction - i])
                {
                    UINT temp = pNumbers[leftIdxReduction];
                    
                    pNumbers[leftIdxReduction]      = pNumbers[rightIdxReduction - i];
                    pNumbers[rightIdxReduction - i] = temp;
                    
                    rightIdxReduction    = rightIdxReduction - i;
                    leftIdxReduction     = leftIdxReduction + 1;
                    // finalPositionIdx may change based on the left-to-right reduction step below
                    finalPositionIdx     = rightIdxReduction;
                    rightToLeftReduction = TRUE;
                    break;
                }
            }
        }
        
        // If right to left reduction is FALSE means the number is properly placed and there
        // is nothing more to do for that number - otherwise do the left to right reduction
        if (rightToLeftReduction == TRUE)
        {
            totalNumInSubList = rightIdxReduction - leftIdxReduction;
            
            if (totalNumInSubList > 0)
            {
                // Left to right searching for greater
                for (UINT i = 0; i < totalNumInSubList; i++)
                {
                    if (pNumbers[leftIdxReduction + i] > pNumbers[rightIdxReduction])
                    {
                        UINT temp = pNumbers[leftIdxReduction + i];
                        
                        pNumbers[leftIdxReduction + i] = pNumbers[rightIdxReduction];
                        pNumbers[rightIdxReduction]    = temp;
                        
                        leftIdxReduction   = leftIdxReduction + i;
                        rightIdxReduction  = rightIdxReduction - 1;
                        finalPositionIdx   = leftIdxReduction;
                        finalPositionFound = FALSE;
                        break;
                    }
                }
            }
        }
        
        // Final position of a number is found - now we need to perform the same redution step
        // on the left and right sublists (left and right of the number whose final position is
        // found)
        if (finalPositionFound == TRUE)
        {
            if (finalPositionIdx == leftIndex)
            {
                // There is no left sublist
                sublist.leftMin  = 0;
                sublist.leftMax  = 0;
                // Only right sublist
                sublist.rightMin = (leftIndex + 1);
                sublist.rightMax = rightIndex;
            }
            else if (finalPositionIdx == rightIndex)
            {
                // There is no right sublist
                sublist.rightMin  = 0;
                sublist.rightMax  = 0;
                // Only left sublist
                sublist.leftMin = leftIndex;
                sublist.leftMax = (rightIndex - 1);
            }
            else
            {
                sublist.leftMin  = leftIndex;
                sublist.leftMax  = (finalPositionIdx - 1);
                sublist.rightMin = (finalPositionIdx + 1);
                sublist.rightMax = rightIndex;
            }
            
            if (sublist.leftMax > sublist.leftMin)
            {
                SortSubList(pNumbers, sublist.leftMin, sublist.leftMax);
            }
            
            if (sublist.rightMax > sublist.rightMin)
            {
                SortSubList(pNumbers, sublist.rightMin, sublist.rightMax);
            }
        }
    }
}
