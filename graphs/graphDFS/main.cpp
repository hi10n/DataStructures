#include <iostream>
#include "bfs.hpp"
#include "commondefs.h"
#include "dfs.hpp"
#include "graph.h"

// -------------------------------------
// Reset the visited status of the nodes
// -------------------------------------
VOID ResetNodeVisited(GraphNode** pGraphNodes, UINT numNodes)
{
    // Create the graph nodes
    for (UINT i = 0; i < numNodes; i++)
    {
        pGraphNodes[i]->isVisited  = FALSE;
    }
}

int main(int argc, const char * argv[])
{
    // Adjacency Lists
    static const NodeCreateInfo Nodes[] =
    {
        { 'A', 3, { 'F', 'C', 'B' } },      ///< A --> F, C, B
        { 'B', 2, { 'G', 'C'} },            ///< B --> G, C
        { 'C', 1, { 'F' } },                ///< C --> F
        { 'D', 1, { 'C' } },                ///< D --> C
        { 'E', 3, { 'D', 'C', 'H' } },      ///< E --> D, C, H
        { 'F', 1, { 'D' } },                ///< F --> D
        { 'G', 2, { 'C', 'E' } },           ///< G --> C, E
        { 'H', 2, { 'D', 'I' } },           ///< H --> D, I
        { 'I', 2, { 'E', 'G' } }            ///< I --> E, G
    };
        
    static const UINT NumNodes = (sizeof(Nodes) / sizeof(NodeCreateInfo));
    
    GraphNode* pGraphNodes[NumNodes];
    
    // Create the graph nodes
    for (UINT i = 0; i < NumNodes; i++)
    {
        pGraphNodes[i]             = (GraphNode*) CALLOC(1, sizeof(GraphNode));
        pGraphNodes[i]->nodeId     = Nodes[i].nodeId;
        pGraphNodes[i]->outDegree  = Nodes[i].outDegree;
        pGraphNodes[i]->ppOutEdges = (GraphNode**) CALLOC(1, (sizeof(GraphNode*) * Nodes[i].outDegree));
        pGraphNodes[i]->isVisited  = FALSE;
    }
    
    // Link the graph nodes
    for (UINT i = 0; i < NumNodes; i++)
    {
        for (UINT j = 0; j < pGraphNodes[i]->outDegree; j++)
        {
            // Connecting the adjacent nodes
            pGraphNodes[i]->ppOutEdges[j] = pGraphNodes[Nodes[i].sinkNodes[j] - 'A'];
        }
    }
    
    // Run the DFS algorithm
    
    DFS* pDFS = DFS::Create();
    // Compute all nodes reachable from 'H'
    ResetNodeVisited(&pGraphNodes[0], NumNodes);
    pDFS->ComputeAllReachableNodes(pGraphNodes['H' - 'A']); // H D C F I E G
    // Compute all nodes reachable from 'C'
    ResetNodeVisited(&pGraphNodes[0], NumNodes);
    pDFS->ComputeAllReachableNodes(pGraphNodes['C' - 'A']); // C F D
    ResetNodeVisited(&pGraphNodes[0], NumNodes);
    // Compute all nodes reachable from 'I'
    ResetNodeVisited(&pGraphNodes[0], NumNodes);
    pDFS->ComputeAllReachableNodes(pGraphNodes['I' - 'A']); // I E D C F H G
    // Compute all nodes reachable from 'E'
    ResetNodeVisited(&pGraphNodes[0], NumNodes);
    pDFS->ComputeAllReachableNodes(pGraphNodes['E' - 'A']); // E D C F H I G
    
    pDFS->Destroy();
    
    return 0;
}
