//分糖果 利用set本身的去重和排序思路
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s(candyType.begin(), candyType.end());
        return min(s.size(),candyType.size()/2);
    }
};
//二叉树的最小深度
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int run(TreeNode* root) {
        // write code here
        if (root == nullptr)
            return 0;
        if (root->left == nullptr)
            return run(root->right)+1;
        if (root->right == nullptr)
            return run(root->left) + 1;
         int LeftDepth = run(root->left);
         int RightDepth = run(root->right);
        return (LeftDepth < RightDepth) ? (LeftDepth + 1) : (RightDepth + 1);
    }
};