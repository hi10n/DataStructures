
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bfs.hpp"

int main(int argc, const char * argv[])
{
    unsigned int numTestCases         = 1;
    unsigned int chessBoardDim        = 16;       // 6;
    Position     knightPosition       = {11, 13}; // {4, 5};
    Position     targetKnightPosition = {10, 14}; // {1, 1};
    BFS*         pBFS                 = BFS::Create(chessBoardDim);
    
    printf("Number of testcases: ");
    scanf("%d", &numTestCases);
    
    while (numTestCases--)
    {
        printf("Chess Board Dimension: ");
        scanf("%d", &chessBoardDim);
        printf("Knight X Y: ");
        scanf("%d %d", &knightPosition.x, &knightPosition.y);
        printf("Target Knight Position X Y: ");
        scanf("%d %d", &targetKnightPosition.x, &targetKnightPosition.y);

        if ((knightPosition.x != targetKnightPosition.x) || (knightPosition.y != targetKnightPosition.y))
        {
            pBFS->CalculateMoves(chessBoardDim, &knightPosition, &targetKnightPosition);
            pBFS->Reset(chessBoardDim);
        }
        else
        {
            printf("0\n");
        }
    }
	
    pBFS->Destroy();
    return 0;
}
