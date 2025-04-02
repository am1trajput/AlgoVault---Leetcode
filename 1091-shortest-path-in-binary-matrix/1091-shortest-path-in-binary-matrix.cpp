class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[0][0] == 1) return -1;
        if(n == 1) return 1;
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int d = p.first;
            int x = p.second.first, y = p.second.second;

            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(i == 0 && j == 0) continue;
                    int nrow = x + i;
                    int ncol = y + j;

                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n
                    && grid[nrow][ncol] == 0 && d + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = d + 1;
                        pq.push({d + 1, {nrow, ncol}});
                        if(nrow == n - 1 && ncol == n - 1) return dist[nrow][ncol] + 1;
                    }
                }
            }
        }
        return -1;
    }
};