class Solution {
    int ans, m_HashTable[101],temp;
    
    void perimeterPerRow(vector<int>& arr, int size ){
        temp = 0;
        for(int i = 0; i<size ; i++ ) {
            if(temp != arr[i]){
                ans+=1;
                temp = arr[i];
            }
            if(m_HashTable[i] != arr[i] ) ans+=1;
            m_HashTable[i] = arr[i];
        }
        if(arr[size-1] ==1) ans+=1;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ans = 0;
        for(int i =0; i <= grid[0].size() ; i++) m_HashTable[i] = 0;
        for(int j = 0; j < grid.size() ; j++){
            perimeterPerRow(grid[j] , grid[j].size());
        }
        int temp = grid.size() -1;
        for(int k = 0; k < grid[temp].size() ; k++ ) if(grid[temp][k]==1) ans+=1;
        return ans;
    }
};