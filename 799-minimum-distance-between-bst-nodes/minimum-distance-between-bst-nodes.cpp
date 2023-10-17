/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void traverse(TreeNode*root, vector<int>&ans){
        if(root!=NULL) ans.push_back(root->val);
        if(root->left)traverse(root->left, ans);
        if(root->right)traverse(root->right, ans);
    }
public:
    int minDiffInBST(TreeNode* root) {
        
        vector<int>ans;
        traverse(root,ans);
        sort(ans.begin(),ans.end());
        int res = INT_MAX;
        int n =  ans.size();
        for(int i=1; i<n; i++){
            res = min(res, ans[i]-ans[i-1]);
        }
        return res;
    }
};