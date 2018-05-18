
#include <iostream>
#include <cstdlib>
#include "bst.hpp"

// -----------------------------------------------
// Add a node in the tree - duplicates are allowed
// -----------------------------------------------
void BinaryTree::InsertNode(int data)
{
    if (m_pHeadNode == NULL)
    {
        m_pHeadNode              = CreateNode(data);
        m_pHeadNode->pParent     = NULL;
        m_pHeadNode->pLeftChild  = NULL;
        m_pHeadNode->pRightChild = NULL;
        m_pHeadNode->pLLNext     = NULL;
        m_pHeadNode->pLLPrev     = NULL;
        m_pLLHeadNode            = m_pHeadNode;
    }
    else
    {
        Insert(data);
    }
}

// --------------------------------------
// Search and add in the correct location
// --------------------------------------
void BinaryTree::Insert(int newData)
{
    TreeNode* pCurrentNode = m_pHeadNode;
    TreeNode* pNewNode     = CreateNode(newData);
    bool      done         = false;
    
    while (done == false)
    {
        if (newData > pCurrentNode->data)
        {
            // Go right
            if (pCurrentNode->pRightChild != NULL)
            {
                pCurrentNode = pCurrentNode->pRightChild;
            }
            else
            {
                // Insert the node and we are done
                pCurrentNode->pRightChild = pNewNode;
                pNewNode->pParent         = pCurrentNode;
                pNewNode->pLLNext         = pCurrentNode->pLLNext;
                pCurrentNode->pLLNext     = pNewNode;
                pNewNode->pLLPrev         = pCurrentNode;
                done                      = true;
            }
        }
        else
        {
            // Go left
            if (pCurrentNode->pLeftChild != NULL)
            {
                pCurrentNode = pCurrentNode->pLeftChild;
            }
            else
            {
                // Insert the node and we are done
                pCurrentNode->pLeftChild = pNewNode;
                pNewNode->pParent        = pCurrentNode;
                pNewNode->pLLNext        = pCurrentNode;
                
                if (pCurrentNode->pLLPrev != NULL)
                {
                    pCurrentNode->pLLPrev->pLLNext = pNewNode;
                    pNewNode->pLLPrev              = pCurrentNode->pLLPrev;
                    pCurrentNode->pLLPrev          = pNewNode;
                }
                else
                {
                    pCurrentNode->pLLPrev = pNewNode;
                }
                
                done = true;
            }
        }
    }
    
    if (m_pLLHeadNode->data >= pNewNode->data)
    {
        m_pLLHeadNode = pNewNode;
    }
}

// ----------------------
// Delete the entire tree
// ----------------------
void BinaryTree::DeleteTree()
{
    TreeNode* pTreeNode = m_pLLHeadNode;
    
    while (pTreeNode != NULL)
    {
        pTreeNode = pTreeNode->pLLNext;
    }
    
    if (m_pHeadNode != NULL)
    {
        Delete(m_pHeadNode);
    }
}

// ----------------------
// Delete the entire tree
// ----------------------
void BinaryTree::Delete(TreeNode* pTreeNode)
{
    if (pTreeNode != NULL)
    {
        if ((pTreeNode->pLeftChild == NULL) && (pTreeNode->pRightChild == NULL))
        {
            if (pTreeNode->pParent != NULL)
            {
                if (pTreeNode == pTreeNode->pParent->pLeftChild)
                {
                    pTreeNode->pParent->pLeftChild = NULL;
                }
                else
                {
                    pTreeNode->pParent->pRightChild = NULL;
                }
                
                free (pTreeNode);
            }
        }
        else
        {
            if (pTreeNode->pLeftChild != NULL)
            {
                Delete(pTreeNode->pLeftChild);
            }
            
            if (pTreeNode->pRightChild != NULL)
            {
                Delete(pTreeNode->pRightChild);
            }

            // All child nodes delete, so free the node itself
            free(pTreeNode);
        }
    }
}

// ---------------
// Find the median
// ---------------
void BinaryTree::Median(unsigned int numElements)
{
    TreeNode*    pLinkNode = m_pLLHeadNode;
    unsigned int median    = 0;
    
    if (numElements % 2 == 0)
    {
        unsigned int middleElement = numElements / 2;
        
        middleElement = (middleElement >= 1) ? (middleElement - 1) : 0;
        
        while (middleElement-- > 0)
        {
            pLinkNode = pLinkNode->pLLNext;
        }
        
        median = pLinkNode->data;
        
        if (pLinkNode->pLLNext != NULL)
        {
            median += pLinkNode->pLLNext->data;
            median /= 2;
        }
    }
    else
    {
        unsigned int middleElement = numElements / 2;
        
        while (middleElement-- > 0)
        {
            pLinkNode = pLinkNode->pLLNext;
        }
        
        median = pLinkNode->data;
    }
    
    cout << median << "\n";
}
