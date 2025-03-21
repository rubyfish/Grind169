class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size);
        vector<int> right(size);
        vector<int> output(size);

        left[0] = 1;
        right[size-1] = 1;

        for(int i = 1; i<size; i++){
            left[i] = left[i-1]*nums[i-1];
            right[size-1-i] = right[size-i]*nums[size-i];
        }

        for(int i = 0; i<size; i++){
            output[i] = left[i]*right[i];
        }

        return output;
    }
};