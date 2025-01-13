class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::unordered_set<int> raw;
        std::unordered_set<int> col;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    raw.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for (int i = 0; i < m; i++){
            if (raw.count(i)){
                for (int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; j++){
            if (col.count(j)){
                for (int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};