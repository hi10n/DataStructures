#ifndef bfs_hpp
#define bfs_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "bfs.hpp"
#include "commondefs.h"
#include "graph.h"

using namespace std;

// -------------------
// BFS Algorithm class
// -------------------
class BFS
{
public:
    static BFS* Create()
    {
        BFS* pBFS = NEW BFS;
        pBFS->Initialize();
        
        return pBFS;
    };
    
    VOID Destroy() { DELETE this; }
    
    VOID CalculateShortestPath(GraphNode* pSrcGraphNode, GraphNode* pSinkNode);
    
protected:
    BFS()          { };
    virtual ~BFS() { cout << "BFS object destroyed" << NEWLINE << NEWLINE; }
    
private:
    BFS(const BFS&);            // Disallow copy constructor
    BFS& operator=(const BFS&); // Disallow assignment operator
    
    VOID Initialize() { };
    
    static const UINT MaxNodes = 32;
    
    struct BFSQueue
    {
        GraphNode* pNode;           ///< Node encountered during BFS
        UINT       srcNodeQIndex;   ///< Index in the queue, of the node that inserted the queue entry
    };
    
    BFSQueue m_bfsQueue[MaxNodes];  ///< Queue used during BFS
    UINT     m_tail;                ///< Location where new entries are added
    UINT     m_head;                ///< Location to be processed in the queue
};

#endif /* bfs_hpp */
