class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1) return s;
        int n=s.length();
        string ans="";

        // First and last row each have jumps of 2*(numRows-1) between the characters of string i.e. P...A...H...N
        // the rows in between have have more character between each column and they are at a jump of (i+inc - 2*r)

        for(int r=0; r<numRows; r++){
            int inc = 2*(numRows-1);
            for(int i=r; i<n ; i+=inc){
                ans += s[i];
                if(r>0 && r<numRows-1 && (i+inc - 2*r)<n){
                    ans += s[i+inc-2*r];
                }
            }
        }

        return ans;
    }
};