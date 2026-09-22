class Solution {
public:

    struct Node {
        int prod = 1;
        long long cnt[5] = {};
    };

    int k;

    Node merge(Node left, Node right) {

        Node res;


        res.prod = (left.prod * right.prod) % k;


        for(int r = 0; r < k; r++) {
            res.cnt[r] = left.cnt[r];
        }


        for(int r = 0; r < k; r++) {
            res.cnt[(left.prod * r) % k] += right.cnt[r];
        }

        return res;
    }

    vector<Node> tree;

    void build(int node, int l, int r, vector<int>& nums) {

        if(l == r) {
            int val = nums[l] % k;

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {

        if(l == r) {

            val %= k;

            tree[node] = Node();

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        if(ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if(qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if(ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {

        k = K;

        int n = nums.size();

        tree.resize(4 * n);

        for(int &x : nums)
            x %= k;

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for(auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];


            update(1, 0, n - 1, index, value);


            Node res = query(1, 0, n - 1,
                             start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};