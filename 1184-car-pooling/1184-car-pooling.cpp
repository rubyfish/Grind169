class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> count_passengers(1001, 0);

        for (auto trip:trips){
            count_passengers[trip[1]] += trip[0];
            count_passengers[trip[2]] -= trip[0];
        }

        int current_passengers = 0;
        for (int count:count_passengers){
            current_passengers += count;
            if (current_passengers > capacity)
                return false;
        }

        return true;
    }
};