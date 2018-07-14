class Solution {
    int i,numsXor,orgXor,S,faultS,delta,totalXor,c;
    vector<int> ans;
    
    int count(vector<int>& nums, int i){
        int temp = 0;
        for(int j = 0 ; j< nums.size(); j++) if(nums[j] == i) temp+=1;
        return temp;
    }
public:
    vector<int> findErrorNums(vector<int>& nums) {
        while(!ans.empty()) ans.pop_back();
        for( i = 0,numsXor = 0,orgXor = 0,faultS = 0; i<nums.size() ; i++){
            numsXor ^= nums[i];
            orgXor ^= (i+1);
            faultS += nums[i];
            S += i+1;
        }
        delta = S-faultS;
        for( i = 1; i<=nums.size() ; i++) if( (numsXor^orgXor) == (i^(i+delta))){
            c = count(nums, i);
            if(c == 0){
                ans.push_back(i+delta);
                ans.push_back(i);
                return ans;
            }else if(c==2){
                ans.push_back(i);
                ans.push_back(i+delta);
                return ans;
            }
        }
        return ans;
    }
};

/*
 [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
 if we replace 15 with 13 in the above test case:-
 using this algorithm the output can be many pairs including the real pair, such as:
 [1,3], [5,7], [13,15]->actual pair and many more. so this algo doesn't work.
*/

// class Solution {
//     int i,numsXor,orgXor,S,faultS,delta,totalXor,a,b;
//     vector<int> ans;
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         while(!ans.empty()) ans.pop_back();
//         for( i = 0,numsXor = 0,orgXor = 0,faultS = 0; i<nums.size() ; i++){
//             numsXor ^= nums[i];
//             orgXor ^= (i+1);
//             faultS += nums[i];
//             S += i+1;
//         }
//         delta = S-faultS;
//         totalXor = numsXor^orgXor;
//         for( i = 1; i<=nums.size() ; i++) {
//             a = i^numsXor;
//             b = ((i+delta)^orgXor);
//             if( totalXor == (i^(i+delta)) && a == b){
//                 ans.push_back(i);
//                 ans.push_back(i+delta);
//                 return ans;
//             }
//         }
//         return ans;
//     }
// };
