#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

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

TreeNode* buildBST(int arr[], int left, int right) {
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;

    TreeNode* root = new TreeNode(arr[mid]);

    root->left = buildBST(arr, left, mid - 1);
    root->right = buildBST(arr, mid + 1, right);

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int arr[100];
    int n = 0;

    while (head != NULL) {
        arr[n] = head->val;
        n++;
        head = head->next;
    }

    return buildBST(arr, 0, n - 1);
}

void preorder(TreeNode* root) {
    if (root == NULL)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
     ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    TreeNode* root = sortedListToBST(head);

    cout << "Preorder: ";
    preorder(root);

    return 0;
}