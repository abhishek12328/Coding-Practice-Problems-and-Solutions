/*Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.

-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode *root) {
        TreeLinkNode* leftWall = NULL; // leftmost node of the next level.
        TreeLinkNode* prev = NULL; // leading node on the next level
        TreeLinkNode* cur = root; // current node on the current level

        while (cur != NULL) {
            
            while (cur != NULL) {
                if (cur->left != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->left;
                    } else {
                        leftWall = cur->left;
                    }
                    prev = cur->left;
                }

                if (cur->right != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->right;
                    } else {
                        leftWall = cur->right;
                    }
                    prev = cur->right;
                }

                // move to the next node
                cur = cur->next;
            }

            // move to the next level
            cur = leftWall;
            leftWall = NULL;
            prev = NULL;

        }
    }
