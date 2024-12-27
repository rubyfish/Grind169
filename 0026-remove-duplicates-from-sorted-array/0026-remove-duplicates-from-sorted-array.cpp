class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int cur = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if (nums[i]>cur){
                nums[count]=nums[i];
                cur=nums[i];
                count++;
            }
        }
        return count;
    }
};