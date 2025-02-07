//https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07
// 3160 find-the-number-of-distinct-colors-among-the-balls
class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            unordered_map<int, int> ballColor;
            unordered_map<int, int> colorCount;
            vector<int> result;
            result.reserve(queries.size());
            int distinctColors = 0;
    
            for (auto& query : queries) {
                int ball = query[0], newColor = query[1];
    
                if (ballColor.count(ball)) {
                    int oldColor = ballColor[ball];
                    if (--colorCount[oldColor] == 0) 
                        distinctColors--;
                }
    
                ballColor[ball] = newColor;
                if (++colorCount[newColor] == 1) 
                    distinctColors++;
    
                result.push_back(distinctColors);
            }
            return result;
        }
    };
    