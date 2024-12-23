class Solution {
public:
    char alphabetToLower(char ch){
        if (ch <= 'Z' && ch >= 'A'){
            return (ch-'A'+'a');
        }

        return ch;
    }
    bool isAlphaberOrNum(char ch){
        if ((ch <= 'z' && ch >= 'a')||
            (ch <= '9' && ch >= '0')||
            (ch <= 'Z' && ch >= 'A')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left<right){
            while (left<right && !isAlphaberOrNum(s[left])) left++;
            while (left<right && !isAlphaberOrNum(s[right])) right--;

            if (alphabetToLower(s[left])!=alphabetToLower(s[right])){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};