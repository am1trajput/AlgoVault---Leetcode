class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int>> sortedQueries;
        for(int i = 0; i < queries.size(); ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        // value -> x, y
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        pq.push({grid[0][0], {0, 0}}); // src -> cell 1
        vis[0][0] = true;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int count = 0;
        vector<int> ans(queries.size());
        for(auto &[value, idx] : sortedQueries) {
            while(!pq.empty() && pq.top().first < value) {
                auto p = pq.top(); pq.pop();
                int val = p.first;
                int row = p.second.first;
                int col = p.second.second;
                count++;
                for(int i = 0; i < 4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol]) {
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                        vis[nrow][ncol] = true;
                    }
                }
            }
            ans[idx] = count;
        }

        return ans;
    }
};