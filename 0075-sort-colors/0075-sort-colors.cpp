class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int cur = 0;
        int end = nums.size()-1;

        while(cur <= end){
            if (nums[cur]==0){
                swap(nums[start], nums[cur]);
                start++;
                cur++;
            }
            else if (nums[cur]==2){
                swap(nums[cur], nums[end]);
                end--;
            }
            else{
                cur++;
            }
        }
    }
};