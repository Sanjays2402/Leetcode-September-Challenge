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
    int sumtree(TreeNode* root, int sum)
    {
        if(root==NULL)
            return 0;
        sum = (sum<<1) + root->val;
        if(root->left==NULL && root->right==NULL)
            return sum;
        
        return sumtree(root->left, sum) + sumtree(root->right, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return sumtree(root, 0);
    }
};
