/*Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

-----------------------------------------
-----------------------------------------
-----------------------------------------
-----------------------------------------*/

string Solution::intToRoman(int a) {
    string s = "";
    int temp =a,i=0;
    while(temp){
        int num =  temp%10;
        temp = temp/10;
        i++;
        if(i==1){
            if(num == 1)
            s = "I" + s; 
            if(num == 2)
            s = "II" + s; 
            if(num == 3)
            s = "III" + s; 
            if(num == 4)
            s = "IV" + s; 
            if(num == 5)
            s = "V" + s; 
            if(num == 6)
            s = "VI" + s; 
            if(num == 7)
            s = "VII" + s; 
            if(num == 8)
            s = "VIII" + s; 
            if(num == 9)
            s = "IX" + s; 
        }
        else if(i==2){
            if(num == 1)
            s = "X" + s; 
            if(num == 2)
            s = "XX" + s; 
            if(num == 3)
            s = "XXX" + s; 
            if(num == 4)
            s = "XL" + s; 
            if(num == 5)
            s = "L" + s; 
            if(num == 6)
            s = "LX" + s; 
            if(num == 7)
            s = "LXX" + s; 
            if(num == 8)
            s = "LXXX" + s; 
            if(num == 9)
            s = "XC" + s;
        }
        else if(i==3){
            if(num == 1)
            s = "C" + s; 
            if(num == 2)
            s = "CC" + s; 
            if(num == 3)
            s = "CCC" + s; 
            if(num == 4)
            s = "CD" + s; 
            if(num == 5)
            s = "D" + s; 
            if(num == 6)
            s = "DC" + s; 
            if(num == 7)
            s = "DCC" + s; 
            if(num == 8)
            s = "DCCC" + s; 
            if(num == 9)
            s = "CM" + s;
        }
        else if(i==4){
            if(num == 1)
            s = "M" + s; 
            if(num == 2)
            s = "MM" + s; 
            if(num == 3)
            s = "MMM" + s; 
        }
    }
    return s;
}
