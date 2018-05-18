#include <iostream>
#include "bst.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    BinaryTree*  pBST = BinaryTree::Create();
    unsigned int totalNumInStream;
    unsigned int newNumber;
    
    cin >> totalNumInStream;
    
    for (unsigned int j = 0; j < totalNumInStream; j++)
    {
        cin >> newNumber;
        pBST->InsertNode(newNumber);
        pBST->Median(j + 1);
    }
    
    pBST->DeleteTree();
    
    return 0;
}
