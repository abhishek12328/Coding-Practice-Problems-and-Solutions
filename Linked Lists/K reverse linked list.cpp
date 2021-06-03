/*Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
 
 
 --------------------------------------------
 --------------------------------------------
 --------------------------------------------
 --------------------------------------------*/





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* a, int b) {
    if(!a)
    return NULL;
    if(a->next==NULL)
    return a;
    ListNode* temp1=a,*temp2,*temp3,*ans,*startodd,*starteven,*temp4;
    int j=0;
    while(temp1){
        temp2 = temp1->next;
        j++;
        if(j%2==1)
        startodd = temp1;
        else
        starteven = temp1;
        temp4 = temp1;
        temp3 = temp2;
        for(int i=0;i<b-1;i++){
            temp3 = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
        }
        temp4->next = temp3;
        if(j%2==0)
        startodd->next = temp1;
        else if(j%2==1 && j>1)
        starteven->next = temp1;
        if(j==1){
            ans = temp1;
        }
        temp1 = temp2;
    }
    return ans;
}
