class Solution {
public:
    int find(vector<int>& in, int target, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(in[i] == target)
                return i;
        }
        return -1;
    }
    
    TreeNode* build(vector<int>& in, vector<int>& pre, int InStart, int InEnd, int index) {
        if(InStart > InEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[index]);
        int pos = find(in, pre[index], InStart, InEnd);
        
        root->left  = build(in, pre, InStart, pos - 1, index + 1);
        root->right = build(in, pre, pos + 1, InEnd, index + (pos - InStart) + 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return build(inorder, preorder, 0, n - 1, 0);
    }
};