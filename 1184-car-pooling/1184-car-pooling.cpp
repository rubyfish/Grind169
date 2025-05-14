class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> count_passengers;

        for (auto trip:trips){
            count_passengers[trip[1]] += trip[0];
            count_passengers[trip[2]] -= trip[0];
        }

        int current_passengers = 0;
        for (auto it = count_passengers.begin(); it != count_passengers.end(); ++it){
            current_passengers += it->second;
            if (current_passengers > capacity)
                return false;
        }

        return true;
    }
};