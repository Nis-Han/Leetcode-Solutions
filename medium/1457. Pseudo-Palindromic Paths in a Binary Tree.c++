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

int freq;
int ans = 0;
int len = 0;
bool vl;
class Solution {
public:
    bool checkPseudoPalindrome() {
        return __builtin_popcount(freq) == len%2;
    };

    void dfs(TreeNode* n){
        if(n==NULL)return;
        
        freq ^= 1 << (n->val);
        len++;
        if(n->left!=NULL)dfs(n->left);
        if(n->right!=NULL)dfs(n->right);

        if(n->left==NULL && n->right==NULL && checkPseudoPalindrome()){
            ans++;
        }
        freq ^= 1 << (n->val);
        len--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        len = 0;
        freq = 0;
        dfs(root);
        return ans;
    }
};