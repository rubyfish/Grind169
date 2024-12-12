class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> stack_temp;
        vector<int> result(size);

        for(int i = size-1; i >= 0; i--){
            while(!stack_temp.empty()){
                if (temperatures[stack_temp.top()] > temperatures[i]){
                    result[i] = stack_temp.top() - i;
                    break;
                }
                else{
                    stack_temp.pop();
                }
            }
            stack_temp.push(i);
        }
        return result;
    }
};