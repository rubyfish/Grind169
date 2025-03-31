class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len <= 1)
            return len;
        
        int p1 = 0;
        int p2 = 0;
        int max_len = 0;
        unordered_map<int, int> map;

        for (char ch:s){
            map[ch]++;

            while(map[ch]>1){
                map[s[p1]]--;
                p1++;
            }
            
            max_len = max(max_len, p2-p1+1);
            p2++;
        }
        return max_len;
    }
};