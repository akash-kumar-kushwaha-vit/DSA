class Solution {
public:
    int ans = 0;

    pair<int, int> f(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        auto left = f(root->left);
        auto right = f(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};