class Solution {
public:
    static bool compareMap(std::unordered_map<char, int> map_s,
                           std::unordered_map<char, int> map_p){
        for (auto it:map_p){
            if (!map_s.count(it.first)||
                map_s[it.first]!=it.second){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int size_p = p.size();
        int size_s = s.size();
        std::vector<int> res;

        if (size_s < size_p)
            return res;

        std::unordered_map<char, int> map_p;
        std::unordered_map<char, int> map_s;
        for(char ch:p){
            map_p[ch]++;
        }

        int head = 0;
        int size = size_s - size_p;

        while(head <= size){
            if (head == 0){
                for(int i=0; i<size_p; i++){
                    map_s[s[i]]++;
                }
            }
            else{
                char c_remove = s[head-1];
                char c_add = s[head+size_p-1];
                map_s[c_remove]--;
                map_s[c_add]++;

                if (!map_p.count(c_add)){
                    head++;
                    continue;
                }
            }
            if (compareMap(map_s, map_p)){
                res.push_back(head);
            }

            head++;
        }

        return res;
    }
};