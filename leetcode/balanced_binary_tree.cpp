// Filename: balanced_binary_tree.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which 
 * the depth of the two subtrees of every node never differ by more than 1.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, &depth);
    }

private:
    bool isBalanced(TreeNode *root, int *depth) {
        if (root == NULL) {
            *depth = 0;
            return true;
        }
        
        int left_depth = 0, right_depth = 0;
        bool b_left= isBalanced(root->left, &left_depth);
        bool b_right = isBalanced(root->right, &right_depth);

        if (b_left && b_right) {
            int diff = left_depth > right_depth ? left_depth - right_depth : right_depth - left_depth;
            
            if (diff <= 1) {
                *depth = 1 + (left_depth > right_depth ? left_depth : right_depth);
                return true;
            }
        }

        return false;
    }
};
