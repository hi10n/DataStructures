
#include <iostream>
#include <cmath>

#include "binarytree.h"

using namespace std;

int main(int argc, const char * argv[])
{
    BinaryTree* pBinaryTree = BinaryTree::Create();
    INT         treeData[]  = { 50, 30, 70, 20, 60, 75 };
    UINT        numData     = (sizeof(treeData) / sizeof(INT));
    
    for (UINT i = 0; i < numData; i++)
    {
        pBinaryTree->InsertNode(treeData[i]);
    }
    
    cout << "Number of nodes in binary tree = " << numData << NEWLINE;
    cout << "Depth of binary tree = " << static_cast<UINT>(log2(numData)+1) << NEWLINE << NEWLINE;
    
    cout << "Preorder Traversal \n";
    pBinaryTree->Preorder();
    cout << "\nPostorder Traversal \n";
    pBinaryTree->Postorder();
    cout << "\nInorder Traversal \n";
    pBinaryTree->Inorder();
    
    cout << NEWLINE;
    
    // Search for every number that we added previously
    for (UINT i = 0; i < numData; i++)
    {
        cout << "Searching for " << treeData[i] << NEWLINE;
        pBinaryTree->SearchNode(treeData[i]);
    }
    
    // Delete every node and then search for it
    for (UINT i = 0; i < numData; i++)
    {
        cout << "Deleting " << treeData[i] << NEWLINE;
        pBinaryTree->DeleteNode(treeData[i]);
        pBinaryTree->SearchNode(treeData[i]);
    }
    
    pBinaryTree->Destroy();

    return 0;
}
