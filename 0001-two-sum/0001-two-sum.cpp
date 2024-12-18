class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> results;

        for(int i = 0; i<nums.size(); i++){
            int tmp = target - nums[i];
            if (map.count(tmp)){
                results.push_back(map[tmp]);
                results.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }

        return results;
    }
};