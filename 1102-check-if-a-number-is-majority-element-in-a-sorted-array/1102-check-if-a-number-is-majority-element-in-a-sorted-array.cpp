class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while (left <= right){
            int mid = (right - left)/2 + left;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
                index = mid;
            }
        }

        if (index == -1 || index + nums.size()/2 > nums.size() - 1)
            return false;
        return nums[index + nums.size()/2] == target;
    }
};