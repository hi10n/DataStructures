
#include "dfs.hpp"

using namespace std;

// -------------------------------------------------
// Compute all nodes reachable from some source node
// -------------------------------------------------
VOID DFS::ComputeAllReachableNodes(GraphNode *pSrcGraphNode)   ///< Source node
{
    printf("All nodes reachable from source node %c are:    ", pSrcGraphNode->nodeId);
    
    ProcessNode(pSrcGraphNode);
    
    cout << NEWLINE << NEWLINE;
}

// -----------------------------------------------------------------------
// Recursive processing of each node so that we follow one path to the end
// -----------------------------------------------------------------------
VOID DFS::ProcessNode(GraphNode* pGraphNode)
{
    pGraphNode->isVisited = TRUE;
    
    cout << pGraphNode->nodeId << " ";
    
    for (UINT i = 0; i < pGraphNode->outDegree; i++)
    {
        if (pGraphNode->ppOutEdges[i]->isVisited == FALSE)
        {
            // We follow each path till we reach a node thats visited or does not have any out edges
            ProcessNode(pGraphNode->ppOutEdges[i]);
        }
    }
}

