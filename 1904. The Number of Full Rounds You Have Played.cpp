class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        string s1 = startTime.substr(0,2),s2 = startTime.substr(3,2),s3 = finishTime.substr(0,2),s4 = finishTime.substr(3,2);
        int sthr = stoi(s1),stmin=stoi(s2);
        int endhr = stoi(s3),endmin= stoi(s4);
        if(stmin==0) stmin = 0;
        else if(stmin<=15) stmin = 15;
        else if(stmin<=30) stmin = 30;
        else if(stmin<=45) stmin = 45;
        else {
            stmin = 0;
            sthr++;
        }
        if(sthr > endhr || (sthr==endhr && stmin > endmin)) endhr += 24;
        int res = 0;
        while(true) {
            if(sthr > endhr || (sthr==endhr && stmin+15>endmin)) break;
            stmin += 15;
            sthr += (stmin/60);
            stmin %= 60;
            res++;
            
        }
        return res;
    }
};