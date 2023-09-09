void bktr(string digits, unordered_map<char,string>mp, vector<string>&ans, string curr, int s){
        if(curr.length()==digits.length()){
            ans.push_back(curr);
            return;
        }

        string si = mp[digits[s]];
        for(int i=0; i<si.length(); i++){
            curr += si[i];
            bktr(digits, mp, ans, curr, s+1);
            curr.pop_back();
        }
    }

class Solution {
public:

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc", mp['3']="def", mp['4']="ghi", mp['5']="jkl", mp['6']="mno", mp['7']="pqrs", mp['8']="tuv",mp['9']="wxyz";

        vector<string>ans;
        int n = digits.length();
        if(n==0) return ans;
        string curr="";

        bktr(digits, mp, ans,curr , 0);

        return ans;
        

    }
};