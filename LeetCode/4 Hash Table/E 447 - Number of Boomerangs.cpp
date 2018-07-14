class Solution {
    int temp1, ans,n;
    vector<int> distance, temp;
    
    int m_DistanceSquare(int x1,int y1, int x2, int y2){ return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1); }
    
    void mergeSort(vector<int>& arr, int left , int right){
        if(right - left > 1){
            mergeSort(arr, left, left +(right-left)/2);
            mergeSort(arr, left+(right-left)/2 , right);
            int i = left, j = left + (right-left)/2;
            while(i != left + (right-left)/2 && j != right){
                if(arr[i]<= arr[j]){
                    temp.push_back(arr[i]);
                    i+=1;
                }else{
                    temp.push_back(arr[j]);
                    j+=1;
                }
            }
            while(i != left + (right-left)/2 ){
                temp.push_back(arr[i]);
                i+=1;
            }
            while(j != right){
                temp.push_back(arr[j]);
                j+=1;
            }
            for(i = right-1; i>=left; i--){
                arr[i] = temp.back();
                temp.pop_back();
            }
        }
    }
    
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        ans = 0;
        int i,j;
        for( i =0 ; i<points.size() ; i++){
            while(!distance.empty()) distance.pop_back();
            for(j = 0; j<points.size() ; j++){
                if(i == j) continue;
                temp1 = m_DistanceSquare(points[i].first, points[i].second, points[j].first,points[j].second);
                distance.push_back(temp1);
            }
            mergeSort(distance,0, distance.size());
            n=1;
            for(j =1 ; j<distance.size(); j++){
                if(distance[j] == distance[j-1]) n+=1;
                else{
                    ans+= (n*(n-1))/2;
                    n = 1;
                }
            }
            ans+= (n*(n-1))/2;
        }
        return 2*ans;
        
    }
};