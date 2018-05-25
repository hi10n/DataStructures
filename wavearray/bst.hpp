#include <cstring>

using namespace std;

#ifndef binarytree_h
#define binarytree_h

// -----------------------
// Node in the binary tree
// -----------------------
struct TreeNode
{
    int       data;         ///< Node data
    TreeNode* pLeftChild;   ///< Left child of the node
    TreeNode* pRightChild;  ///< Right child of the node
    TreeNode* pParent;      ///< Parent of the node
    TreeNode* pLLNext;      ///< Next in LinkList
    TreeNode* pLLPrev;      ///< Prev in LinkList
};

// -----------------
// Binary tree class
// -----------------
class BinaryTree
{
public:
    static BinaryTree* Create()
    {
        BinaryTree* pBinaryTree = new BinaryTree;
        pBinaryTree->Initialize();
        
        return pBinaryTree;
    }
    
    void Destroy()
    {
        delete this;
    }

    void InsertNode(int data);
    void DeleteTree();
    void WaveArray(vector<uint32_t>* pWaveArrayVec);
    
protected:
    BinaryTree() { };
    virtual ~BinaryTree() { };
    
private:
    void Initialize() { m_pHeadNode = NULL; }
    
    TreeNode* CreateNode(int data)
    {
        TreeNode* pTreeNode = (TreeNode*) calloc(1, sizeof(TreeNode));
        
        if (pTreeNode != NULL)
        {
            pTreeNode->data = data;
        }
        
        return pTreeNode;
    }
    
    void DestroyNode(TreeNode* pTreeNode)
    {
        free(pTreeNode);
    }
    
    // Search in the tree and add it in the correct location
    void Insert(int data);
    // Recursively empty the tree by deleting every node
    void Delete(TreeNode* pTreeNode);
    
    BinaryTree& operator=(const BinaryTree&); // Disable assignment operator
    BinaryTree(const BinaryTree&) = delete;   // Disable copy constructor
    
    TreeNode* m_pHeadNode;      ///< Head node of the tree
    TreeNode* m_pLLHeadNode;    ///< Head node of the LL
};

#endif /* binarytree_h */
