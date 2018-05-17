#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct
{
    uint32_t maxWToLastElement;
    uint32_t maxWToSecondLastElement;
} MaxWeights;

static const uint32_t MaxNumbers = 1000;
static MaxWeights     FinalWeights[MaxNumbers];

void MaxSubArray(vector<uint32_t>* pNumVec,
                 uint32_t          index,
                 uint32_t          totalNumbers,
                 MaxWeights*       pPerIndexWeights)
{
    vector<uint32_t>::iterator it = pNumVec->begin();
    uint32_t currentValue         = *(it + index);
    MaxWeights max2Weights        = { 0 };
    MaxWeights max3Weights        = { 0 };
    
    if ((FinalWeights[index].maxWToLastElement == 0) && (FinalWeights[index].maxWToSecondLastElement == 0))
    {
        if ((it + index + 2) < pNumVec->end()) // Have we reached the last element in the DFS path
        {
            MaxSubArray(pNumVec, index+2, totalNumbers, &max2Weights);
            
            if ((it + index + 3) < pNumVec->end())
            {
                MaxSubArray(pNumVec, index+3, totalNumbers, &max3Weights);
            }
            
            FinalWeights[index].maxWToLastElement       = max(max2Weights.maxWToLastElement, max3Weights.maxWToLastElement);
            FinalWeights[index].maxWToSecondLastElement = max(max2Weights.maxWToSecondLastElement, max3Weights.maxWToSecondLastElement);
            
            if (FinalWeights[index].maxWToLastElement > 0)
            {
                FinalWeights[index].maxWToLastElement += currentValue;
            }
            
            if (FinalWeights[index].maxWToSecondLastElement > 0)
            {
                FinalWeights[index].maxWToSecondLastElement += currentValue;
            }
        }
        else
        {
            if (index == totalNumbers - 1)
            {
                FinalWeights[index].maxWToLastElement = currentValue;
            }
            else
            {
                FinalWeights[index].maxWToSecondLastElement = currentValue;
            }
        }
    }
    
    *pPerIndexWeights = FinalWeights[index];
}

uint32_t FindMaxSubArray(vector<uint32_t>* pNumVec, uint32_t totalNumbers)
{
    uint32_t   maxPath = 0;
    MaxWeights perIndexWeights[MaxNumbers] = { 0 };
    
    MaxSubArray(pNumVec, 0, totalNumbers, &perIndexWeights[0]);
    
    maxPath = max(perIndexWeights->maxWToLastElement, perIndexWeights->maxWToSecondLastElement);
    
    perIndexWeights->maxWToLastElement       = 0;
    perIndexWeights->maxWToSecondLastElement = 0;
    
    MaxSubArray(pNumVec, 1, totalNumbers, &perIndexWeights[0]);
    
    maxPath = max(maxPath, max(perIndexWeights->maxWToLastElement, perIndexWeights->maxWToSecondLastElement));
    
    return maxPath;
}

int main(int argc, const char * argv[])
{
    uint32_t         numTestcases;
    uint32_t         totalNumbers;
    uint32_t         number;
    vector<uint32_t> numVec;
    
    cin >> numTestcases;
    
    for (uint32_t i = 0; i < numTestcases; i++)
    {
        cin >> totalNumbers;
        
        numVec.clear();
        memset(&FinalWeights[0], 0, sizeof(FinalWeights));
        
        for (uint32_t i = 0; i < totalNumbers; i++)
        {
            cin >> number;
            numVec.push_back(number);
        }
        
        cout << FindMaxSubArray(&numVec, totalNumbers) << "\n";
    }
    
    cout << "\n";
    
    return 0;
}




