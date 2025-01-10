class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int mid_x = mid / n;
            int mid_y = mid % n;
            int mid_val = matrix[mid_x][mid_y];

            if (mid_val == target)
                return true;
            else if (mid_val > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
};