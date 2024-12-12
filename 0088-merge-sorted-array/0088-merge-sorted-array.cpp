class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int cur_p = m+n-1;

        while(cur_p >= 0){
            if (p1 < 0){
                nums1[cur_p] = nums2[p2];
                p2--;
            }
            else if (p2 < 0){
                break;
            }
            else if (nums1[p1] >= nums2[p2]){
                swap(nums1[cur_p], nums1[p1]);
                p1--;
            }
            else{
                swap(nums1[cur_p], nums2[p2]);
                p2--;
            }
            cur_p--;
        }
    }
};