/*Given a linked list A , reverse the order of all nodes at even positions.

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
ListNode* Solution::solve(ListNode* a) {
    vector<int> v;
    ListNode* temp = a;
    int i=0;
    while(temp){
        i++;
        if(i%2==0)
        v.push_back(temp->val);
        temp = temp->next;
    }
    temp = a->next;
    for(i=v.size()-1;i>=0 && temp ;i--){
        temp->val = v[i];
        if(temp->next)
        temp = temp->next->next;
    }
    return a;
}
