class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min_positive = INT_MAX;
        bool has_one = false;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] <= 0){
                nums[i] = 1;
            }
            else if (nums[i] == 1){
                has_one = true;
            }
        }

        for (int i = 0; i < nums.size(); i++){
            bool flag = false;
            int target_index = abs(nums[i])-1;
            if (target_index < nums.size()){
                if (target_index == 0 && has_one){
                    flag = true;
                }
                else if (target_index != 0){
                    flag = true;
                }
            }
            if (flag){
                if (nums[target_index] > 0){
                    nums[target_index]*=-1;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                return i+1;
            }
        }

        return nums.size()+1;
    }
};