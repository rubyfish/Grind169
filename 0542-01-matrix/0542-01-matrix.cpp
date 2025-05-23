class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int max_value = m*n;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0)
                    continue;
                int up = max_value;
                int left = max_value;

                if (i-1 >= 0)
                    left = mat[i-1][j];
                if (j-1 >= 0)
                    up = mat[i][j-1];
                mat[i][j] = std::min(left, up) + 1;
            }
        }

        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                if (mat[i][j] == 0)
                    continue;
                int down = max_value;
                int right = max_value;

                if (i+1 < m)
                    down = mat[i+1][j];
                if (j+1 < n)
                    right = mat[i][j+1];
                mat[i][j] = std::min(mat[i][j], std::min(down, right) + 1);
            }
        }

        return mat;
    }
};