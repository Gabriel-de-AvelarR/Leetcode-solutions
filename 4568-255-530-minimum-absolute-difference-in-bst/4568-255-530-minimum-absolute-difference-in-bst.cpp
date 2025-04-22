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
#include <cmath>
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        
        int minimumDifference = INT_MAX;
        TreeNode* prev = nullptr;
        inOrderDFS(root, prev, minimumDifference);
        
        return minimumDifference;
    }

    void inOrderDFS(TreeNode* node, TreeNode*& prev, int& minimumDifference){
        if(!node)
            return; 
        
        inOrderDFS(node->left, prev, minimumDifference);
        if(prev)
            minimumDifference = min(minimumDifference, abs(node->val - prev->val));
        prev = node;
        inOrderDFS(node->right, prev, minimumDifference);
    }
};