class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int cur = result;

        for(int i = 1; i<nums.size(); i++){
            int tmp = cur+nums[i];
            if (tmp < nums[i]){
                cur = nums[i];
            }
            else{
                cur = tmp;
            }

            if (result<cur){
                result = cur;
            }
        }

        return result;
    }
};