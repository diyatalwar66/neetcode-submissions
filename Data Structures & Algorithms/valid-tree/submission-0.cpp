class Solution {
public:
    bool checkDfs(int node, int parent, unordered_map<int, vector<int>>& mp, vector<bool>& vis){
        vis[node] = true;
        for(auto child : mp[node]){
            if(child==parent) continue;
            else if(vis[child]) return false;
            else {
                vis[child] = true;
                if(!checkDfs(child, node, mp, vis)) return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        if(!checkDfs(0, -1, mp, vis)) return false;
        for(int i=0;i<n;++i){
            if(!vis[i]) return false;
        }

        return true;
    }
};
