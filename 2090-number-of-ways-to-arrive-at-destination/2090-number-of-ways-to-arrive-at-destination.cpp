class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);

        // Build adjacency list
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        // Min-heap: (time, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // Initialize Dijkstra
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue; // Ignore outdated entries

            for (auto& [neighbor, t] : graph[node]) {
                long long new_time = time + t;

                if (new_time < dist[neighbor]) { // Found a shorter path
                    dist[neighbor] = new_time;
                    ways[neighbor] = ways[node]; // Inherit path count
                    pq.push({new_time, neighbor});
                } 
                else if (new_time == dist[neighbor]) { // Another shortest path
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};