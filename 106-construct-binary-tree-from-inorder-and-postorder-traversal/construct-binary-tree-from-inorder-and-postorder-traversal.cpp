class Solution {
public:
    int find(vector<int>& in, int target, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(in[i] == target)
                return i;
        }
        return -1;
    }
    
    TreeNode* build(vector<int>& in, vector<int>& post, int InStart, int InEnd, int index) {
        if(InStart > InEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(post[index]);
        int pos = find(in, post[index], InStart, InEnd);
        

        root->right = build(in, post, pos + 1, InEnd, index - 1);
        root->left  = build(in, post, InStart, pos - 1, index - 1 - (InEnd - pos));
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, 0, n - 1, n - 1);
    }
};