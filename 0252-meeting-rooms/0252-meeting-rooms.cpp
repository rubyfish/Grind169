class Solution {
public:
    static bool sortVector(vector<int>& a, vector<int>& b){
        return a[0] <= b[0] && a[1] <= b[1];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return true;
        std::sort(intervals.begin(), intervals.end(), sortVector);

        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] < prev_end)
                return false;
            prev_end = std::max(prev_end, intervals[i][1]);
        }

        return true;
    }
};