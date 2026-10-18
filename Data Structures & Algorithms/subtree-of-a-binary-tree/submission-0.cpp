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
    bool isEqualTree(TreeNode * root1, TreeNode *root2){
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr) return false;
        if(root1->val!=root2->val) return false;
        bool left=isEqualTree(root1->left,root2->left);
        bool right=isEqualTree(root1->right,root2->right);
        if(left && right) return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=isEqualTree(root,subRoot);
        if(ans) return true;
        bool left=false,right=false;
        if(root!=nullptr) left=isSubtree(root->left,subRoot);
        if(root!=nullptr) right=isSubtree(root->right,subRoot);
        if(left || right) return true;
        return false;
    }
};
