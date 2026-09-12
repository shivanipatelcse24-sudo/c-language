#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* solve(vector<int>& nums, int left, int right) {
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;

    TreeNode* root = new TreeNode(nums[mid]);

    root->left = solve(nums, left, mid - 1);
    root->right = solve(nums, mid + 1, right);

    return root;
}

void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = solve(nums, 0, nums.size() - 1);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}