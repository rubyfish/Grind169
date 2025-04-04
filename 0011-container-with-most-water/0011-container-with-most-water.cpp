class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;

        while(left < right){
            int tmp_area = std::min(height[left], height[right]) * (right - left);
            area = std::max(area, tmp_area);

            if (height[left] > height[right])
                right--;
            else
                left++;
        }

        return area;
    }
};