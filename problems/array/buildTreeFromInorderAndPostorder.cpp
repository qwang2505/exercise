#include "../include.h"

/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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

TreeNode* buildUtil(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2) {
    if (s1 > e1) {
        return NULL;
    }
    TreeNode* node = new TreeNode(postorder[e2]);
    int i = index(inorder, s1, e1, postorder[e2]);
    if (i == -1) {
        return node;
    }
    int leftCount = i - s1;
    int rightCount = e1 - i;
    node->left = buildUtil(inorder, s1, i-1, postorder, s2, s2+leftCount-1);
    node->right = buildUtil(inorder, i+1, e1, postorder, e2-rightCount, e2-1);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildUtil(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}
