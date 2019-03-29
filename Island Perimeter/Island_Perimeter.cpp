#include <iostream>
#include <vector>

class Solution {

    private:

    bool isNeighbour(std::vector<std::vector<int>> &grid, int a, int b) {
    //is the element at (a,b) a node? 
        int nRows = grid.size();
        int nCols = grid[0].size();
        
        if ( (a >= 0)  && (a < nRows) &&  (b >= 0) && (b < nCols) )
            if (grid[a][b] > 0 )
                return true;
                        
        return false;   
    }

    int countAdjacentNeighbours(std::vector<std::vector<int>> &grid, int ii, int jj) {
    //Counts the four adjacent neighbours

        int nNeighbours = 0;
        
        //above
        if ( isNeighbour(grid,ii-1, jj) )
            nNeighbours++;
        
        //below
        if ( isNeighbour(grid,ii+1, jj) )
            nNeighbours++;
        
        //right
        if ( isNeighbour(grid,ii, jj+1) )
            nNeighbours++;
        
        //left
        if ( isNeighbour(grid,ii, jj-1) )
            nNeighbours++;

        return nNeighbours;
    }



public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        //Counts the perimeter of true nodes given a 2D vector. Assumes solid mass


        int nRows = grid.size();
        int nCols = grid[0].size();
        
        int perimeter = 0;
        for (int ii = 0; ii < nRows; ii++)
        {
           for (int jj = 0; jj < nCols; jj++)
           {
               if (grid[ii][jj] == 0)
                   continue;
                       
               perimeter  += 4 - countAdjacentNeighbours(grid, ii, jj);
           
            }

        } 
        return perimeter;
        
    }

};


int main() {

    Solution mySol;

    std::vector<std::vector<int>> mtx = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };

    std::cout << mySol.islandPerimeter(mtx) << std::endl;



    return 0;
}