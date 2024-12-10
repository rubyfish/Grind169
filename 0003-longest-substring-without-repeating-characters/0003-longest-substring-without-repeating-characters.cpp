class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num_size = s.length();
        if (num_size == 0){
            return 0;
        }

        unordered_map<char, int> map;
        int start_index = 0;
        int end_index = 0;
        int max_size = 0;

        while(end_index < num_size){
            map[s[end_index]]++;

            while (map[s[end_index]] > 1){
                map[s[start_index]]--;
                start_index++;
            }

            max_size = std::max(max_size, end_index - start_index + 1);
            end_index++;
        }

        return max_size;
    }
};