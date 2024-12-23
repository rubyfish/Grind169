class Solution {
public:
    bool isPalindrome(string s) {
        std::string new_s;
        for(char ch:s){
            //check if ch is upper case letter
            if (ch <= 'Z' && ch >= 'A'){
                new_s += (ch-'A'+'a');
            }
            //check if ch is lower case letter or number
            else if ((ch <= 'z' && ch >= 'a')||(ch <= '9' && ch >= '0')){
                new_s += ch;
            }
        }

        int left = 0;
        int right = new_s.size()-1;

        while(left<right){
            if (new_s[left]!=new_s[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};