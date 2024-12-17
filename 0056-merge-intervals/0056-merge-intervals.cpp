class Solution {
public:
    static bool compare(vector<int> a, vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;

        std::sort(intervals.begin(), intervals.end(), compare);

        for (vector<int> interval : intervals){
            if (results.empty()||results.back()[1] < interval[0]){
                results.push_back(interval);
            }
            else{
                results.back()[1] = max(results.back()[1], interval[1]);
            }
        }

        return results;
    }
};