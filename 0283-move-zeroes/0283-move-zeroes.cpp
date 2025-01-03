class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;

        while (p2 < nums.size() && p1 < nums.size()) {
            if (nums[p2] == 0) {
                p2++;
            } 
            else if (nums[p1] != 0) {
                p1++;
            } 
            else if (p1 > p2) {
                p2++;
            } 
            else {
                std::swap(nums[p1], nums[p2]);
                p1++;
                p2++;
            }
        }
    }
};