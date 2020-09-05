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
    void get(TreeNode* root1, vector<int> &r1)
    {
        if(root1==NULL)
            return;
        get(root1->left, r1);
        r1.push_back(root1->val);
        get(root1->right, r1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> r1;
        get(root1, r1);
        get(root2, r1);
        sort(r1.begin(), r1.end());
        return r1;
        
    }
};
