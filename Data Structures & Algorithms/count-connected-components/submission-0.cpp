class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {
        // initialise the adj list
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // initialise visited array
        int visitedArr[n] = {0};
        int connectedComponents = 0;
        queue<int> q;
        
        for(int i=0;i<n;++i){
            if(visitedArr[i] == 0){
            connectedComponents++;
            // traverse the rest of the connected component
                q.push(i);
                visitedArr[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(!visitedArr[it]){
                        visitedArr[it] = 1;
                        q.push(it);
                        }
                    }
                }
            }
        }

        return connectedComponents;
        
    }
};
