class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, t = nums.size();
        while(t--){
            ans ^= nums[t];
        }        
        return ans;
    }
};
