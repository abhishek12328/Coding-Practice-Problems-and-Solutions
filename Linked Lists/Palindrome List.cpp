/*Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.

-------------------------------------------------
-------------------------------------------------
-------------------------------------------------
-------------------------------------------------*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* a) {
    if(!a)
    return 1;
    if(a->next == NULL)
    return 1;
    int n=0;
    ListNode *temp=a;
    while(temp){
        n++;
        temp = temp->next;
    }
    temp = a;
    for(int i=0;i<n/2;i++){
        temp = temp->next;
    }
    ListNode *temp1 = temp,*temp2=temp->next,*temp3;
    int bound = (n%2==0)? (n/2-1):(n/2);
    for(int i=0;i<bound;i++){
        temp3 = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    temp = a;
    for(int i=0;i< n/2 ;i++){
    
        if(temp->val!=temp1->val)
        return 0;
        temp = temp->next;
        temp1 = temp1->next;
    }
    return 1;
    
    
    
}
