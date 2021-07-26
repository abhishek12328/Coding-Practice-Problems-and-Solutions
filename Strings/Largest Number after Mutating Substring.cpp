/*You are given a string num, which represents a large integer. You are also given a 0-indexed integer array change of length 10 that maps each digit 0-9 to another digit. More formally, digit d maps to digit change[d].

You may choose to mutate any substring of num. To mutate a substring, replace each digit num[i] with the digit it maps to in change (i.e. replace num[i] with change[num[i]]).

Return a string representing the largest possible integer after mutating (or choosing not to) any substring of num.

A substring is a contiguous sequence of characters within the string.


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------*/


class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int flag = 0,flag1 =0 ;
        for(int i=0;i<num.size();i++){
            if((num[i]-'0')<=change[num[i]-'0'] && flag == 0 && flag1 == 1){
                flag1 = 1;
                num[i] = change[num[i]-'0']+'0';
            }
            else if((num[i]-'0')<change[num[i]-'0'] && flag == 0){
                flag1 = 1;
                num[i] = change[num[i]-'0']+'0';
            }
            
            else if(flag1  == 1 ){
                flag = 1;
                break;
            }
            cout << flag << flag1 << " ";
        }
        cout <<endl;
        return num;
        
        
    }
};
