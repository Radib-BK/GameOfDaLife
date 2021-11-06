#include <stdio.h>
#include <stdlib.h>
#define rowCounts 20
#define colCounts 60

/*
       '.' indicates dead cell
       '0' indicates alive cell
*/

//Returns the count of alive neighbours.
int Live_Neighbour_Count(int old_generation[rowCounts][colCounts], int num1, int num2)
{
    int i, j, count = 0;
    for (i = num1 - 1; i <= num1 + 1; i++)
    {
        for (j = num2 - 1; j <= num2 + 1; j++)
        {
            if ((i == num1 && j == num2) || (i < 0 || j < 0) || (i >= rowCounts || j >= colCounts))
            {
                continue;
            }
            if (old_generation[i][j] == 0)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int old_Generation[rowCounts][colCounts], new_Generation[rowCounts][colCounts];
    int row = 0, col = 0, generation_Count, i, j, z;
    int Neighbour_Live_Cell;

    for (i = 0; i < rowCounts; i++)
    {
        for (j = 0; j < colCounts; j++)
        {

            old_Generation[i][j] = 1;
        }
    }

    //Generate matrix canvas (live and dead cells)

    printf("Enter the Position of Alive Cells:\n");
    while (row >= 0 && col >= 0 && row < rowCounts && col < colCounts)

    {
        scanf("%d,%d", &row, &col);
        old_Generation[row][col] = 0;
    }
    printf("Enter Number of Generations: ");
    scanf("%d", &generation_Count);

    //Print initial old generation

    printf("Initial Stage:");
    for (i = 0; i < rowCounts; i++)
    {
        for (j = 0; j < colCounts; j++)
        {
            if (old_Generation[i][j] == 1)
            {
                printf(".");
            }
            else
                printf("%d", old_Generation[i][j]);
        }
        printf("\n");
    }

    //Next canvas values based on previous generation alive neighbour count

    while (generation_Count--)

    {

        for (i = 0; i < rowCounts; i++)
        {
            for (j = 0; j < colCounts; j++)
            {
                Neighbour_Live_Cell = Live_Neighbour_Count(old_Generation, i, j);
                if (old_Generation[i][j] == 0 && (Neighbour_Live_Cell == 2 || Neighbour_Live_Cell == 3))
                {
                    new_Generation[i][j] = 0;
                }

                else if (old_Generation[i][j] == 1 && Neighbour_Live_Cell == 3)
                {
                    new_Generation[i][j] = 0;
                }

                else
                {
                    new_Generation[i][j] = 1;
                }
            }
        }

        //print Next generation

        getchar();
        system("cls");
        printf("\nNext Generation:\n");

        for (i = 0; i < rowCounts; i++)
        {
            printf("[%.3d] ", i);
            for (j = 0; j < colCounts; j++)
            {
                if (new_Generation[i][j] == 1)
                {
                    printf(".");
                }
                else
                    printf("%d", new_Generation[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i < rowCounts; i++)
        {
            for (j = 0; j < colCounts; j++)
            {

                old_Generation[i][j] = new_Generation[i][j];
            }
        }
    }
    return 0;

    /* 
Input :

Simulate Glider:     
0,1
1,2
2,0
2,1
2,2
-1,-1

Simulate Combination:
5,3
6,1
6,3
7,2
7,3
5,6
6,6
6,8
7,6
7,7
-1,-1

Simulate Blinker: 
0,1
1,1
2,1
-1,-1

Simulate Beacon: 
1,1
2,1
1,2
4,3 
3,4 
4,4
-1,-1

Simulate Figure:
0,12
1,12
2,12
1,6
2,7
0,8
1,8
2,8 
-1,-1
    
Simulate Gosper Glider Gun:
5,1
5,2 
6,1 
6,2 
5,11 
6,11
7,11 
4,12 
3,13 
3,14
8,12
9,13
9,14
6,15
4,16
5,17
6,17
7,17 
6,18
8,16
3,21
4,21
5,21
3,22
4,22
5,22
2,23
6,23
1,25
2,25
6,25
7,25
3,35
4,35
3,36
4,36
-1,-1
   
*/
}
