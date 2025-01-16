class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n, char target, char replace) {
        if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size())
            return;
        if (grid[m][n] != target)
            return;
        
        grid[m][n] = replace;
        dfs(grid, m - 1, n, target, replace);
        dfs(grid, m + 1, n, target, replace);
        dfs(grid, m, n - 1, target, replace);
        dfs(grid, m, n + 1, target, replace);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j, '1', '0');
                }
            }
        }

        return count;
    }
};