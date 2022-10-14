class Solution {
public:
    TreeNode* getRightMost(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        if(not root) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left){
            TreeNode* temp = getRightMost(root->left);
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        return;
    }
};
