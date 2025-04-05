class Solution {
public:
    int m = 0;
    int n = 0;
    const char land = '1';
    const char water = '0';
    void DFS(vector<vector<char>>& grid, int i, int j){
        if (i < 0 || i >= this->m || j < 0 || j >= this->n)
            return;
        if (grid[i][j] != this->land)
            return;
        
        grid[i][j] = this->water;
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        int count = 0;

        for (int i = 0; i < this->m; i++){
            for (int j = 0; j < this->n; j++){
                if (grid[i][j] == this->land){
                    count++;
                    DFS(grid, i, j);
                }
            }
        }

        return count;
    }
};