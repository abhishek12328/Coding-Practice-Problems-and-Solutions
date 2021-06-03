/*Reverse a linked list from position m to n. Do it in-place and in one-pass.


-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *curr,*prev=NULL,*next=NULL,*temp = A,*temp1;
    for(int i=0;i<B-2;i++){
        temp = temp->next;
    }
    int i=0;
    if(B==1){
        curr = temp;
        temp1 = temp;
    }
    else{
        curr = temp->next;
        temp1 = temp->next;
    }
    while(i<=C-B){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    temp->next = prev;
    temp1->next = next;
    if(B==1)
    return prev;
    return A;
    
}
