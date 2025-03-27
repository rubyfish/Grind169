//Solve the problem with sorting array
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int num_len = nums.size();
        if (num_len <= 1)
            return num_len;
        vector<int> input(nums.begin(), nums.end());
        std::sort(input.begin(), input.end());
        int max_len = 1;
        int cur_len = 1;
        int cur_num = input[0];

        for (int i = 1; i < num_len; i++){
            if (input[i] == cur_num+1)
                cur_len += 1;
            else if (input[i] == cur_num)
                continue;
            else{
                max_len = std::max(max_len, cur_len);
                cur_len = 1;
            }
            cur_num = input[i];
        }
        max_len = std::max(max_len, cur_len);

        return max_len;
    }
};

//Solve the problem without sorting the input array
/*class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        unordered_set<int> seen;
        int max_len = 0;

        for (int n:nums){
            //skip already process number
            if (num_set.count(n - 1)||seen.count(n))
                continue;

            int cur_len = 1;
            while(num_set.count(n+cur_len)){
                cur_len += 1;
            }
            max_len = max(max_len, cur_len);
            seen.insert(n);
        }

        return max_len;
    }
};*/