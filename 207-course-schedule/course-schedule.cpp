class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int>indegree(numCourses,0);
        for(int i=0; i<n; i++){
            indegree[prerequisites[i][0]]++;
        }

        queue<int>q;
        int cnt=0;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(q.size()>0){
            int node = q.front();
            q.pop();
            cnt++;

            for(int i=0;i<n; i++){
                if(prerequisites[i][1]==node){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]]==0) q.push(prerequisites[i][0]);
                }
            }
        }

        return cnt==numCourses;

    }
};