class Solution {
public:
    vector<vector<int>> twoSum(vector<int>&nums, int start_index, int target){
        std::unordered_set<int> set;
        vector<vector<int>> results;

        for(int i = start_index; i < nums.size(); i++){
            int tmp_target = target - nums[i];
            if (set.count(tmp_target)){
                results.push_back({tmp_target, nums[i]});

                while(i+1 < nums.size() && nums[i+1] == nums[i]){
                    i++;
                }
            }
            set.insert(nums[i]);
        }

        return results;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            vector<vector<int>> twosum_res = twoSum(nums, i + 1, target);

            for (vector<int> tmp_vec:twosum_res){
                results.push_back({nums[i], tmp_vec[0], tmp_vec[1]});
            }
        }

        return results;    
    }
};