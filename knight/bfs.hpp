
#ifndef bfs_hpp
#define bfs_hpp

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
// ------------
// Knight moves
// ------------
typedef struct
{
    int x;      ///< Move x by or Move x to
    int y;      ///< Move y by or Move y to
} Position, Move;

class BFS final
{
public:
    static BFS* Create(unsigned int chessBoardDim)
    {
        BFS* pBFS = new BFS;
        
        pBFS->Reset(chessBoardDim);
        
        return pBFS;
    }
    
    void Destroy()
    {
        delete this;
    }
    
    void Reset(unsigned int chessDimension)
    {
        m_head = 0;
        m_tail = 0;
        
        memset(&m_locationInfo[0][0], 0, sizeof(m_locationInfo));
        memset(&m_pQueue, 0, sizeof(m_pQueue));
    }
    
    // Calculate the number of moves to reach the destination
    bool CalculateMoves(unsigned int    chessBoardDim,
                        const Position* pKnightPosition,
                        const Position* pTargetKnightPosition);
    
protected:
    BFS() { }
    virtual ~BFS() { }
    
private:
    struct LocationInfo
    {
        bool     isVisited;     ///< Has this been visited before
        int      moves;         ///< Number of moves to reach from the source
        Position position;
    };
    
    // Checks to see if the move goes outside the chess board
    static bool IsValidMove(const Position* pCurrentLocation,
                            const Move*     pMoveBy,
                            Position*       pNewLocation,
                            unsigned int    maxXY);
    
    // Checks to see if this position on the chess board has already been visited before via a different path
    bool IsVisited(Position* pNewPosition)
    {
        return (m_locationInfo[pNewPosition->x][pNewPosition->y].isVisited);
    }
    
    static const unsigned int MaxKnightMoves      = 8;
    const Move                KnighMoves[MaxKnightMoves] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                                             {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
    
    LocationInfo  m_locationInfo[256][256];
    LocationInfo* m_pQueue[1024];
    unsigned int  m_head;
    unsigned int  m_tail;
};

#endif /* bfs_hpp */
