#include <stdio.h>
#include <stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

};

struct TreeNode*
findNode(struct TreeNode* root, int value){
    if(root == NULL){
        return NULL;
    
    }

    if(root->val == value){
        return root;
    
    }

    struct TreeNode* leftResult = findNode(root->left, value);
    struct TreeNode* rightResult = findNode(root->right, value);
        return leftResult != NULL ? leftResult : rightResult;

}

int depth(struct TreeNode* root, int value, int level){
    if(root == NULL){
        return -1;
    
    }

    if(root->val == value){
        return level;
    
    }

    int leftDepth = depth(root->left, value, level + 1);
        if(leftDepth != -1){
            return leftDepth;
        
        }

        return depth(root->right, value, level +1);

}

bool isCousins(struct TreeNode* root, int x, int y){
    if (root == NULL || x == y){
        return false;

    }

int xDepth = depth(root, x, 0);
int yDepth = depth(root, y, 0);

    if(xDepth == yDepth){
        struct TreeNode* xParent = findNode(root, x);
        struct TreeNode* yParent = findNode(root, y);

            return xParent != NULL && yParent != NULL && xParent != yParent;

    }

    return false;

}
