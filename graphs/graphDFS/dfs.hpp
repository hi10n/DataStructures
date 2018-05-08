#ifndef DFS_HPP
#define DFS_HPP

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "bfs.hpp"
#include "commondefs.h"
#include "graph.h"

using namespace std;

// -------------------
// DFS Algorithm class
// -------------------
class DFS
{
public:
    static DFS* Create()
    {
        DFS* pDFS = NEW DFS;
        pDFS->Initialize();
        
        return pDFS;
    };
    
    VOID Destroy() { DELETE this; }
    
    VOID ComputeAllReachableNodes(GraphNode* pSrcGraphNode);
    
protected:
    DFS()          { };
    virtual ~DFS() { cout << "DFS object destroyed" << NEWLINE << NEWLINE; }
    
private:
    DFS(const DFS&);            // Disallow copy constructor
    DFS& operator=(const DFS&); // Disallow assignment operator
    
    VOID Initialize() { };
    VOID ProcessNode(GraphNode* pGraphNode);
};

#endif /* DFS_HPP */

