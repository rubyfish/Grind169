class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right){
            max_area = std::max(max_area, (right - left) * std::min(height[right], height[left]));
            if (height[right] > height[left])
                left++;
            else
                right--;
        }

        return max_area;
    }
};