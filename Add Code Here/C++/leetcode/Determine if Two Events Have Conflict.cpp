class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int time11=stoi(event1[0].substr(0,2))*60;
        time11+=stoi(event1[0].substr(3,2));
        
        int time12=stoi(event1[1].substr(0,2))*60;
        time12+=stoi(event1[1].substr(3,2));
        
        int time21=stoi(event2[0].substr(0,2))*60;
        time21+=stoi(event2[0].substr(3,2));
        
        int time22=stoi(event2[1].substr(0,2))*60;
        time22+=stoi(event2[1].substr(3,2));
        
        if(time11>time22 or time12<time21) return false;
        return true;
    }
};