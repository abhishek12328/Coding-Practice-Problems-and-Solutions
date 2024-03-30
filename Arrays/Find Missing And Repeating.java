// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

class Solve {
    int[] findTwoElement(int arr[], int n) {
        // code here
        int[] ans = new int[2];
        for(int i=0;i < n ;i++){
            int temp = arr[i];
            if(arr[i] < 0)  temp = -arr[i];
            if(arr[temp-1] < 0) ans[0] = temp;
            else arr[temp-1] = -arr[temp-1];
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0) ans[1] = i+1;
        }
        return ans;
    }
}
