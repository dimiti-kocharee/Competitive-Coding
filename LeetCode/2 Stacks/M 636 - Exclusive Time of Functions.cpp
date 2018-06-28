class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans;
        for( int y = 0 ; y < n ;y++ ) ans.push_back(0);
        if( !logs.empty() ){
            stack<int> tempid;
            int stringIndex, presentid, presentTimeStamp, startOrEnd, previousSign, previousTimeStamp;
            for( int i = 0 ; i < logs.size() ; i++ ){
                stringIndex = 0;
                presentid = 0;
                presentTimeStamp =0;

//This line will just extract time, id and state either start or end from the string
                while(logs[i][stringIndex] != ':') {          //to get id from the string
                    presentid = presentid*10 + logs[i][stringIndex] - 48;
                    stringIndex++;
                }
                if(logs[i][stringIndex+1] == 's'){            //to know about start or end
                    startOrEnd = 0;    //start flag
                    stringIndex += 7;
                }else{
                    startOrEnd = 1;    //end flag
                    stringIndex += 5;
                }
                while( stringIndex != logs[i].length() ){     //to get the timestamp from the string
                    presentTimeStamp = presentTimeStamp*10 + logs[i][stringIndex] - 48;
                    stringIndex++;
                }
//This                
                if( !tempid.empty() ){
                    if( previousSign == startOrEnd ) ans[tempid.top()] += presentTimeStamp - previousTimeStamp;
                    else if(previousSign == 0 && startOrEnd == 1) ans[tempid.top()] += presentTimeStamp - previousTimeStamp + 1;
                    else if(previousSign == 1 && startOrEnd == 0) ans[tempid.top()] += presentTimeStamp - previousTimeStamp - 1;
                }
                previousSign = startOrEnd;
                previousTimeStamp = presentTimeStamp;
                if(startOrEnd == 0) tempid.push(presentid);
                else tempid.pop();
            }
            
        }
        return ans;
    }
};
