class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        std::string result = std::string();
        
        for (int i = 0; i < std::max(m, n); i++){
            if (i < m)
                result += word1[i];
            if (i < n)
                result += word2[i];
        }

        return result;
    }
};