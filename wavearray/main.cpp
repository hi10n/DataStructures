#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>

#include "bst.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    uint32_t         numTestcases;
    uint32_t         totalNumbers;
    uint32_t         number;
    vector<uint32_t> numVec;
    BinaryTree*      pBST = BinaryTree::Create();
    
    cin >> numTestcases;
    
    for (uint32_t i = 0; i < numTestcases; i++)
    {
        cin >> totalNumbers;
        
        for (uint32_t i = 0; i < totalNumbers; i++)
        {
            cin >> number;
            pBST->InsertNode(number);
        }
        
        pBST->WaveArray(&numVec);
        
        for (vector<uint32_t>::iterator it = numVec.begin(); it != numVec.end(); it++)
        {
            cout << *it << " ";
        }
        
        numVec.clear();
        pBST->DeleteTree();
        
        cout << "\n";
    }
    
    return 0;
}





