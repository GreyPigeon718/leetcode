//不同的二叉搜索树II
class Solution {
public:
    vector<TreeNode*> generateTrees(int st,int n) {
        // 边界条件
        vector<TreeNode*> ans;
        if(st > n) return {NULL};   // 一定要返回{NULL}集合，否则上级树根节点i取边界得时候就不能去全排列了，有一个for循环会直接跳过
        // 递归代码
        for(int i=st;i<=n;i++){
            for(auto& l : generateTrees(st,i-1)){
                for(auto& r : generateTrees(i+1,n)){
                    TreeNode* root = new TreeNode(i,l,r);
                    ans.push_back(root);
                }
            }            
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generateTrees(1,n);
    }
};
