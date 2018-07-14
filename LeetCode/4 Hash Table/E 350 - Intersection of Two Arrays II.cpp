class Solution {
    int p,q;
    vector<int> ans;
    
    void mergeSort(vector<int>& arr, int left, int right){
        if(right - left != 1 ){
            mergeSort(arr , left , left+(right-left)/2);
            mergeSort(arr, left+(right-left)/2 , right);
            int i = left, j = left+(right-left)/2;
            while( i != left+(right-left)/2 && j != right){
                if(arr[i] <= arr[j] ){
                    ans.push_back(arr[i]);
                    i+=1;
                }else{
                    ans.push_back(arr[j]);
                    j+=1;
                }
            }
            while( i != left+(right-left)/2){
                ans.push_back(arr[i]);
                i+=1;
            }
            while( j != right ){
                ans.push_back(arr[j]);
                j+=1;
            }
            for(i = right-1 ; i>=left ; i--){
                arr[i] = ans.back();
                ans.pop_back();
            } 
        }
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        while(!ans.empty()) ans.pop_back();
        if( nums1.empty() || nums2.empty() ) return ans;
        mergeSort(nums1, 0 , nums1.size());
        mergeSort(nums2, 0 , nums2.size());
        p = 0;
        q = 0;
        while( p < nums1.size() && q < nums2.size() ){
            if(nums1[p] < nums2[q] ) p+=1;
            else if(nums1[p] > nums2[q]) q+=1;
            else{
                ans.push_back(nums1[p]);
                p+=1;
                q+=1;
            }
        }
        return ans;
    }
};
