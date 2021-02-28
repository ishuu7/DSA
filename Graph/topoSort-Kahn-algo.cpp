// Kahn's Algo
vector<int> toposort(vector<vector<int>>& G, int n) {

        vector<bool> vis(n + 1, false);
        vector<int> inDegree(n + 1, 0);
        for(int i = 1; i <= n; i++) {
                for(auto &it : G[i]) {
                        inDegree[it]++;
                }
        }

        queue<int> q;

        for(int i = 1; i <= n; i++) {
                if(inDegree[i] == 0) {
                        q.push(i);
                        vis[i] = true;
                }
        }
        vector<int> ans;
        while(q.size()) {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto &it : G[curr]) {
                        if(!vis[it]) {
                                inDegree[it]--;
                                if(inDegree[it] == 0) {
                                        q.push(it);
                                        vis[it] = true;
                                }
                        }
                }
        }
        return ans;
}
