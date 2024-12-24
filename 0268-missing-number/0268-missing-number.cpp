class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        for(int i = 0; i<=size; i++){
            res+=i;
            if (i!=size)
                res-=nums[i];
        }
        return res;
    }
};