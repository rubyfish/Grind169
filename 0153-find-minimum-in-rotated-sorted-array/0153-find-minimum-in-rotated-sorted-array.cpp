class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        if (nums[left] > nums[right])
            return nums[right];
        return nums[left];
    }
};