class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // for each edge query if it is redundant or not(if there already exist that connection or not)
        vector<int> link(edges.size() + 1);
        int count = 0;
        generate(link.begin(), link.end(), [&](){return count++;});
        vector<int> rank(edges.size() + 1, 1);
        
        auto find = [&](auto&& find, int p) -> int{
            if(p != link[p]){
                link[p] = find(find, link[p]);
            }
            return link[p];
        };
        auto cluster = [&](int l, int r){
            int lr = find(find, l);
            int rr = find(find, r);
            if(lr == rr) return false;
            if(rank[lr] < rank[rr])
                swap(lr, rr);

            rank[lr] += rank[rr];
            link[rr] = lr;
            return true;
        };
        
        for(auto edge: edges){
            if(!cluster(edge[0], edge[1])) return edge;
        }
        return vector<int>();
    }
};