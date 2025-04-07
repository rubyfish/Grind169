class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        std::vector<unordered_set<int>> relations(n);
        std::unordered_set<int> seen;
        //sorting logs
        std::sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        for (vector<int> log:logs){
            int time = log[0];
            int personA = log[1];
            int personB = log[2];

            relations[personA].insert(personB);
            relations[personB].insert(personA);

            //check relations
            seen.clear();
            queue<int> q;
            q.push(personA);
            while(!q.empty()){
                int currPerson = q.front();
                q.pop();
                seen.insert(currPerson);

                for(int person:relations[currPerson]){
                    if (seen.count(person))
                        continue;
                    q.push(person);
                }
            }

            if (seen.size() == n)
                return time;
        }

        return -1;
    }
};