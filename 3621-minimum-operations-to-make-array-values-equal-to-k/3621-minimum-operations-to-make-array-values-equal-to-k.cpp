class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> seen;
        for (int n:nums){
            if (n < k)
                return -1;
            if (n != k)
                seen.insert(n);
        }

        return seen.size();
    }
};