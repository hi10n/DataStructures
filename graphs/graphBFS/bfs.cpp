
#include "bfs.hpp"

using namespace std;

// -----------------------------------------------------------------
// Calculate the shortest path from the source node to the sink node
// -----------------------------------------------------------------
VOID BFS::CalculateShortestPath(GraphNode *pSrcGraphNode,   ///< Source node
                                GraphNode *pSinkNode)       ///< Sink node
{
    BOOL isSinkNodeReached = FALSE;
    CHAR sinkNodeId        = pSinkNode->nodeId;
    
    m_head = 0;
    m_tail = 0;
    
    pSrcGraphNode->isVisited         = TRUE;
    m_bfsQueue[m_tail].pNode         = pSrcGraphNode;
    m_bfsQueue[m_tail].srcNodeQIndex = 0;
    m_tail++;
    
    while (isSinkNodeReached == FALSE)
    {
        // Process m_head location in the queue - Put the neighbours of the node in the queue so that we'll examine all neighbours
        // before we examine the neighbours-neighours and so on
        for (UINT i = 0; i < m_bfsQueue[m_head].pNode->outDegree; i++)
        {
            GraphNode* pOutEdgeNode = m_bfsQueue[m_head].pNode->ppOutEdges[i];
            
            if (pOutEdgeNode->nodeId != sinkNodeId)
            {
                // Put the node in the BFS queue only if it has not been visited before
                if (pOutEdgeNode->isVisited == FALSE)
                {
                    pOutEdgeNode->isVisited          = TRUE;
                    m_bfsQueue[m_tail].pNode         = pOutEdgeNode;
                    m_bfsQueue[m_tail].srcNodeQIndex = m_head;
                    m_tail++;
                }
            }
            else
            {
                // We reached the sink node
                isSinkNodeReached                = TRUE;
                m_bfsQueue[m_tail].pNode         = pSinkNode;
                m_bfsQueue[m_tail].srcNodeQIndex = m_head;
                break;
            }
        }
        
        m_head++;
    }
    
    for (UINT i = 0; i <= m_tail; i++)
    {
        m_bfsQueue[i].pNode->isVisited = FALSE;
    }
    
    CHAR       nodePath[MaxNodes];
    UINT       numNodes   = 0;
    GraphNode* pGraphNode = NULL;
    UINT       queueIdx   = m_tail;
    
    // Backtrace from the sink node to the source node so that we can print the path from source to sink
    do
    {
        pGraphNode           = m_bfsQueue[queueIdx].pNode;
        nodePath[numNodes++] = pGraphNode->nodeId;
        queueIdx             = m_bfsQueue[queueIdx].srcNodeQIndex;
        
    } while (pGraphNode != pSrcGraphNode);
    
    printf ("Shortest path from source %c to sink %c is:    ", pSrcGraphNode->nodeId, pSinkNode->nodeId);
    
    for (INT i = numNodes-1; i >= 0; i--)
    {
        printf("%c ", nodePath[i]);
    }
    
    cout << NEWLINE << NEWLINE;
}

