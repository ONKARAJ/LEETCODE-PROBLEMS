class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() : leftChar(0), rightChar(0),
                 prefix(0), suffix(0), best(0), len(0) {}

        Node(char c) : leftChar(c), rightChar(c),
                       prefix(1), suffix(1), best(1), len(1) {}
    };

    vector<Node> tree;

    Node merge(Node &a, Node &b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.len = a.len + b.len;

        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            // Run crossing the boundary
            res.best = max(res.best, a.suffix + b.prefix);

            // Entire left segment is the prefix
            if (a.prefix == a.len)
                res.prefix = a.len + b.prefix;

            // Entire right segment is the suffix
            if (b.suffix == b.len)
                res.suffix = a.suffix + b.len;
        }

        return res;
    }

    void build(int node, int l, int r, const string &s) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();
        int k = queryCharacters.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            // Root represents the entire string.
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};