/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

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
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A)
    return NULL;
    
    ListNode* temp=A,*prev=NULL,*ans,*fprev=NULL,*temp4;
    int i=0;
    while(temp){
        if((temp->next && temp->val == temp->next->val) || (prev && prev->val == temp->val)){
            prev = temp;
            temp = temp->next;
        }
        else{
            if(fprev){
            fprev->next = temp;
            
                
            }
            else{
                if(i==0){
                    ans =  temp;
                    i++;
                }
            }
            fprev = temp;
            temp4 = temp->next;
            fprev->next = NULL;
            prev = temp;
            temp = temp4;

        }
    }
    

    return (i==0)?NULL:ans;
}
