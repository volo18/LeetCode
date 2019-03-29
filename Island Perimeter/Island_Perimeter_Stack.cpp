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

    std::vector<int> findFirstNode(std::vector<std::vector<int>>& grid) {

        int nRows = grid.size();
        int nCols = grid[0].size();

        std::vector<int> xy;
        xy.resize(2);

        xy[0] = -1;
        xy[1] = -1;

        bool found = false;
        int ii = 0;
        int jj = 0;
        while ( ( ii < nRows ) && (found == false) ) {
            while ( ( jj < nCols ) && (found == false) ) {
                if (grid[ii][jj] > 0)
                    found = true;
                    xy[0] = ii;
                    xy[1] = jj;
                jj++;
            }
            ii++;
        }

        return xy;

    }

public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        //Counts the perimeter of true nodes given a 2D vector. Assumes solid mass

        int nRows = grid.size();
        int nCols = grid[0].size();
        
        std::vector<int> XY = findFirstNode(grid);

        std::cout << XY[0]<< std::endl;
        std::cout << XY[1]<< std::endl;

        

        int perimeter = 0;

        return perimeter;
        
    }

};


int main() {

    Solution mySol;

    std::vector<std::vector<int>> mtx = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };

    std::cout << "Perimeter: " << mySol.islandPerimeter(mtx) << std::endl;



    return 0;
}