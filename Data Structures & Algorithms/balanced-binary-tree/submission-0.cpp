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
    bool ans=true;
    bool isBalanced(TreeNode* root) {
        int n=0;
        fun(root, n);
        return ans;
    }
    int fun(TreeNode* root, int &n){
        if(root==NULL) return 0;
        int l= fun(root->left, n);
        int r= fun(root->right, n);
        n= abs(l-r);
        if(n>1) ans= false;
        return 1+max(l, r);
    }
};
