class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& mp, unordered_set<int>& currPath, vector<bool>& vis){
        currPath.insert(node);
        for(auto child : mp[node]){
            if(currPath.find(child) != currPath.end()) return false;
            if(!vis[child] && !dfs(child, mp, currPath, vis)) return false;
            vis[child] = true;
        }
        currPath.erase(node);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(const auto& p : prerequisites){
            mp[p[0]].push_back(p[1]);
        }

        vector<bool> vis(numCourses, false);
        unordered_set<int> currPath;

        for(int i=0;i<numCourses;++i){
            if(mp.find(i)!=mp.end() && !vis[i]){
                vis[i] = true;
                if(!dfs(i, mp, currPath, vis)) return false;
            }
        }

        return true;
    }
};
