class Solution {
public:
    void dfs(int open, int close, int n, vector<string>& results, string current){
        if (open == close && open == n){
            results.push_back(current);
            return;
        }

        if (open < n){
            dfs(open + 1, close, n, results, current + "(");
        }

        if (close < open){
            dfs(open, close + 1, n, results, current + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;

        dfs(0, 0, n, results, std::string());
        return results;
    }
};