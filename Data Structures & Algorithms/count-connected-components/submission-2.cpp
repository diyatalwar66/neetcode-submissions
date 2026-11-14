class Solution {
public:
    void dfs(int node, int parent, unordered_map<int, vector<int>>& mp, vector<bool>& vis){
        vis[node] = true;
        for(auto child : mp[node]){
            if(child == parent) continue;
            if(!vis[child]) dfs(child, node, mp, vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        vector<bool> vis(n, false);
        int count = 0;

        for(const auto& e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        for(int i=0;i<n;++i){
            if(!vis[i]){
                count++;
                dfs(i, -1, mp, vis);
            }
        }

        return count;
    }
};
