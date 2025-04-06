typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n + 1);
        for(auto &e : times) {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            adj[u].push_back({v, t});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(auto it : adj[node]) {
                int neigh = it.first;
                int time1 = it.second;
                if(time + time1 < dist[neigh]) {
                    dist[neigh] = time + time1;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};