#include <cassert>
#include "../../common/TreeNode.hpp"

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/delete-leaves-with-a-given-value/solutions/5170962/dfs-with-postorder-traversal/
 */
class Problem1325 {

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) return nullptr;
        return root;
    }
};

TreeNode* createTree() {
    // Уровень 3
    auto* node4 = new TreeNode(4);
    auto* node2_leaf = new TreeNode(2);

    // Уровень 2
    auto* node3 = new TreeNode(3, node2_leaf, node4);
    auto* node2 = new TreeNode(2);
    auto* node2_with_child = new TreeNode(2, node2, nullptr);

    // Уровень 1 (корень)
    auto* root = new TreeNode(1, node2_with_child, node3);

    return root;
}

void freeTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}


int main() {
    Problem1325 problem;
    auto root = createTree();
    problem.removeLeafNodes(root, 2);
    assert(root->left == nullptr);
    freeTree(root);
    return 0;
}
