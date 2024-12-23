class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
            return false;

        unordered_map<char, int> map;
        for(char ch:s){
            map[ch]++;
        }

        for(char ch:t){
            if (!map.count(ch) || map[ch]==0){
                return false;
            }
            map[ch]--;
        }
        return true;
    }
};