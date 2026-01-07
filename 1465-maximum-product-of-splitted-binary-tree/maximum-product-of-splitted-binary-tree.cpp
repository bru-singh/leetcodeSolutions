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
public:
    int mod = 1e9+7;
    long long total;
    long long solve(TreeNode* root, long long& ans){
        if(!root)return 0;
        // for current subtree: 
        long long leftSum = solve(root->left, ans);
        long long rightSum = solve(root->right, ans);
        // ((total-leftSum)*leftSum)%mod;
        // ((total-rightSum)*rightSum)%mod;
        ans=max({ans,(total-leftSum)*leftSum,(total-rightSum)*rightSum});
        return leftSum + rightSum + root->val;

    }
    void totalSum(TreeNode* root){
        if(!root)return ;
        total+= root->val;
        totalSum(root->left);
        totalSum(root->right);
    }
    int maxProduct(TreeNode* root) {
        // at every root
        // check the left sum and right sum
        // and store the ans as the max product
        totalSum(root);
        long long ans = 0;
        solve(root, ans);
        return ans%mod;


    }
};