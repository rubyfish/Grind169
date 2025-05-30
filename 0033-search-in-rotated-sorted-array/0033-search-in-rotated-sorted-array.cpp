class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = (right - left)/2 + left;
            int n = nums[mid];

            if (n == target)
                return mid;
            else if (nums[left] <= n){
                if (nums[left] <= target && target < n){
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            else{
                if (n < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};