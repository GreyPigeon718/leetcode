#include <iostream>
#include <string>

using namespace std;
//根据二叉树创建字符串
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
// class Solution {
// public:
//     string tree2str(TreeNode* root) {
//         if (root == nullptr)
//             return "";
//         else if (root->left == nullptr && root->right == nullptr)
//             return root->val;
//         else if(root->right == nullptr)
//             return to_string(root->val) + "(" + tree2str(root->left) + ")";
//         else 
//             return to_string(root->val) + "(" + tree2str(root->left) + ")"
//                     + "(" + tree2str(root->right) + ")";
//     }
// };
//二叉树的层序遍历
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
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> vv;
//         if(root == nullptr)
//             return vv;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             int size = q.size();
//             vector<int> v;
//             for(int i = 0; i < size; ++i)
//             {
//                 TreeNode* Node = q.front();
//                 q.pop();
//                 v.push_back(Node->val);
//                 if (Node->left)
//                     q.push(Node->left);
//                 if (Node->right)
//                     q.push(Node->right);
//             }
//             vv.push_back(v);
//         }
//         return vv;
//     }
// };

//二叉树最近公共祖先
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool dfs (TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
            return false;
        bool lson = dfs(root->left,p,q);
        bool rson = dfs(root->right,p,q);
        if(lson && rson ||((root->val == p->val || root->val == q->val) && (lson || rson)))
            ans = root;
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};