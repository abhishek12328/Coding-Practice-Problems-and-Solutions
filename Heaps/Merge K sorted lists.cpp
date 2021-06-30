/*Merge k sorted linked lists and return it as one sorted list.


------------------------------------------------------------
------------------------------------------------------------*/


ListNode* mergeKLists(ListNode** A, int n1) {
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n1;i++){
        ListNode* temp = A[i];
        while(temp){
            q.push(temp->val);
            temp = temp->next;
        }
    }
    ListNode* head = new ListNode(q.top());
    ListNode *temp = head;
    q.pop();
    while(!q.empty()){
        ListNode* temp1 = new ListNode(q.top());
        q.pop();
        temp->next = temp1;
        temp = temp->next;
    }
    return head;
    
}
