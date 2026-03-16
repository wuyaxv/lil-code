/* 236.二叉树的最近公共祖先
 *
 * 思路：递归遍历二叉树
 */

#include <cstddef>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // DFS遍历
        stack<int> indices;
        stack<TreeNode *> node;
        unordered_map<int, TreeNode*> map;
        int i[2] = {0}; // 需要找到的索引 
        int index = 0;  // 当前指针的索引，初始化为0
        int d1 = 0, d2 = 0;

        TreeNode *ptr = NULL;
        indices.push(1);
        node.push(root);

        while(!node.empty() && !(i[0] && i[1])) {
            ptr = node.top();
            index = indices.top();
            map.insert({index, ptr});

            node.pop();
            indices.pop();

            // 找到
            if(ptr == p) {
                i[0] = index;
            }
            else if(ptr == q) {
                i[1] = index;
            }

            // 前序遍历
            if(ptr->right) {
                node.push(ptr->right);
                indices.push(index*2 + 1);
            }

            if(ptr->left) {
                node.push(ptr->left);
                indices.push(index*2);
            }
        }

        d1 = static_cast<int>(log2(i[0]));
        d2 = static_cast<int>(log2(i[1]));
        
        if(d1 > d2) {
            for(int j = d1-d2; j > 0; --j) {
                i[0] /= 2;
            }
        }
        else {
            for(int j = d2-d1; j > 0; --j) {
                i[1] /= 2;
            }
        }

        while(i[0] != i[1]) {
            i[0] /= 2;
            i[1] /= 2;
        }

        if(auto search = map.find(i[0]); search != map.end()) {
            return search->second;
        }
    }
};

TreeNode* buildTree(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1; // 当前访问数组索引
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();

        // 处理左孩子
        if (i < values.size()) {
            if (values[i] != -1) {
                node->left = new TreeNode(values[i]);
                q.push(node->left);
            }
            i++;
        }

        // 处理右孩子
        if (i < values.size()) {
            if (values[i] != -1) {
                node->right = new TreeNode(values[i]);
                q.push(node->right);
            }
            i++;
        }
    }
    return root;
}

int main(void)
{
    auto s = Solution();

    std::vector<int> vals = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* tree = buildTree(vals);

    TreeNode *root = tree;

    TreeNode *p = root;
    TreeNode *q = root->right;

    TreeNode *result = s.lowestCommonAncestor(root, p, q);
    printf("%d" ,result->val);
}
