class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int pre_min = nums[0];
        int pre_max = nums[0];

        for (int i = 1; i < nums.size(); i++){
            int cur = nums[i];
            int cur_min = std::min(cur, std::min(cur*pre_min, cur*pre_max));
            int cur_max = std::max(cur, std::max(cur*pre_min, cur*pre_max));
            result = std::max(result, cur_max);
            pre_min = cur_min;
            pre_max = cur_max;
        }

        return result;
    }
};