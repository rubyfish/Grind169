class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        std::sort(intervals.begin(), intervals.end());

        for (auto interval : intervals){
            if (results.empty()){
                results.push_back(interval);
                continue;
            }

            if (interval[0] <= results.back()[1]){
                results.back()[1] = std::max(interval[1], results.back()[1]);
            }
            else
                results.push_back(interval);
        }

        return results;
    }
};