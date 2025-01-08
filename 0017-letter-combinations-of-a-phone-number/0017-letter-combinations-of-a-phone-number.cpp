class Solution {
public:
    unordered_map<char, vector<char>> map;
    vector<string> letterCombinations(string digits) {
        int count_letter = 0;
        for (int i = 2; i <= 9; i++){
            vector<char> letters;
            int tmp = 3;
            if (i == 7 || i == 9) {
                tmp = 4;
            }
            for (int j = 0; j < tmp; j++) {
                letters.push_back('a'+count_letter);
                count_letter++;
            }
            this->map[i+'0'] = letters;
        }

        vector<string> results;
        loopLetters(results, "", digits, 0);
        return results;
    }

    void loopLetters(vector<string>& results, string curr, string digits, int index) {
        if (digits.size() == 0)
            return;
        if (curr.size() == digits.size()) {
            results.push_back(curr);
            return;
        }
        
        vector<char> letters = this->map[digits[index]];
        for (int i = 0; i < letters.size(); i++) {
            curr += letters[i];
            loopLetters(results, curr, digits, index+1);
            curr.pop_back();    
        }
    }
};