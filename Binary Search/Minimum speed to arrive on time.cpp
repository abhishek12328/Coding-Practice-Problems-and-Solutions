/*You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.

 */


class Solution {
public:
    
    double round(double var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    double value = (long long int)(var * 10000000);
    return (double)value / 10000000;
}
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=1e7,mid,ans=INT_MAX;
        while(l<=r){
            mid = (l+r)/2;
            double time=0,i;
            for(i=0;i<dist.size()-1;i++){
                time += ((dist[i]))/((mid));
                if(dist[i]%mid !=0)
                    time += 1;
            }
            time += ((double)(dist[i]))/((double)(mid));
            if(time<=hour){
                r = mid-1;
                if(ans>mid)
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }
        if(ans ==INT_MAX)
            return -1;
        else
            return ans;
    }
};
