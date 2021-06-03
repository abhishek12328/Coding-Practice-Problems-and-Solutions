/*Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

------------------------------------------------
------------------------------------------------
------------------------------------------------
------------------------------------------------*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    vector<int> v1,v2;
    ListNode *temp=A;
    while(temp){
        v1.push_back(temp->val);
        v2.push_back(temp->val);
        temp = temp->next;
    }
    reverse(v1.begin(),v1.end());
    temp = A;
    int i=0;
    while(temp){
        if(i%2==0)
        temp->val = v2[i/2];
        else
        temp->val = v1[i/2];
        temp = temp->next;
        i++;
    }
    return A;
}
