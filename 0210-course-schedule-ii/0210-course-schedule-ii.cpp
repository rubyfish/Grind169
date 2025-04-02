class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> results;
        std::queue<int> q;

        for (vector<int> prerequisite:prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()){
            int course = q.front();
            results.push_back(course);
            q.pop();

            for (int node:adj[course]){
                indegree[node]--;
                if (indegree[node] == 0)
                    q.push(node);
            }
        }

        if (results.size() == numCourses)
            return results;

        return std::vector<int>();
    }
};