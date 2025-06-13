class Solution {
public:
    struct Node {
        int value;
        int row;
        int col;
        Node(int v, int r, int c) : value(v), row(r), col(c) {}
    };

    struct Compare {
        bool operator()(const Node& a, const Node& b) {
            return a.value > b.value; // Min-heap
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<Node, vector<Node>, Compare> pq;
        int maxi = INT_MIN;

        // Insert the first element from each list
        for (int i = 0; i < k; i++) {
            int val = nums[i][0];
            pq.push(Node(val, i, 0));
            maxi = max(maxi, val);
        }

        int start = pq.top().value, end = maxi;

        while (true) {
            Node curr = pq.top();
            pq.pop();

            int mini = curr.value;

            // Update range if it's smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // If next element exists in the same row, push it
            if (curr.col + 1 < nums[curr.row].size()) {
                int nextVal = nums[curr.row][curr.col + 1];
                maxi = max(maxi, nextVal);
                pq.push(Node(nextVal, curr.row, curr.col + 1));
            } else {
                // One list is exhausted
                break;
            }
        }

        return {start, end};
    }
};