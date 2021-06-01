/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.



----------------------------------------------------
----------------------------------------------------
----------------------------------------------------
----------------------------------------------------*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A)
    return NULL;
    
    ListNode* temp = A;
    temp->val -= 99999999;

    while(1){
        temp = temp->next;
        if(temp == NULL)
        return temp;
        else if(temp->val < 0){
        temp->val +=99999999;
        return temp;
        }
        else
        temp->val -= 99999999;
    }
    return NULL;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
