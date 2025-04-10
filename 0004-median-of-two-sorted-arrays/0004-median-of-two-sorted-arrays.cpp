class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> target_index;

        if ((len1+len2)%2 == 1){
            target_index.push_back((len1+len2)/2);
        }
        else{
            target_index.push_back((len1+len2)/2 - 1);
            target_index.push_back((len1+len2)/2);
        }

        int p1 = 0;
        int p2 = 0;
        int pt = 0;

        while (p1+p2 < len1+len2 && pt < target_index.size()){
            int tmp = 0;
            if (p1 >= len1 || (p2 < len2 && nums1[p1] > nums2[p2])){
                tmp = nums2[p2];
                p2++;
            }
            else{
                tmp = nums1[p1];
                p1++;
            }

            if (p1+p2-1 == target_index[pt]){
                target_index[pt] = tmp;
                pt++;
            }
        }

        float result = 0;
        for (int target:target_index){
            result += target;
        }

        result /= target_index.size();
        return result;
    }
};