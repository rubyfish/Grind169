class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0;
        int n = neededTime.size();
        int min_cost = 0;

        while (i < n-1){
            if (colors[i] == colors[i+1]){
                if (neededTime[i] < neededTime[i+1]){
                    min_cost += neededTime[i];
                }
                else{
                    min_cost += neededTime[i+1];
                    neededTime[i+1] = neededTime[i];
                }
                    
            }
            i++;
        }

        return min_cost;
    }
};