/*Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

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
ListNode* Solution::removeNthFromEnd(ListNode* a, int b) {
    if(!a)
    return NULL;
    int n=0;
    ListNode *temp = a;
    while(temp){
        n++;
        temp = temp->next;
    }
    int target = n-b-1;
    if(target < 0){
        return a->next;
    }
    else{
        temp = a;
        for(int i=0;i<target;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    return a;
}
