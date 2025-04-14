class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n_size = nums.size();

        if (n_size == 1)
            return true;

        int target_index = n_size - 1;
        
        for (int i = n_size - 2; i >= 0; i--){
            if (target_index - i <= nums[i])
                target_index = i;
            if (target_index == 0)
                return true;
        }

        return false;
    }
};