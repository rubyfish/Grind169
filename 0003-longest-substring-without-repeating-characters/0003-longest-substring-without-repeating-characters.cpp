class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_map<char, int> map;
        int start_index = 0;

        for (int i = 0; i < s.size(); i++){
            char ch = s[i];
            map[ch]++;
            
            while(map[ch] != 1){
                map[s[start_index]]--;
                start_index += 1;
            }

            max_length = std::max(max_length, i - start_index + 1);
        }

        return max_length;
    }
};