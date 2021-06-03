/*Sort a linked list using insertion sort.

------------------------------------------
------------------------------------------
------------------------------------------
------------------------------------------*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* head = new ListNode (INT_MIN);
    head -> next = A;
    
    int preval = INT_MIN;
    ListNode* prev = head;
    ListNode* t = A;
    while(t != NULL)
    {
        if(t-> val >= preval)
        {
            preval = t-> val;
            prev = t;
            t = t -> next;
            continue;
        }
        
        ListNode* k = head;
        while(t-> val >= k->next->val)
        {
            k = k->next;
        }
        // ListNode* temp = t-> next;
        prev-> next = t->next;
        t-> next = k->next;
        k->next = t;
        t = prev-> next;
    }
    
    return head -> next;
}

