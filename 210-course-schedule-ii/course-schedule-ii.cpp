class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        int n = prerequisites.size();
        if(n==0){
            for(int i=0; i<numCourses; i++) ans.push_back(i);
            return ans;
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            indegree[prerequisites[i][0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i=0; i<n; i++){
                if(prerequisites[i][1]==node){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]]==0){
                        q.push(prerequisites[i][0]);
                    }
                }
                
            }
        }
        vector<int>empty;

        if(ans.size()==numCourses){
            return ans;
        }
        else return empty;
    }
};