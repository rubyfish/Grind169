class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> map;
        for(char ch:magazine){
            map[ch]++;
        }
        
        for(char ch:ransomNote){
            if(!map.count(ch)||map[ch]==0)
                return false;
            map[ch]--;
        }
        return true;
    }
};