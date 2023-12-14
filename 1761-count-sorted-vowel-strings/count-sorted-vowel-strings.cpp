class Solution {

public:
    int countVowelStrings(int n) {
        vector<int>prev(5,1);
        vector<int>curr(5,1);

        for(int i=1; i<=n; i++){
            for(int j=3; j>=0; j--){
                curr[j] = curr[j+1]+prev[j];
            }
            prev = curr;
        }

        return prev[0];
    }
};