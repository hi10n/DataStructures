#include <cstdlib>

#include "commondefs.h"

using namespace std;

#ifndef binarytree_h
#define binarytree_h

// -----------------------
// Node in the binary tree
// -----------------------
struct TreeNode
{
    INT       data;         ///< Node data
    TreeNode* pLeftChild;   ///< Left child of the node
    TreeNode* pRightChild;  ///< Right child of the node
    TreeNode* pParent;      ///< Parent of the node
};

// -----------------
// Binary tree class
// -----------------
class BinaryTree
{
public:
    static BinaryTree* Create()
    {
        BinaryTree* pBinaryTree = NEW BinaryTree;
        pBinaryTree->Initialize();
        
        return pBinaryTree;
    }
    
    VOID Destroy()
    {
        DELETE this;
    }

    VOID      DeleteNode(INT data);
    VOID      InsertNode(INT data);
    TreeNode* SearchNode(INT data);
    VOID      Preorder()  { PreorderTraversal(m_pHeadNode);  }
    VOID      Postorder() { PostorderTraversal(m_pHeadNode); }
    VOID      Inorder()   { InorderTraversal(m_pHeadNode);   }
    
protected:
    BinaryTree() { };
    virtual ~BinaryTree() { };
    
private:
    VOID Initialize() { m_pHeadNode = NULL; }
    
    TreeNode* CreateNode(INT data)
    {
        TreeNode* pTreeNode = (TreeNode*) CALLOC(1, sizeof(TreeNode));
        
        if (pTreeNode != NULL)
        {
            pTreeNode->data = data;
        }
        
        return pTreeNode;
    }
    
    VOID DestroyNode(TreeNode* pTreeNode)
    {
        FREE(pTreeNode);
    }
    
    VOID DeleteNodeWith0or1Child(TreeNode* pDeleteNode);
    // Search in the tree and add it in the correct location
    VOID Insert(INT data);
    VOID PreorderTraversal(TreeNode* pTreeNode);
    VOID PostorderTraversal(TreeNode* pTreeNode);
    VOID InorderTraversal(TreeNode* pTreeNode);
    // Returns the pointer to the Inorder successor of the passed in node
    TreeNode* GetInorderSuccessor(TreeNode* pTreeNode);
    
    BinaryTree& operator=(const BinaryTree&); // Disable assignment operator
    BinaryTree(const BinaryTree&) = delete;   // Disable copy constructor
    
    TreeNode* m_pHeadNode;  ///< Head node of the tree
};

#endif /* binarytree_h */
