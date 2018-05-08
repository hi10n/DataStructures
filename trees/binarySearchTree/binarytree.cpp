
#include <iostream>
#include <cstdlib>
#include "binarytree.h"

// -----------------------------------------------
// Add a node in the tree - duplicates are allowed
// -----------------------------------------------
VOID BinaryTree::InsertNode(INT data)
{
    if (m_pHeadNode == NULL)
    {
        m_pHeadNode          = CreateNode(data);
        m_pHeadNode->pParent = NULL;
    }
    else
    {
        Insert(data);
    }
}

// --------------------------------------
// Search and add in the correct location
// --------------------------------------
VOID BinaryTree::Insert(INT newData)
{
    ASSERT (m_pHeadNode != NULL);
    
    TreeNode* pCurrentNode = m_pHeadNode;
    TreeNode* pNewNode     = CreateNode(newData);
    BOOL      done         = FALSE;
    
    while (done == FALSE)
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
                done = TRUE;
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
                done= TRUE;
            }
        }
    }
}

// ------------------
// Preorder Traversal
// ------------------
VOID BinaryTree::PreorderTraversal(TreeNode* pTreeNode)
{
    if (pTreeNode != NULL)
    {
        // Process the node
        cout << pTreeNode->data << "\n";
        // Go left
        PreorderTraversal(pTreeNode->pLeftChild);
        // Go right
        PreorderTraversal(pTreeNode->pRightChild);
    }
}

// -------------------
// Postorder Traversal
// -------------------
VOID BinaryTree::PostorderTraversal(TreeNode* pTreeNode)
{
    if (pTreeNode != NULL)
    {
        // Go left
        PostorderTraversal(pTreeNode->pLeftChild);
        // Go right
        PostorderTraversal(pTreeNode->pRightChild);
        // Process the node
        cout << pTreeNode->data << "\n";
    }
}

// -----------------
// Inorder Traversal
// -----------------
VOID BinaryTree::InorderTraversal(TreeNode* pTreeNode)
{
    if (pTreeNode != NULL)
    {
        // Go left
        InorderTraversal(pTreeNode->pLeftChild);
        // Process the node
        cout << pTreeNode->data << "\n";
        // Go right
        InorderTraversal(pTreeNode->pRightChild);
    }
}

// -------------
// Binary Search
// -------------
TreeNode* BinaryTree::SearchNode(INT searchData)
{
    TreeNode* pCurrentNode    = m_pHeadNode;
    BOOL      found           = FALSE;
    UINT      numComparisions = 0;
    
    while ((pCurrentNode != NULL) && (found == FALSE))
    {
        numComparisions++;
        
        if (searchData != pCurrentNode->data)
        {
            // Go right
            if (searchData > pCurrentNode->data)
            {
                pCurrentNode = pCurrentNode->pRightChild;
            }
            else // Go left
            {
                pCurrentNode = pCurrentNode->pLeftChild;
            }
        }
        else
        {
            found = TRUE;
        }
    }
    
    if (found == TRUE)
    {
        printf("Found %d in the binary search tree after %d comparisions\n\n", searchData, numComparisions);
    }
    else
    {
        printf("Did not find %d in the binary search tree\n\n", searchData);
    }
    
    return pCurrentNode;
}

// -----------
// Delete Node
// -----------
VOID BinaryTree::DeleteNode(INT deleteData)
{
    TreeNode* pDeleteNode = SearchNode(deleteData);
    
    if (pDeleteNode != NULL)
    {
        // Handle the easier case of a node being deleted with 0 or 1 child
        if ((pDeleteNode->pLeftChild == NULL) || (pDeleteNode->pRightChild == NULL))
        {
            DeleteNodeWith0or1Child(pDeleteNode);
            FREE(pDeleteNode);
        }
        else
        {
            // In order to get the inorder successor of the deletenode we start with its
            // right child and the first node we process will be its inorder successor
            TreeNode* pInorderSuccessor = GetInorderSuccessor(pDeleteNode->pRightChild);
            
            ASSERT(pInorderSuccessor != NULL);
            
            // pInorderSuccessor will not have a left child
            DeleteNodeWith0or1Child(pInorderSuccessor);
            
            // Replace DeleteNode with InorderSuccessor
            pInorderSuccessor->pLeftChild           = pDeleteNode->pLeftChild;
            pInorderSuccessor->pRightChild          = pDeleteNode->pRightChild;
            pInorderSuccessor->pParent              = pDeleteNode->pParent;
            pInorderSuccessor->pLeftChild->pParent  = pInorderSuccessor;
            pInorderSuccessor->pRightChild->pParent = pInorderSuccessor;
            
            if (pDeleteNode == m_pHeadNode)
            {
                m_pHeadNode = pInorderSuccessor;
                cout << "Root node deleted with data " << deleteData << " New Root node data " << m_pHeadNode->data << NEWLINE;
            }
            else
            {
                cout << "Non-root node deleted with data " << deleteData << NEWLINE;
            }
        }
    }
    else
    {
        cout << "Node to be deleted with data " << deleteData << " not found!";
    }
}

// -----------------------------
// Delete Node with 0 or 1 child
// -----------------------------
VOID BinaryTree::DeleteNodeWith0or1Child(TreeNode* pDeleteNode)
{
    ASSERT(pDeleteNode != NULL);
    
    if (pDeleteNode != NULL)
    {
        TreeNode** ppParentNodePtr = NULL;
        
        if (pDeleteNode->pParent != NULL)
        {
            if (pDeleteNode->pParent->pLeftChild == pDeleteNode)
            {
                ppParentNodePtr = &pDeleteNode->pParent->pLeftChild;
            }
            else
            {
                ppParentNodePtr = &pDeleteNode->pParent->pRightChild;
            }
        }
        
        if (pDeleteNode != m_pHeadNode) // Non-Root node with 0 or 1 child is being deleted
        {
            if (pDeleteNode->pLeftChild != NULL)
            {
                *ppParentNodePtr                 = pDeleteNode->pLeftChild;
                pDeleteNode->pLeftChild->pParent = pDeleteNode->pParent;
            }
            else if (pDeleteNode->pRightChild != NULL)
            {
                *ppParentNodePtr                  = pDeleteNode->pRightChild;
                pDeleteNode->pRightChild->pParent = pDeleteNode->pParent;
            }
            else // Deletenode is a terminal node, so deletnode's parent doesnt point to anything now
            {
                *ppParentNodePtr = NULL;
            }
        }
        else // Root node with 0 or 1 child is being deleted
        {
            m_pHeadNode = NULL;
            
            if (pDeleteNode->pLeftChild != NULL)
            {
                m_pHeadNode          = pDeleteNode->pLeftChild;
                m_pHeadNode->pParent = NULL;
            }
            else if (pDeleteNode->pRightChild != NULL)
            {
                m_pHeadNode          = pDeleteNode->pRightChild;
                m_pHeadNode->pParent = NULL;
            }
            
            if (m_pHeadNode == NULL)
            {
                cout << "Tree EMPTY! - Everything deleted!" << NEWLINE << NEWLINE;
            }
        }
    }
}

// -------------------------------------------------------------------
// Returns the pointer to the Inorder successor of pTreeNode passed in
// -------------------------------------------------------------------
TreeNode* BinaryTree::GetInorderSuccessor(TreeNode* pTreeNode)
{
    TreeNode* pInorderSuccessorNode = NULL;
    
    if (pTreeNode != NULL)
    {
        pInorderSuccessorNode = pTreeNode;
        
        while (pInorderSuccessorNode->pLeftChild != NULL)
        {
            pInorderSuccessorNode = pInorderSuccessorNode->pLeftChild;
        }

        cout << "Inorder successor is " << pInorderSuccessorNode->data << NEWLINE;
    }
    
    return pInorderSuccessorNode;
}
