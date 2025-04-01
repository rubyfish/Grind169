class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0)
            return std::string();
        if (len == 1)
            return strs[0];
        
        std::string pattern = strs[0];
        for (int i = 1; i < len; i++){
            std::string new_pattern = std::string();
            std::string cur = strs[i];
            int str_len = std::min(pattern.size(), cur.size());
            
            for (int j = 0; j < str_len; j++){
                if (pattern[j] != cur[j])
                    break;
                new_pattern += pattern[j];
            }

            pattern = new_pattern;
        }

        return pattern;
    }
};