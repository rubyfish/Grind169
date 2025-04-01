class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p0 = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;

        while (p0 >= 0){
            int tmp = 0;
            if (p1 < 0 || (p2 >= 0 && nums1[p1] < nums2[p2])){
                tmp = nums2[p2];
                p2--;
            }
            else {
                tmp = nums1[p1];
                p1--;
            }
            nums1[p0] = tmp;
            p0--;
        }
    }
};