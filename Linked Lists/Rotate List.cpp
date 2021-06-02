/*Given a list, rotate the list to the right by k places, where k is non-negative.

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
ListNode* Solution::rotateRight(ListNode* a, int b) {
    if(!a)
    return NULL;
    int count=1;
    ListNode* temp = a;
    while(temp->next){
        count++;
        temp = temp->next;
    }
    temp->next = a;
    int end = count-(b%count)-1;
    ListNode* temp1 = a,*temp2;
    for(int i=0;i<end;i++){
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = NULL;
    return temp2;
}
