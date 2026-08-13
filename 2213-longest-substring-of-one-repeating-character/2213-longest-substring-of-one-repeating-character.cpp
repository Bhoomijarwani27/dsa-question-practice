class Solution {
    struct Node {
        int len;
        int pre;
        int suf;
        int best;
        char left;
        char right;

        Node(int len = 0, int pre = 0, int suf = 0,
             int best = 0, char left = '#', char right = '#')
            : len(len), pre(pre), suf(suf),
              best(best), left(left), right(right) {}
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        Node res;

        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pre = a.pre;
        res.suf = b.suf;

        res.best = max(a.best, b.best);

        if (a.right == b.left) {
            // Join suffix of left + prefix of right
            res.best = max(res.best, a.suf + b.pre);

            // Entire left segment has same character
            if (a.pre == a.len)
                res.pre = a.len + b.pre;

            // Entire right segment has same character
            if (b.suf == b.len)
                res.suf = a.suf + b.len;
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = Node(1, 1, 1, 1, s[l], s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2],
                          seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            seg[node] = Node(1, 1, 1, 1, c, c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, c);
        else
            update(node * 2 + 1, mid + 1, r, pos, c);

        seg[node] = merge(seg[node * 2],
                          seg[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};