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
    TreeNode* build(vector<int>&nums, int start, int end){
        if(start>end) return NULL;

        int mxidx=0, mxval=INT_MIN;
        for(int i=start; i<=end; i++){
            if(nums[i]>mxval){
                mxval = nums[i];
                mxidx = i;
            }
        }

        TreeNode*root = new TreeNode(mxval);
        root->left = build(nums, start, mxidx-1);
        root->right = build(nums, mxidx+1,end);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        int n =nums.size();
        if(n==0) return NULL;
        return build(nums,0,n-1);
    }
};