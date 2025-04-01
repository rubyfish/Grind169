class Solution {
public:
    int climbStairs(int n) {
        int n0 = 1;
        int n1 = 1;

        while (n > 1){
            int n2 = n0 + n1;
            n0 = n1;
            n1 = n2;
            n--;
        }

        return n1;
    }
};