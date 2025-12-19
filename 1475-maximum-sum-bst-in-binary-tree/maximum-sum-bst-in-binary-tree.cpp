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
class bst{
    public: 
        bool isBST;
        int mn;
        int mx;
        int sum;
        bst(){
            isBST=true;
            mn=INT_MAX;
            mx = INT_MIN;
            sum = 0;
        }
};
class Solution {
public:
    bst recc(TreeNode* root, int & maxSum){
        if(!root){
            return bst();
        }
        // post order
        bst left = recc(root->left, maxSum);
        bst right = recc(root->right, maxSum);
        
        // curr treeNode
        bool isbst = left.isBST && right.isBST && (root->val>left.mx and root->val<right.mn);
        bst curr; 
        curr.sum = left.sum + right.sum + root->val;
        curr.mn = min(left.mn, root->val);
        curr.mx = max(right.mx, root->val);
        curr.isBST = isbst;
        
        if(curr.isBST){
            maxSum = max(maxSum, curr.sum);
        }
        return curr;
    }
    int maxSumBST(TreeNode* root){
        int maxSum = 0;
        bst BSTNode = recc(root, maxSum);
        return maxSum;
        
    }
};