class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> relations(numCourses);
        vector<int> indegree(numCourses);
        vector<int> courseOrder;
        queue<int> q;

        for(vector<int> prerequisite:prerequisites){
            relations[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()){
            int curCourse = q.front();
            q.pop();
            courseOrder.push_back(curCourse);

            for (int course:relations[curCourse]){
                indegree[course]--;
                if (indegree[course] == 0)
                    q.push(course);
            }
        }

        return courseOrder.size() == numCourses;
    }
};