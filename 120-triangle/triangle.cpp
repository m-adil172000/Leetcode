class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>prev(triangle[n-1].size(),0);

        for(int i=0; i<triangle[n-1].size(); i++) prev[i] = triangle[n-1][i];

        for(int i=n-2; i>=0; i--){
            vector<int>curr(i+1,0);
            for(int j=i; j>=0; j--){
                long long down=INT_MAX, diagonal = INT_MAX;

                down = triangle[i][j]+prev[j];
                diagonal = triangle[i][j] + prev[j+1];

                curr[j] = min(down,diagonal);
            }
            prev= curr;

        }

        return prev[0];
    }
};