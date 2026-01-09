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
    TreeNode* LCA(TreeNode* root, TreeNode* left ,TreeNode* right){
        if(!root or root==right or root==left)return root;
        TreeNode* leftside = LCA(root->left, left, right);
        TreeNode* rightside = LCA(root->right, left, right);
        if(leftside!=NULL and rightside!=NULL)return root;
        if(leftside)return leftside;
        return rightside;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // basically we need to first find the leftmost and the rightmost point and then find there LCA
        if(!root)return NULL;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        TreeNode* leftMost = root, *rightMost = root;
        while(!treeQueue.empty()){
            int n = treeQueue.size();
            for(int i=0;i<n;i++){
                auto curr = treeQueue.front();treeQueue.pop();
                if(i==0)leftMost = curr;
                if(i==n-1)rightMost = curr;
                if(curr->left)treeQueue.push(curr->left);
                if(curr->right)treeQueue.push(curr->right);
            }
        }
        cout<<"left: "<<leftMost->val<<endl;
        cout<<"right: "<<rightMost->val<<endl;
        return LCA(root, leftMost, rightMost);

    }
};