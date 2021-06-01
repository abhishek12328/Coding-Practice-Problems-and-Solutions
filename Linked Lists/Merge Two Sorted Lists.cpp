/*Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

---------------------------------------
---------------------------------------
---------------------------------------
---------------------------------------*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    if(a==NULL && b==NULL)
    return NULL;
    ListNode* temp1 = a,*temp2=b,*temp4;
    ListNode* result;
    if(temp1 &&temp2){
        if(temp1->val<temp2->val){
            result = new ListNode(temp1->val);
            temp1 = temp1->next;
        }
        else{
            result = new ListNode(temp2->val);
            temp2 = temp2->next;
        }
    }
    else if(temp1){
        result = new ListNode(temp1->val);
        temp1 = temp1->next;
    }
    else if(temp2){
        result = new ListNode(temp2->val);
        temp2 = temp2->next;

    }
    ListNode* temp3 = result;
    
    while(temp1 &&temp2){
        if(temp1->val<temp2->val){
            ListNode* temp4 = new ListNode(temp1->val);
            temp3->next = temp4;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
        else{
            ListNode* temp4 = new ListNode(temp2->val);
            temp3->next = temp4;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        
    }
    while(temp1){
        ListNode* temp4 = new ListNode(temp1->val);
            temp3->next = temp4;
            temp3 = temp3->next;
            temp1 = temp1->next;
    }
    while(temp2){
        ListNode* temp4 = new ListNode(temp2->val);
            temp3->next = temp4;
            temp3 = temp3->next;
            temp2 = temp2->next;
    }
    return result;
}
