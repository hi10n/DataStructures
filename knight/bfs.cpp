
#include "bfs.hpp"

// ------------------------------------------
// Check if the Knight's move is valid or not
// ------------------------------------------
bool BFS::IsValidMove(const Position* pCurrentLocation,
                      const Move*     pMoveBy,
                      Position*       pNewLocation,
                      unsigned int    maxXY)
{
    bool isValid = true;
    
    pNewLocation->x = pCurrentLocation->x + pMoveBy->x;
    pNewLocation->y = pCurrentLocation->y + pMoveBy->y;
    
    if ((pNewLocation->x > maxXY) || (pNewLocation->y > maxXY) || (pNewLocation->x == 0) || (pNewLocation->y == 0))
    {
        isValid = false;
    }
    
    return isValid;
}

// ----------------------------------------------------
// BFS moves to see if we can reach the target position
// ----------------------------------------------------
bool BFS::CalculateMoves(unsigned int    chessBoardDim,
                         const Position* pKnightPosition,
                         const Position* pTargetKnightPosition)
{
    Position newPosition   = { 0 };
    bool     targetReached = false;
    
    m_locationInfo[pKnightPosition->x][pKnightPosition->y].isVisited  = true;
    m_locationInfo[pKnightPosition->x][pKnightPosition->y].position.x = pKnightPosition->x;
    m_locationInfo[pKnightPosition->x][pKnightPosition->y].position.y = pKnightPosition->y;
    
    m_pQueue[m_tail++] = &m_locationInfo[pKnightPosition->x][pKnightPosition->y];
    
    while ((targetReached == false) && (m_head != m_tail))
    {
        for (unsigned int i = 0; i < MaxKnightMoves; i++)
        {
            if (IsValidMove(&m_pQueue[m_head]->position, &KnighMoves[i], &newPosition, chessBoardDim) == true)
            {
                if ((newPosition.x != pTargetKnightPosition->x) || (newPosition.y != pTargetKnightPosition->y))
                {
                    if (IsVisited(&newPosition) == false)
                    {
                        m_locationInfo[newPosition.x][newPosition.y].position.x = newPosition.x;
                        m_locationInfo[newPosition.x][newPosition.y].position.y = newPosition.y;
                        m_locationInfo[newPosition.x][newPosition.y].isVisited  = true;
                        m_locationInfo[newPosition.x][newPosition.y].moves      = (m_pQueue[m_head]->moves + 1);
                        
                        m_pQueue[m_tail++] = &m_locationInfo[newPosition.x][newPosition.y];
                    }
                }
                else
                {
                    targetReached = true;
                    printf("Total Moves: %u\n", m_pQueue[m_head]->moves + 1);
                }
            }
        }
        
        m_head++;
    };

    if (targetReached == false)
    {
        printf("1\n");
    }
    
    return targetReached;
}
