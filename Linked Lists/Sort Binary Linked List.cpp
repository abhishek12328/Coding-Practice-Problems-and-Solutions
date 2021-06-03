/*Given a Linked List A consisting of N nodes.

The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

You need to sort the linked list and return the new linked list.

NOTE:

Try to do it in constant space.

--------------------------------------
--------------------------------------
--------------------------------------
--------------------------------------*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int zero=0,one=0;
    ListNode * temp = A;
    int i;
    while(temp){
        if(temp->val==0)
        zero++;
        else
        one++;
        temp = temp->next;
    }
    temp =A;
    for(i=0;i<zero;i++){
        temp->val = 0;
        temp = temp->next;
    }
    for(i=0;i<one;i++){
        temp->val = 1;
        temp = temp->next;
    }
    return A;
}
