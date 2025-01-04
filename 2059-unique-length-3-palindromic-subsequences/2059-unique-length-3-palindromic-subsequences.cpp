class Solution {
public:
    int countPalindromicSubsequence(string s) {
        std::unordered_set<char> seen;
        int n = s.size();
        int answer = 0;

        for (int i = 0; i < n; i++){
            int j = 0;
            bool found = false;
            for (j = n-1; j >= 0; j--){
                if (i != j && s[i] == s[j]){
                    found = true;
                    break;
                }
                else if (i >= j){
                    break;
                }
            }

            if (found && !seen.count(s[i])){
                std::unordered_set<char> between;
                for(int k = i+1; k < j; k++){
                    between.insert(s[k]);
                }
                answer += between.size();
                seen.insert(s[i]);
            }
        }

        return answer;
    }
};