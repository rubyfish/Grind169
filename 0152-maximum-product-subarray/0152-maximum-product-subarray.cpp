class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int max_num = nums[0];
        int min_num = nums[0];

        for(int i = 1; i<nums.size(); i++){
            int cur = nums[i];
            int tmp_max = std::max(cur*max_num, cur*min_num);
            int tmp_min = std::min(cur*max_num, cur*min_num);

            max_num = std::max(cur, tmp_max);
            min_num = std::min(cur, tmp_min);

            result = std::max(result, max_num);
        }

        return result;
    }
};