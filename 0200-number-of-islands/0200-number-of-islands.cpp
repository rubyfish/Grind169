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

    std::queue<pair<int, int>> neighbors;
    void BFS(vector<vector<char>>& grid){
        while(!this->neighbors.empty()){
            pair<int, int> n = neighbors.front();
            neighbors.pop();
            int i = n.first;
            int j = n.second;
            if (i < 0 || i >= this->m || j < 0 || j >= this->n)
                continue;
            if (grid[i][j] != this->land)
                continue;
            grid[i][j] = this->water;
            neighbors.push({i+1, j});
            neighbors.push({i-1, j});
            neighbors.push({i, j+1});
            neighbors.push({i, j-1});
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        int count = 0;

        for (int i = 0; i < this->m; i++){
            for (int j = 0; j < this->n; j++){
                if (grid[i][j] == this->land){
                    count++;
                    
                    //DFS
                    //DFS(grid, i, j);
                    
                    //BFS
                    this->neighbors.push({i, j});
                    BFS(grid);
                }
            }
        }

        return count;
    }
};