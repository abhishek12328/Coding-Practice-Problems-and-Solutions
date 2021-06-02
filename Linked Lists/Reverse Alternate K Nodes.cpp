/*Given a linked list A of length N and an integer B.

You need to reverse every alternate B nodes in the linked list A.

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
ListNode* Solution::solve(ListNode* a, int b) {
    if(!a)
    return NULL;
    vector<int> tempv(b),final;
    ListNode *temp = a,*temp1,*temp2;
    int i,j=0;
    while(temp){
        if(j%2 == 0){
            for(i=0;i<b;i++){
                tempv[i] = temp->val;
                temp = temp->next;
            }
            reverse(tempv.begin(),tempv.end());
            for(i=0;i<tempv.size();i++){
                final.push_back(tempv[i]);
            }
        }
        else{
            for(i=0;i<b;i++){
                final.push_back(temp->val);
                temp = temp->next;
            }
        }
        j++;
    }
    
    ListNode* ans = new ListNode(final[0]);
    temp2 = ans;
    for(i=1;i<final.size();i++){
        temp1 = new ListNode(final[i]);
        temp2->next = temp1;
        temp2 = temp2->next;
    }
    return ans;
}
