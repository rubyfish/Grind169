class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index_nonzero = 0;
        int N = nums.size();

        for (int i = 0; i < N; i++){
            if (nums[i] != 0){
                nums[index_nonzero++] = nums[i];
            }
        }

        for(int i = index_nonzero; i < N; i++){
            nums[i] = 0;
        }
    }
};