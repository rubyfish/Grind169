class Solution {
public:
    static bool sortIntervals(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), sortIntervals);
        int count = 0;
        int end = intervals[0][1];

        for(int i = 1; i<intervals.size(); i++){
            if (intervals[i][0] < end){
                count++;
            }
            else{
                end = intervals[i][1];
            }
        }

        return count;
    }
};