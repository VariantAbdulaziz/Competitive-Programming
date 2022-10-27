class Solution {
public:
    int find(vector<int>& link, int p){
        if(p != link[p]){
            link[p] = find(link, link[p]);
        }
        return link[p];
    }
    bool cluster(vector<int>& link, vector<int>& rank, int l, int r){
        int lr = find(link, l);
        int rr = find(link, r);
        if(lr == rr) return false;
        if(rank[lr] < rank[rr]) swap(lr, rr);
        rank[lr] += rank[rr];
        link[rr] = lr;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // for each edge query if it is redundant or not(if there already exist that connection or not)
        vector<int> link(edges.size() + 1); iota(begin(link), end(link), 0);
        vector<int> rank(edges.size() + 1, 1);
        
        for(auto edge: edges){
            if(!cluster(link, rank, edge[0], edge[1])) return edge;
        }
        return vector<int>();
    }
};