class Solution {
public:
    double dfs(string node, string end, unordered_map<string, vector<pair<string, double>>> &adj, 
    unordered_map<string, bool> &vis) {
        if(node == end) return 1.0;
        vis[node] = true;
        for(auto it : adj[node]) {
            if(!vis[it.first]) {
                double val = dfs(it.first, end, adj, vis);
                if(val != -1) {
                    return it.second * val;
                }
            }
        }

        // if no path found
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
    vector<double>& values,
    vector<vector<string>>& queries) {
        int n = values.size();
        // Creating an undirected weighted graph where weight is divison a / b
        // Storing a / b as weight -> {a : [{b, div}]}
        // Storing b / a inverse as {b : [a, inv]}
        unordered_map<string, vector<pair<string, double>>> adj(n);
        for(int i = 0; i < n; ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double div = values[i];
            double inv = div == 0 ? INT_MAX : 1 / div;
            adj[a].push_back({b, div});
            adj[b].push_back({a, inv});
        }

        vector<double> ans;
        for(auto &q : queries) {
            string a = q[0];
            string b = q[1];
            // To evaluate a / b
            
            // Case 1: a || b do not exist in the graph -> -1
            if(adj.find(a) == adj.end() || adj.find(b) == adj.end()) ans.push_back(-1);
            
            // Case 2: a == b:
            else if(a == b) ans.push_back(1);

            // Case 3: If no direct edge btw a and b (check for path a -> ... -> b)
            else {
                unordered_map<string, bool> vis;
                double val = dfs(a, b, adj, vis);
                ans.push_back(val);
            }
        }

        return ans;
    }
};