class Solution {
    private: 
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        
        if(prev != NULL && prev->val > root->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
         inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};
