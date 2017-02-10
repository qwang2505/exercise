#include "../include.h"

/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int index(vector<int>& arr, int start, int end, int v) {
    for (int i=start; i <= end; i++) {
        if (arr[i] == v) {
            return i;
        }
    }
    return -1;
}

TreeNode* buildUtil(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
    if (s1 > e1) {
        return NULL;
    }
    TreeNode* node = new TreeNode(preorder[s1]);
    int i = index(inorder, s2, e2, preorder[s1]);
    if (i == -1) {
        return node;
    }
    int leftCount = i - s2;
    int rightCount = e2 - i;
    node->left = buildUtil(preorder, s1+1, s1+leftCount, inorder, s2, i-1);
    node->right = buildUtil(preorder, e1-rightCount+1, e1, inorder, i+1, e2);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildUtil(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}
