/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

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
ListNode* Solution::addTwoNumbers(ListNode* a, ListNode* b) {
    if(!a||!b)
    return NULL;
    ListNode* temp1=a;
    ListNode* temp2=b;
    ListNode* result = new ListNode((a->val+b->val)%10);
    ListNode* temp3 = result,*temp4;
    int carry= (a->val+b->val)/10;
    while(temp1 || temp2){
        if(temp1)
        temp1 = temp1->next;
        if(temp2)
        temp2 = temp2->next;
        
        if(!temp1 && !temp2){
            break;
        }
        
        else if(temp1 == NULL && temp2){
            ListNode* temp4 = new ListNode((carry+temp2->val)%10);
            temp3->next = temp4;
            temp3 = temp3->next;
            carry = (carry+temp2->val)/10;
        }
        else if(temp2 == NULL && temp1){
            ListNode* temp4 = new ListNode((carry+temp1->val)%10);
            temp3->next = temp4;
            temp3 = temp3->next;
            carry = (carry+temp1->val)/10;
        }
        else if(temp1 && temp2){
            ListNode* temp4 = new ListNode((carry+temp1->val+temp2->val)%10);
            temp3->next = temp4;
            temp3 = temp3->next;
            carry = (carry+temp1->val+temp2->val)/10;
        }
    }

    if(carry){
            ListNode* temp4 = new ListNode(carry%10);
            temp3->next = temp4;
                        temp3 = temp3->next;

    }
    return result;
    
}
