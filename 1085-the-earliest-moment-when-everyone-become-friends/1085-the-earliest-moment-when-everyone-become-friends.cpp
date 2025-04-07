class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        std::vector<unordered_set<int>> relations(n);
        //sorting logs
        std::sort(logs.begin(), logs.end());

        for (vector<int> log:logs){
            int time = log[0];
            int personA = log[1];
            int personB = log[2];

            relations[personA].insert(personB);
            relations[personB].insert(personA);

            //check relations
            unordered_set<int> seen;
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