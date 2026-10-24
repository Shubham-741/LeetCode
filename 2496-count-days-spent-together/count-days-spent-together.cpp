class Solution {
public:

    int convert(string & date){

        vector<int>dates = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int m = stoi(date.substr(0,2));
        int d = stoi(date.substr(3,2));

        for(int i = 0; i<m-1; i++){
            d+=dates[i];            
        }

        return d;

    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        string startDate = max(arriveAlice, arriveBob);
        string endDate = min(leaveAlice, leaveBob);

        if(startDate > endDate){
            return 0;
        }

        return convert(endDate) - convert(startDate)+1;
        
    }
};