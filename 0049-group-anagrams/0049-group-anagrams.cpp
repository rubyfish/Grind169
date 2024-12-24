class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, int> map;
        std::vector<std::vector<std::string>> results;
        int count = 0;
        for(std::string s:strs){
            std::string ori_s = s;
            std::sort(s.begin(), s.end());
            //If map contain sort string
            //Add original string to mapping index
            if(map.count(s)){
                results[map[s]].push_back(ori_s);
            }
            //If map doesn't contain sort string
            //Add original string to the end of results and add mapping index
            else{
                map[s] = count;
                count++;
                results.push_back({ori_s});
            }
        }
        return results;
    }
};