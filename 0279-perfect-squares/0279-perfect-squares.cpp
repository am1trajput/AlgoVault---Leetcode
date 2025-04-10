class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n + 1, false); // To avoid revisiting
        q.push(n);
        visited[n] = true;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int i = 0; i < size; ++i) {
                int num = q.front();
                q.pop();

                for (int j = 1; j * j <= num; ++j) {
                    int next = num - j * j;
                    if (next == 0) return level;
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }

        return -1;
    }
};
