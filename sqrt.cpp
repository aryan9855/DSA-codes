//https://leetcode.com/problems/sqrtx/description/
//Implement int sqrt(int x)
class Solution {
public:
    int mySqrt(int x) {
        long long int y ;
        for(long long int i = 0 ; i<=x ; i++){
            y = i*i;
            if(y>x){
                y=i-1;
                break;
            }
            if(y==x){
                y=i;
                break;
            }
        }
        return y;
    }
};