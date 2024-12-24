class Solution {
public:
    string minWindow(string s, string t) {
        // If s is short than t, it can't contain all character in t
        if (s.length() < t.length())
            return std::string();

        int l = 0;
        int r = 0;
        int count = 0;
        int res_len = -1;
        int res_start_index = 0;
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for(char ch:t){
            t_map[ch]++;
        }

        while(r<s.length()){
            s_map[s[r]]++;
            if (t_map.contains(s[r]) && t_map[s[r]] >= s_map[s[r]])
                count++;
            
            while(count == t.length()){
                if (res_len == -1 || res_len > r-l+1){
                    res_len = r-l+1;
                    res_start_index = l;
                }
                s_map[s[l]]--;
                if (t_map.contains(s[l]) && t_map[s[l]] > s_map[s[l]])
                    count--;
                l++;
            }
            r++;
        }
        return res_len==-1?std::string():s.substr(res_start_index, res_len);
    }
};