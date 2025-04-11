class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int i = low; i <= high; i++){
            if (i < 100 && i % 11 == 0)
                count++;
            else if (i > 999 && i < 10000){
                int left = i / 1000 + i % 1000 / 100;
                int right = i % 100 / 10 + i % 10;
                if (left == right)
                    count++;
            }
        }

        return count;
    }
};