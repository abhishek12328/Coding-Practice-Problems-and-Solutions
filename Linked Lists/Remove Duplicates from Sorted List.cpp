/*Given a sorted linked list, delete all duplicates such that each element appear only once.

-------------------------------------------
-------------------------------------------
-------------------------------------------
-------------------------------------------*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* a) {
    if(!a)
    return NULL;
    ListNode* result = new ListNode(a->val);
    ListNode* temp = a,*temp1 = result, *temp2;
    int prev = a->val;
    while(temp){
        temp = temp->next;
        if(temp && prev!=temp->val){
            prev = temp->val;
            ListNode* temp2 = new ListNode(temp->val);
            temp1->next = temp2;
            temp1 = temp1->next;
        }
    }
    return result;
}
