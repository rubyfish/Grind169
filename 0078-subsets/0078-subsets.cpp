class Solution {
public:
    vector<int> nums;
    int n;

    vector<vector<int>> subsets(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        vector<int> curr;
        vector<vector<int>> results;

        loopNumbers(0, curr, results);

        return results;
    }

    void loopNumbers(int start_index, vector<int> curr, vector<vector<int>>& results){
        results.push_back(curr);
        
        if (curr.size() == this->n)
            return;

        for (int i = start_index; i < n; i++){
            curr.push_back(this->nums[i]);
            loopNumbers(i+1, curr, results);
            curr.pop_back();
        }
    }
};