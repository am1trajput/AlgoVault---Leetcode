class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[1]]++;
            indegree[e[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 1) q.push(i);
        }

        int left = n;
        while(left > 2) {
            int sz = q.size();
            left -= sz;
            for(int i = 0; i < sz; ++i) {
                int node = q.front(); q.pop();
                for(auto it : adj[node]) {
                    indegree[it]--;
                    if(indegree[it] == 1) q.push(it);
                }
            }
        }

        vector<int> roots;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            roots.push_back(node);
        }

        return roots;
    }
};