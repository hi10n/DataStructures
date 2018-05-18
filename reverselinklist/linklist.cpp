
#include <iostream>
#include <cstdlib>
#include "linklist.hpp"

// -----------------------------------------------
// Add a node in the list - duplicates are allowed
// -----------------------------------------------
void LinkList::AddNode(int data)
{
    if (m_pHeadNode == NULL)
    {
        m_pHeadNode        = CreateNode(data);
        m_pHeadNode->pNext = NULL;
    }
    else
    {
        Node* pCurrentNode = m_pHeadNode;
        Node* pNewNode     = CreateNode(data);
        
        while (pCurrentNode->pNext != NULL)
        {
            pCurrentNode = pCurrentNode->pNext;
        }
        
        pCurrentNode->pNext = pNewNode;
    }
}

// ----------------------
// Delete the entire list
// ----------------------
void LinkList::DeleteLinkList()
{
    Node* pCurrentNode = m_pHeadNode;
    
    while (pCurrentNode != NULL)
    {
        pCurrentNode = DestroyNode(pCurrentNode);
    }
    
    m_pHeadNode = NULL;
}

// ----------------------
// Reverse the entire list
// ----------------------
void LinkList::ReverseLinklist()
{
    if (m_pHeadNode != NULL)
    {
        Node* pNode     = m_pHeadNode;
        Node* pNext     = m_pHeadNode->pNext;
        Node* pNodeTemp = NULL;
        
        while (pNext != NULL)
        {
            pNodeTemp = pNext;
            pNext     = ReverseNodes(pNode, pNext);
            pNode     = pNodeTemp;
        }

        m_pHeadNode->pNext = NULL;
        m_pHeadNode        = pNode;
    }
}

// -----------------
// Reverse two nodes
// -----------------
Node* LinkList::ReverseNodes(Node* pNode, Node* pNext)
{
    Node* pNextNode = pNext->pNext;
    
    pNext->pNext = pNode;
    
    return pNextNode;
}

