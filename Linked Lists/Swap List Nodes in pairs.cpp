/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

----------------------------------------------------
----------------------------------------------------
----------------------------------------------------
----------------------------------------------------*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* a) {

    ListNode *temp1=a,*temp2,*temp3,*temp4,*resultNode;
    if(a->next)
    resultNode = a->next;
    else
    resultNode = a;
    if(temp1 && temp1->next){
        temp2 = temp1->next;
        temp3 = temp2->next;
        temp4 = temp1;
        temp1->next = temp3;
        temp2->next = temp1;
        temp1 = temp3;
    }
    while(temp1 && temp1->next){
        temp2 = temp1->next;
        temp3 = temp2->next;
        temp4->next = temp2;
        temp4 = temp1;
        temp1->next = temp3;
        temp2->next = temp1;
        temp1 = temp3;
    }
    
    return resultNode;
}
