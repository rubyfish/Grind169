class Solution {
public:
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& results){
        std::unordered_set<int> set;
        for (int j = i+1; j<nums.size(); j++){
            int target = -nums[i]-nums[j];

            if (set.count(target)){
                results.push_back({nums[i],nums[j],target});

                while (j+1<nums.size() && nums[j] == nums[j+1]){
                    j++;
                }
            }

            set.insert(nums[j]);
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> results;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            //since the array has been sorted, we can't find threesum equal to zero if first number is larger than zero
            if (nums[i]>0)
                break;
            if (i==0 || nums[i]!=nums[i-1]){
                twoSum(nums, i, results);
            }
        }

        return results;
    }
};