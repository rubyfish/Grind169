class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        int semester = 1;
        vector<int> order;
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        queue<pair<int, int>> q;

        for(vector<int> relation:relations){
            graph[relation[0] - 1].push_back(relation[1] - 1);
            indegree[relation[1] - 1]++;
        }

        for (int i = 0; i < n; i++){
            if (indegree[i] == 0)
                q.push({i, semester});
        }

        while (!q.empty()){
            pair<int,int> coursePair = q.front();
            int course = coursePair.first;
            semester = coursePair.second;
            order.push_back(course + 1);
            q.pop();

            for (int node:graph[course]){
                indegree[node]--;
                if (indegree[node] == 0)
                    q.push({node, semester+1});
            }
        }

        if (order.size() == n)
            return semester;
        return -1;
    }
};