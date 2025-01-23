//1267. Count Servers that Communicate
//https://leetcode.com/problems/count-servers-that-communicate/description/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> r(grid.size());
        vector<int> c(grid[0].size());
        for(int i = 0 ;i < grid.size();i++){
            for(int j =0 ; j< grid[0].size();j++){
                r[i]+= grid[i][j];
                c[j] += grid[i][j]; 
            }
        }
        int count =0;
        for(int i = 0 ;i < grid.size();i++){
            for(int j =0 ; j< grid[0].size();j++){
                if(grid[i][j]==1 && (r[i]>1 || c[j]>1)){
                    count++;
                }
            }
        }
        return count;
    }
};