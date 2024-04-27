#include "TreeNode.cpp"
#include <cassert>

class Problem129 {
public:
    int dfs(TreeNode* node, int pathSum = 0) {
        if (node == nullptr) return 0;
        int nextPathSum = pathSum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) return nextPathSum;
        else return dfs(node->left, nextPathSum) + dfs(node->right, nextPathSum);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root);
    }
};

int main() {

    TreeNode left(2);
    TreeNode right(3);
    TreeNode root = TreeNode(1, &left, &right);

    Problem129 problem129;
    assert(25 == problem129.sumNumbers(&root));

    return 0;
}