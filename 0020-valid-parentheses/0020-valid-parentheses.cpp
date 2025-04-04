class Solution {
public:
    std::unordered_map<char, char> map{{'(', ')'},{'{','}'},{'[',']'}};
    bool isValid(string s) {
        std::stack<char> stk;

        for (char ch:s){
            // input is (, {, [ , then add ch to stack
            if (map.count(ch))
                stk.push(ch);
            
            // input is ), }, ] , then check the top of stack
            // if stack is empty, return false
            else if (stk.empty())
                return false;
            else{
                char top = stk.top();
                if (map[top] == ch)
                    stk.pop();
                else
                    return false;
            }
        }

        if (stk.empty())
            return true;
        return false;
    }
};