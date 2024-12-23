class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0;
        int tail = 0;
        int res = 0;
        std::unordered_map<char, int> map;

        for(char ch:s){
            map[ch]++;
            tail++;
            
            while(map[ch]>1){
                map[s[head]]--;
                head++;
            }

            res = std::max(tail-head, res);
        }

        return res;
    }
};