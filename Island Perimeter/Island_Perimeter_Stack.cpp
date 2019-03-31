#include <iostream>
#include <vector>

class gridNode {
  
private:
    int ii;
    int jj;
    
public:
    gridNode(int inputI, int inputJ) {
        ii = inputI;
        jj = inputJ;
    }
    
    void setII(int inputII) {ii = inputII;};
    void setJJ(int inputJJ) {jj = inputJJ;};
    int getII() {return ii;};
    int getJJ() {return jj;};
};

class Solution {

    private:

    std::vector<std::vector<bool> > visited;

    std::vector<int> findFirstNode(std::vector<std::vector<int> >& grid)
    {
        int nRows = grid.size();
        int nCols = grid[0].size();

        std::vector<int> xy;
        xy.resize(2);

        xy[0] = -1;
        xy[1] = -1;

        for (int ii = 0; ii < nRows; ii++)
        {
            for (int jj = 0; jj < nCols; jj++)
            {
                if (grid[ii][jj] > 0)
                {
                    xy[0] = ii;
                    xy[1] = jj;
                    return xy;
                }
            }
        }
        return xy;
    }

    void initVisted(int nR, int nC)
    {
        visited.resize(nR);
        
        
        for ( int ii = 0; ii < nR; ii++ ) {
            visited[ii].resize(nC);
            for ( int jj = 0; jj < nC; jj++ ) {
                visited[ii][jj] = false;
            }
        }
    }
    
    bool isNeighbourHelper(std::vector<std::vector<int> > &grid, int a, int b)
    {
        //is the element at (a,b) a node?
        int nRows = grid.size();
        int nCols = grid[0].size();
        
        if ( (a >= 0)  && (a < nRows) &&  (b >= 0) && (b < nCols) )
            if (grid[a][b] > 0 )
                return true;
        
        return false;
    }
    
    bool isNeighbour(std::vector<std::vector<int> > &grid, std::vector<gridNode> &queue, int a, int b )
    {
        
        if ( isNeighbourHelper(grid, a, b) )
        {
            if (visited[a][b] == false)
            {
                gridNode newNode(a,b);
                queue.push_back(newNode);
                visited[a][b] = true;
            }
            return true;
        }
        return false;
    }
    
public:
    
    int islandPerimeter(std::vector<std::vector<int> >& grid)
    {
        //Counts the perimeter of true nodes given a 2D vector. Assumes solid mass

        int perimeter = 0;
        
        int nRows = grid.size();
        int nCols = grid[0].size();
        
        initVisted(nRows,nCols);
        
        std::vector<int> XY = findFirstNode(grid);

        std::vector<gridNode> q;
        
        gridNode node(XY[0],XY[1]);
        q.push_back(node);
        visited[XY[0]][XY[1]] = true;
        
        while ( q.size()  > 0)
        {
            gridNode tempNode = q.back();
            q.pop_back();
            
            int nNeighbours = 0;
            
            int curII = tempNode.getII();
            int curJJ = tempNode.getJJ();
        
            if (isNeighbour(grid,q,curII-1,curJJ) )
                nNeighbours++;
            
            if (isNeighbour(grid,q,curII+1,curJJ) )
                nNeighbours++;
            
            if (isNeighbour(grid,q,curII,curJJ-1) )
                nNeighbours++;
            
            if (isNeighbour(grid,q,curII,curJJ+1) )
                nNeighbours++;
            
            
            perimeter += 4 - nNeighbours;
        }
        return perimeter;
        
    }

};



int main() {

    Solution mySol;

    std::vector<std::vector<int> > mtx;   //= { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };

    
    int nRows = 4;
    int nCols = 4;
    mtx.resize(nRows);
    for ( int ii = 0; ii < nRows; ii++ )
    {
        mtx[ii].resize(nCols);
        for ( int jj = 0; jj < nCols; jj++ )
        {
            mtx[ii][jj] = 0;
        }
    }
    mtx[0][0] = 0;
    mtx[0][1] = 1;
    mtx[0][2] = 0;
    mtx[0][3] = 0;
    
    mtx[1][0] = 1;
    mtx[1][1] = 1;
    mtx[1][2] = 1;
    mtx[1][3] = 0;
    
    mtx[2][0] = 0;
    mtx[2][1] = 1;
    mtx[2][2] = 0;
    mtx[2][3] = 0;
    
    mtx[3][0] = 1;
    mtx[3][1] = 1;
    mtx[3][2] = 0;
    mtx[3][3] = 0;

    std::cout << "Perimeter: " << mySol.islandPerimeter(mtx) << std::endl;

    return 0;
}
