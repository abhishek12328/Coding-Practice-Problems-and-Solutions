/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

----------------------------------------
----------------------------------------
----------------------------------------
----------------------------------------*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    vector<int> less,greater;
    int i;
    ListNode *temp=A;
    while(temp){
        if(temp->val < B)
        less.push_back(temp->val);
        else
        greater.push_back(temp->val);
        temp = temp->next;
    }
    if(less.size()==0)
    return A;
    temp = A;
    for(i=0;i<less.size();i++){
        temp->val = less[i];
        temp = temp->next;
    }
    for(i=0;i<greater.size();i++){
        temp->val = greater[i];
        temp = temp->next;
    }
    return A;
    
}
