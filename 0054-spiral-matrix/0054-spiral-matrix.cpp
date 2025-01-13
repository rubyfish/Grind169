class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //0,0 0,1 0,2 1,2 2,2 2,1 2,0 1,0 1,1
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        int x = 0;
        int y = 0;
        int d = 0;
        vector<int> results;
        int seen = 101;

        while (count != m*n){
            results.push_back(matrix[x][y]);
            matrix[x][y] = seen;
            int tmp_x = x + direction[d][0];
            int tmp_y = y + direction[d][1];
            if (tmp_x >= m || tmp_x < 0){
                d += 1;
            }
            else if (tmp_y >= n || tmp_y < 0){
                d += 1;
            }
            else if (matrix[tmp_x][tmp_y] == seen){
                d += 1;
            }
            d %= 4;
            x = x + direction[d][0];
            y = y + direction[d][1];
            count++;
        }
        return results;
    }
};