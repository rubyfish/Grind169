class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low_p = prices[0];
        int profit = 0;

        for (int p:prices){
            if (p<low_p){
                low_p = p;
            }
            else if(p-low_p > profit){
                profit = p-low_p;
            }
        }

        return profit;
    }
};