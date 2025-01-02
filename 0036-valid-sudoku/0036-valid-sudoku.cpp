class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = 9;
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> groups[9];

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                char ch = board[i][j];
                
                if (ch == '.'){
                    continue;
                }

                if (rows[i].count(ch)){
                    return false;
                }
                rows[i].insert(ch);

                if (cols[j].count(ch)){
                    return false;
                }
                cols[j].insert(ch);

                int g = (i/3)*3+(j/3);
                if (groups[g].count(ch)){
                    return false;
                }
                groups[g].insert(ch);
            }
        }
        return true;
    }
};