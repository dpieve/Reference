/*
    Dynamic  Segment Tree
    Implicit Segment Tree
    Sparse   Segment Tree
    
    SegTree st(0, MAXV);
    st.update(pos, val); -> point update
    st.query(a, b);      -> range query  
*/

const int MAXV = 1e9;

struct Node {
    int sum, left, right;
    Node(int L_id = -1, int R_id = -1): sum(0), left(L_id), right(R_id) { }
};
 
struct SegTree {
 
    const int left, right;
    
    vector<Node> t;

    void extend(int id, int l, int r) {      
        if (t[id].left == -1) {

            t.push_back(Node());
            t[id].left = (int)t.size() - 1;
 
            t.push_back(Node());
            t[id].right = (int)t.size() - 1;
        
        }
    }
 
    void update(int id, int l, int r, int pos, int val) {
        if (pos < l || pos > r) 
            return;
        
        if (l == r) {
            t[id].sum += val;
            return;
        }
 
        extend(id, l, r);
 
        int L_id = t[id].left;  
        int R_id = t[id].right;        
        int m = l + (r - l) / 2;
 
        if (pos <= m) update(L_id,  l, m, pos, val);
        else update(R_id,m+1, r, pos, val);
 
        t[id].sum = t[L_id].sum + t[R_id].sum;
    }
 
    void update(int pos, int val) { return update(0, left, right, pos, val); }
 
    int query(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) 
            return t[id].sum;
 
        if (l > r || qr < l || ql > r)
            return 0;
 
        extend(id, l, r);
 
        int L_id = t[id].left;  
        int R_id = t[id].right;    
        int m = l + (r - l) / 2;
 
        return query(L_id, l, m, ql, qr) + query(R_id, m+1, r, ql, qr);
    }
 
    int query(int L, int R) { return query(0, left, right, L, R); }
 
    SegTree(int l, int r) : left(l), right(r) {
        t.reserve((1u << 23));  // MAX Size -> 2 ^ 23 = 8388608 Nodes    
        t.push_back(Node());
    }
};
