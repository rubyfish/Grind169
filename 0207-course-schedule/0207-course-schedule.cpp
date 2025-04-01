class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> order;
        queue<int> q;

        for (vector<int> prereq:prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
            indegree[prereq[1]]++;
        }

        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            order.push_back(course);
            q.pop();

            for (int neighbor : adj[course]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return order.size() == numCourses;
    }
};