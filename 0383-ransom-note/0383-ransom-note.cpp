class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;

        std::unordered_map<char, int> mappings;

        for (char ch:magazine){
            mappings[ch]++;
        }

        for (char ch:ransomNote){
            mappings[ch]--;
            if (mappings[ch] < 0)
                return false;
        }

        return true;
    }
};