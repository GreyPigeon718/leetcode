// 二叉搜索树的第k个节点
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        stack<TreeNode*> skt;
        TreeNode* res = NULL;
        if(pRoot == nullptr || k == 0)
            return NULL;
        TreeNode* cur = pRoot;
        int count = 0;
        while(cur || !skt.empty())
        {
            while (cur)
            {
                skt.push(cur);
                cur = cur->left;
            }
            cur = skt.top();
            skt.pop();
            count++;
            if(count == k)
            {
                res = cur;
                return res;
            }
            cur = cur->right;
        }
        return res;
    }
};

//二叉树的深度
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution1 {
public:
    int TreeDepth(TreeNode* pRoot) {
    //if (pRoot == NULL)
    //    return 0;
     //return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    //
        if (pRoot == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        int res = 0;
        while (!q.empty())
        {
            int n = q.size();
            for(int i = 0;i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                   q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res++;
        }
        return res;
    }
};

//二叉树的层序遍历
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution2 {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> v;
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> tmp;
            while (n)
            {
                TreeNode* p = q.front();
                q.pop();
                tmp.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                n--;
            }
            res.push_back(tmp);
        }
        return res;
        // write code here
//         if (root == NULL)
//             return v;
//         go(0,root);
//         return v;
//     }
//     void go (int level,TreeNode* p){
//         if (v.size() == level){
//             vector<int> blank;
//             v.push_back(blank);
//         }
//         v.at(level).push_back(p->val);
//         if (p->left != NULL){
//             go(level+1,p->left);
//         }
//         if (p->right != NULL){
//             go(level+1,p->right);
//         }



    }
};