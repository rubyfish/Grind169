class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        if (s_len < t_len)
            return std::string();
        
        int left = 0;
        int right = 0;
        int count = 0;
        int res_start_index = 0;
        int res_len = -1;
        std::unordered_map<char, int> t_map;
        std::unordered_map<char, int> s_map;

        for(char ch:t){
            t_map[ch]++;
        }

        while(right < s_len){
            s_map[s[right]]++;
            if (t_map.count(s[right]) && t_map[s[right]] >= s_map[s[right]]){
                count++;
            }

            while(count == t_len){
                if (res_len == -1 || right-left+1 < res_len){
                    res_start_index = left;
                    res_len = right-left+1;
                }
                s_map[s[left]]--;
                if (t_map.count(s[left]) && t_map[s[left]] > s_map[s[left]]){
                    count--;
                }
                left++;
            }
            right++;
        }
        return res_len == -1?std::string():s.substr(res_start_index, res_len);
    }
};