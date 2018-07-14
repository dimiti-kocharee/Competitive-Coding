class Solution {
    bool ans;
    vector<int> temp;
    void mergeSort(vector<int>& arr, int left, int right){
        if(right - left >1){
            mergeSort(arr, left, left+(right - left)/2);
            mergeSort(arr, left+(right - left)/2, right);
            int i = left, j = left+(right - left)/2;
            while(i != left+(right-left)/2 && j != right){
                if(arr[i]<=arr[j]){
                    temp.push_back(arr[i]);
                    i+=1;
                }else{
                    temp.push_back(arr[j]);
                    j+=1;
                }
            }
            while(i != left + (right-left)/2){
                temp.push_back(arr[i]);
                i+=1;
            }
            while(j != right){
                temp.push_back(arr[j]);
                j+=1;
            }
            for(int i = right -1 ; i >=left; i--){
                arr[i]= temp.back();
                temp.pop_back();
            }
        }
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        ans = false;
        if( !nums.empty() && nums.size() > 1){
            mergeSort(nums, 0 , nums.size());
            for(int i =1; i< nums.size() ; i++) if(nums[i] == nums[i-1]) ans = true;
        }
        return ans;
    }
};