#include <cstring>

using namespace std;

#ifndef binarytree_h
#define binarytree_h

// -----------------------
// Node in the linked list
// -----------------------
struct Node
{
    int   data;         ///< Node data
    Node* pNext;        ///< Next node pointer
};

// -----------------
// Linked List class
// -----------------
class LinkList
{
public:
    static LinkList* Create()
    {
        LinkList* pLinkList = new LinkList;
        pLinkList->Initialize();
        
        return pLinkList;
    }
    
    void Destroy()
    {
        DeleteLinkList();
        delete this;
    }
    
    void PrintLinkList()
    {
        Node* pNode = m_pHeadNode;
        
        while (pNode != NULL)
        {
            cout << pNode->data << " ";
            pNode = pNode->pNext;
        }
        
        cout << "\n";
    }

    void AddNode(int data);
    void ReverseLinklist();
    
protected:
    LinkList() { };
    virtual ~LinkList() { };
    
private:
    void Initialize() { m_pHeadNode = NULL; }
    
    Node* CreateNode(int data)
    {
        Node* pNode = (Node*) calloc(1, sizeof(Node));
        
        if (pNode != NULL)
        {
            pNode->data = data;
        }
        
        return pNode;
    }
    
    Node* DestroyNode(Node* pNode)
    {
        Node* pNext = pNode->pNext;
        free(pNode);
        return pNext;
    }
    
    Node* ReverseNodes(Node* pNode, Node* pNext);
    
    void DeleteLinkList();                  ///< Destroy entire linklist
    
    LinkList& operator=(const LinkList&);   ///< Disable assignment operator
    LinkList(const LinkList&) = delete;     ///< Disable copy constructor
    
    Node* m_pHeadNode;                      ///< Head node of the tree
};

#endif /* binarytree_h */
