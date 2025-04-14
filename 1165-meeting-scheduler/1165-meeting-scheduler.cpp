class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());

        int p1 = 0;
        int p2 = 0;

        while (p1 < slots1.size() && p2 <slots2.size()){
            int start = max(slots1[p1][0], slots2[p2][0]);
            int end = min(slots1[p1][1], slots2[p2][1]);

            if (end - start >= duration){
                return {start, start + duration};
            }

            if (slots1[p1][1] > slots2[p2][1])
                p2++;
            else
                p1++;
        }

        return {};
    }
};