/*Given a linked list A of length N and an integer B.

You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

If no such element exists, then return -1.

NOTE:

Position of middle node is: (N/2)+1, where N is the total number of nodes in the list.


----------------------------------------
----------------------------------------
----------------------------------------
----------------------------------------*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* a, int b) {
    int i,n=0;
    ListNode* temp = a;
    while(temp){
        temp = temp->next;
        n++;
        
    }
    temp = a;
    int bound = n/2-b;
    if(bound<0)
    return -1;
    for(i=0;i<bound;i++){
        temp = temp->next;
    }
    return temp->val;

}
