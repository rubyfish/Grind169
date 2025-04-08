class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //use input vector as hashmap
        //convert negative and number>nums.size() to 1
        //iterative all value, if value x exists, turn index-1 to negative
        //iterative all value, if current value is positive, return its index+1
        int n_size = nums.size();
        bool has_one = false;
        for (int i = 0; i < n_size; i++){
            if (nums[i] <= 0 || nums[i] > n_size){
                nums[i] = 1;
            }
            else if (nums[i] == 1){
                has_one = true;
            }
        }
        
        for (int i = 0; i < n_size; i++){
            //remember to turn current number to positive
            int curr_n = abs(nums[i]);
            if (curr_n == 1 && has_one == false)
                continue;
               
            if (nums[curr_n - 1] > 0)
                nums[curr_n - 1] *= -1;
        }
        
        for (int i = 0; i < n_size; i++){
            if (nums[i] > 0){
                return i + 1;
            }
        }
        
        return n_size + 1;
    }
};