class Solution {
public:
    int n;
    int k;

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<vector<int>> results;
        vector<int> curr;

        loopNumber(1, curr, results);

        return results;
    }

    void loopNumber(int start_index, vector<int>& curr,
                    vector<vector<int>>& results) {
        std::cout<<std::endl;
        if (curr.size() == this->k) {
            results.push_back(curr);
            return;
        }

        for (int i = start_index; i <= this->n; i++){
            curr.push_back(i);
            loopNumber(i+1, curr, results);
            curr.pop_back();
        }
    }
};