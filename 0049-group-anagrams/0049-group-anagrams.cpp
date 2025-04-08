class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //count characters for each string
        std::vector<std::vector<std::string>> results;
        std::unordered_map<std::string, int> mappings;
        int index = 0;

        for (std::string str:strs){
            std::unordered_map<char, int> map_count_ch;
            for(char ch:str) map_count_ch[ch]++;
            std::string key = std::string();
            for (int i = 0; i < 26; i++){
                char ch = 'a' + i;
                key += ch + std::to_string(map_count_ch[ch]);
            }

            if (!mappings.count(key)){
                results.push_back(std::vector<std::string>());
                mappings[key] = index;
                index++;
            }
            results[mappings[key]].push_back(str);
        }

        return results;
    }
};