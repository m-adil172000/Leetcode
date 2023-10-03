class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(n<=m){
            int rs=0, re = n-1;
            for(int i=rs; i<=re; i++){
                int l = 0, r = m-1;

                while(l<=r){
                    int m = l + (r-l)/2;
                    if(matrix[i][m]==target) return true;
                    else if(matrix[i][m]>target){
                        r= m-1;
                    }
                    else l = m+1;
                }
            }
        }
        else{
            int cs =0, ce=m-1;
            for(int i=cs; i<=ce; i++){
                int l = 0, r = n-1;

                while(l<=r){
                    int m = l + (r-l)/2;
                    if(matrix[m][i]==target) return true;
                    else if(matrix[m][i]>target){
                        r = m-1;
                    }
                    else l = m+1;
                }
            }
        }

        return false;
    }
};