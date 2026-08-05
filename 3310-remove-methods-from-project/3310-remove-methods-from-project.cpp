class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Graph - Adjacency List
        vector<vector<int>> adj(n);
        vector<bool> suspicious(n, false);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // BFS to mark all suspicious methods
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            for (int ngbr : adj[curr]) {
                if (!suspicious[ngbr]) {
                    suspicious[ngbr] = true;
                    que.push(ngbr);
                }
            }
        }

        // Check if any non-suspicious method calls a suspicious one
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return remaining methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                result.push_back(i);
        }

        return result;
    }
};