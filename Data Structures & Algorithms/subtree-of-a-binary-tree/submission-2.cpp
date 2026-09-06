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
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(subroot==NULL){
            return true;
        }
        if (root == NULL && subroot!=NULL) return false;

        if (isSame(root, subroot)) return true;

        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
        
    }
    bool isSame(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if (p == NULL || q == NULL)
            return false;
        if(p->val!=q->val){
            return false;
        }
        return isSame(p->left, q->left)&&isSame(p->right, q->right);
    }
};
