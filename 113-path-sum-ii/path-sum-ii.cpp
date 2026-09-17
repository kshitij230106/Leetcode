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
class Solution {
public:
    vector<vector<int>> ans;
    int path[1000];
    int index=0;

    void dfs(TreeNode* root,int targetSum){
        if(root==NULL)
            return;

        path[index++] = root->val;

        if(root->left == NULL && root->right==NULL){
            if(root->val==targetSum){
                vector<int> temp;

            for(int i=0;i<index;i++)
                temp.push_back(path[i]);

            ans.push_back(temp);
            }
            index--;
            return;
        }
        targetSum -= root->val;

        dfs(root->left,targetSum);
        dfs(root->right,targetSum);

        index--;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);

        return ans;
    }
};