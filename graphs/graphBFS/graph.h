#ifndef graph_h
#define graph_h

// -------------------
// One node in a graph
// -------------------
struct GraphNode
{
    CHAR        nodeId;         ///< Node Id
    UINT        outDegree;      ///< Out degree
    GraphNode** ppOutEdges;     ///< Out edges
    BOOL        isVisited;      ///< Has the node been visited or not while walking the graph
};

// ----------------
// Node create info
// ----------------
struct NodeCreateInfo
{
    UINT nodeId;                ///< Node Id - 'A', 'B', 'C' etc
    UINT outDegree;             ///< Number of adjacent nodes
    CHAR sinkNodes[3];          ///< List of adjacent nodes - currently max is 3
};

#endif /* graph_h */
