class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n){
        rank.assign(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1;i <= n;i++)
            parent[i] = i;
    }
    int find_set(int v) {
        if (parent[v] == v)
            return v;
        return v = find_set(parent[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
            } else if (rank[b] < rank[a]) {
                parent[b] = a;
            } else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (vector<int> edge: edges) {
            int a = uf.find_set(edge[0]);
            int b = uf.find_set(edge[1]);
            if (a != b) {
                uf.union_set(a, b);
            } else
                return edge;
        }
        return {};
    }
};
