/*A new online video game has been released, and in this video game, there are 15-minute rounds scheduled every quarter-hour period. This means that at HH:00, HH:15, HH:30 and HH:45, a new round starts, where HH represents an integer number from 00 to 23. A 24-hour clock is used, so the earliest time in the day is 00:00 and the latest is 23:59.

Given two strings startTime and finishTime in the format "HH:MM" representing the exact time you started and finished playing the game, respectively, calculate the number of full rounds that you played during your game session.

For example, if startTime = "05:20" and finishTime = "05:59" this means you played only one full round from 05:30 to 05:45. You did not play the full round from 05:15 to 05:30 because you started after the round began, and you did not play the full round from 05:45 to 06:00 because you stopped before the round ended.
If finishTime is earlier than startTime, this means you have played overnight (from startTime to the midnight and from midnight to finishTime).

Return the number of full rounds that you have played if you had started playing at startTime and finished at finishTime.

---------------------------------------------------------------------------
----------------------------------------------------------------------------*/


class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int shr = stoi(startTime.substr(0,2)),ehr = stoi(finishTime.substr(0,2)),smin = stoi(startTime.substr(3,2)),emin = stoi(finishTime.substr(3,2));
        
        if(shr*60+smin > ehr*60+emin){
            ehr = ehr + 24; 
        }
        
        if(smin%15 != 0)
            smin = smin + (15-smin%15);
        
        if(emin%15 != 0)
            emin = emin - emin%15;
        
        
        
       return (((ehr-shr)*60+emin-smin)/15 > 0 )?((ehr-shr)*60+emin-smin)/15:0;
        
        
    }
};
