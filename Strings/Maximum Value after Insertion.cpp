/*You are given a very large integer n, represented as a string,​​​​​​ and an integer digit x. The digits in n and the digit x are in the inclusive range [1, 9], and n may represent a negative number.

You want to maximize n's numerical value by inserting x anywhere in the decimal representation of n​​​​​​. You cannot insert x to the left of the negative sign.

For example, if n = 73 and x = 6, it would be best to insert it between 7 and 3, making n = 763.
If n = -55 and x = 2, it would be best to insert it before the first 5, making n = -255.
Return a string representing the maximum value of n​​​​​​ after the insertion.

 -----------------------------------------------------------------------------
 -----------------------------------------------------------------------------*/



class Solution {
public:
    string maxValue(string n, int x) {
        int flag = 0;
        if(n[0]=='-'){
        for(int i=1;i<n.size();i++){
            if(n[i]-'0'>x){
                n.insert(n.begin()+i,x+'0');
                flag = 1;
                break;
            }
        }
            if(flag != 1)
                n.push_back(x+'0');
        }
        else{
        for(int i=0;i<n.size();i++){
            if(n[i]-'0'<x){
                n.insert(n.begin()+i,x+'0');
                flag = 1;
                break;
            }
        }   
            if(flag != 1)
                n.push_back(x+'0');
        }
        return n;
            
    }
};
