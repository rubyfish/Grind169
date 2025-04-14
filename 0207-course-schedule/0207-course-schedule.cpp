class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> relations(numCourses);
        vector<int> order;
        queue<int> q;

        for (vector<int> prerequisite:prerequisites){
            relations[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()){
            int cur_course = q.front();
            q.pop();
            order.push_back(cur_course);

            for (int course:relations[cur_course]){
                indegree[course]--;
                if (indegree[course] == 0)
                    q.push(course);
            }
        }

        return order.size() == numCourses ? true:false;
    }
};