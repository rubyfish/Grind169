class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        unordered_set<int> seen;
        int max_len = 0;

        for (int n:nums){
            //skip already process number
            if (num_set.count(n - 1)||seen.count(n))
                continue;

            int cur_len = 1;
            while(num_set.count(n+cur_len)){
                cur_len += 1;
            }
            max_len = max(max_len, cur_len);
            seen.insert(n);
        }

        return max_len;
    }
};