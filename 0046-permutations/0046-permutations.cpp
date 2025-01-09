class Solution {
public:
    int n = 0;
    vector<int> nums;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> seen;
        vector<vector<int>> results;
        this->nums = nums;
        this->n = nums.size();

        for (int num : nums) {
            seen[num] = false;
        }
        loopNumbers(results, {}, seen);
        return results;
    }

    void loopNumbers(vector<vector<int>>& results, vector<int> curr,
                     unordered_map<int, bool> seen) {
        if (curr.size() == this->n) {
            results.push_back(curr);
            return;
        }

        for (int i = 0; i < this->n; i++) {
            int num = this->nums[i];
            if (seen[num])
                continue;
            curr.push_back(num);
            seen[num] = true;
            loopNumbers(results, curr, seen);
            curr.pop_back();
            seen[num] = false;
        }
    }
};