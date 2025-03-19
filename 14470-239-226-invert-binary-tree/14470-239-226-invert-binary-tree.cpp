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

    TreeNode* invertTree(TreeNode* root){
        if(!root) return nullptr;
        auto tempNode = root->left; 
        root->left = root->right;
        root->right = tempNode;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    //essa foi a minha primeira solucao 
    //porem nao funciona pq apesar de inverter os valores n inverte a estrutura 
    //a mudança deve ser simetrica em torno da raiz
    //por isso eh mt melhor a solucao classica de trocar os ponteiros  
    TreeNode* solucaoRUIM(TreeNode* root) {
        if (!root) return nullptr;
        vector<int> BFS_order;
        InOrderTransverse(root, BFS_order);
        int index = BFS_order.size() - 1;
        ReverseReplace(root, BFS_order, index);

        return root;
    }

    void InOrderTransverse(TreeNode* node, vector<int>& NodesList){
        if(!node) return;
        InOrderTransverse(node->left, NodesList);
        NodesList.push_back(node->val);
        InOrderTransverse(node->right, NodesList);
    }

    void ReverseReplace(TreeNode* node, vector<int>& NodesList, int& index){
        if(!node) return;
        ReverseReplace(node->left, NodesList, index);
        node->val = NodesList[index];
        index--;
        ReverseReplace(node->right, NodesList, index);
    }   
};