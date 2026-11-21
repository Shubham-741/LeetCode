class Solution {
public:

    unordered_map<int,vector<int>>adj;
    vector<int> resultSize;
    vector<int> last;

    void dfs(int curr, string &s, vector<int>& parent){
        int c = s[curr]-'a';

        int nearestAncestor = last[c];

        last[c]=curr;

        for(int child : adj[curr]){
            dfs(child, s, parent);
        }

        // back to current node

        last[c] = nearestAncestor;

        if (curr != 0){
            int newParent = parent[curr];

            if (nearestAncestor != -1){
                newParent = nearestAncestor;
            }

            parent[curr] = newParent;

            resultSize[newParent] += resultSize[curr];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        for(int i = 1; i<n; i++){
            int u = parent[i];
            int v = i;

            adj[u].push_back(v);
        }

        resultSize.assign(n,1);
        last.assign(26,-1);

        dfs(0,s,parent);

        return resultSize;
        
    }
};