struct BinaryLifting {
	int n;
	int maxLog;
	ll maxRequirement;
	vector<vector<int>> parent;
	vector<int> *edges;
	vector<int> logValues;
	bool precomputedLogs = false;
	BinaryLifting(int n1, vector<int> *edges1, ll requirement, int root) {
		n = n1;
		edges = edges1;
		parent.resize(n);
		maxLog = log2(requirement + 1);
		maxRequirement = requirement;
		for (int i = 0; i < n; i++) {
			parent[i].resize(maxLog + 1);
			for (int j = 0; j <= maxLog; j++) {
				parent[i][j] = -1;
			}
		}
		fillParentTable(root);
		if (maxRequirement <= 1000000LL)
			precomputeLogs();
	}
	BinaryLifting() {}
	void fillParentTable(int root) {
		vector<bool> visited(n);
		dfsBinaryLifting(root, visited);
		int intermediate = -1;
		for (int i = 1; i <= maxLog; i++) {
			for (int j = 0; j < n; j++) {
				intermediate = parent[j][i - 1];
				if (intermediate != -1) {
					parent[j][i] = parent[intermediate][i - 1];
				}
			}
		}
	}
	void dfsBinaryLifting(int root, vector<bool> &visited) {
		visited[root] = true;
		for (auto i : edges[root]) {
			if (!visited[i]) {
				parent[i][0] = root;
				dfsBinaryLifting(i, visited);
			}
		}
	}
	void precomputeLogs() {
		precomputedLogs = true;
		logValues.resize(maxRequirement + 1);
		logValues[1] = 0;
		for (int i = 2; i <= maxRequirement; i++) {
			logValues[i] = logValues[i / 2] + 1;
		}
	}
	int kthParent(int start, int k) {
		int a = start;
		while (k > 0) {
			int x = getLog(k);
			a = parent[a][x];
			if (a == -1)
				return a;
			k -= (1 << x);
		}
		return a;
	}
	int getLog(ll x) {
		return precomputedLogs ? logValues[x] : log2(x);
	}
};

// No need to change anything here
struct LCA {
	int n;
	BinaryLifting *bl_object;
	vector<int> level;
	vector<int> *edges;
	LCA(int n1, vector<int> *edges1, int root, BinaryLifting *bl) {
		n = n1;
		bl_object = bl;
		edges = edges1;
		level.resize(n);
		dfsLCA(root, -1);
	}
	LCA() {}
	void dfsLCA(int root, int parent) {
		for (auto i : edges[root]) {
			if (i != parent) {
				level[i] = level[root] + 1;
				dfsLCA(i, root);
			}
		}
	}
	int getLCA(int a, int b) {
		if (level[a] > level[b]) {
			swap(a, b);
		}
		b = bl_object->kthParent(b, level[b] - level[a]);
		if (a == b)
			return a;
		for (int i = bl_object->maxLog; i >= 0; i--) {
			int parent1 = bl_object->parent[a][i];
			int parent2 = bl_object->parent[b][i];
			if (parent2 != parent1 && parent1 != -1 && parent2 != -1) {
				a = parent1;
				b = parent2;
			}
		}
		return bl_object->parent[a][0];
	}
};


template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<ll> arr; // type may change
	int n;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		tree.resize(4 * n); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	SegTree() {}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	ll val; // may change
	Node1() { // Identity element
		val = -INF;	// may change
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = max(l.val, r.val);  // may change
	}
};

struct Update1 {
	ll val; // may change
	Update1(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};
template<typename Node, typename Update>
struct HLD {
	int n;
	int rootHere;
	vector<int> *edges;
	vector<int> big_child;
	vector<int> subtree_sum;
	vector<int> chain;
	vector<int> label;
	vector<ll> values;
	SegTree<Node, Update> s1;
	LCA *lca_object;
	BinaryLifting *bl_object;
	HLD(int n1, vector<int> *edges1, int root1, vector<ll> &values1, LCA *lca) {
		n = n1;
		lca_object = lca;
		bl_object = lca->bl_object;
		edges = edges1;
		rootHere = root1;
		big_child.resize(n);
		subtree_sum.resize(n);
		label.resize(n);
		chain.resize(n);
		values = values1;
		dfsPrecompute(rootHere, -1);
		int label_time = 0;
		dfsLabels(rootHere, -1, label_time);
		for (int i = 0; i < n; i++)
			chain[i] = i;
		dfsChains(rootHere, -1);
		s1 = SegTree<Node, Update>(n, values);
		for (int i = 0; i < n; i++) {
			s1.make_update(label[i], values[i]);
		}
		// debugHLD();
	}
	void dfsPrecompute(int root, int parent) {
		subtree_sum[root] = 1;
		big_child[root] = -1;
		int biggest = -1;
		for (auto i : edges[root]) {
			if (i != parent) {
				dfsPrecompute(i, root);
				subtree_sum[root] += subtree_sum[i];
				if (subtree_sum[i] > biggest) {
					big_child[root] = i;
					biggest = subtree_sum[i];
				}
			}
		}
	}
	void dfsLabels(int root, int parent, int &label_time) {
		label[root] = label_time++;
		if (big_child[root] != -1)
			dfsLabels(big_child[root], root, label_time);
		for (auto i : edges[root])
			if (i != parent && i != big_child[root])
				dfsLabels(i, root, label_time);
	}
	void dfsChains(int root, int parent) {
		if (big_child[root] != -1)
			chain[big_child[root]] = chain[root];
		for (auto i : edges[root])
			if (i != parent)
				dfsChains(i, root);
	}
	void debugHLD() {
		debug(big_child);
		debug(subtree_sum);
		debug(chain);
		debug(label);
		debug(values);
	}
	Node queryChain(int here, int toReach) {
		Node val = Node(0);
		int top;
		while (lca_object->level[here] > lca_object->level[toReach]) {
			top = chain[here];
			if (lca_object->level[top] <= lca_object->level[toReach])
				top = bl_object->kthParent(here, lca_object->level[here] - lca_object->level[toReach] - 1);
			Node a1 = val;
			Node a2 = s1.make_query(label[top], label[here]);
			val.merge(a1, a2);
			here = bl_object->parent[top][0];
		}
		return val;
	}
	ll findAnswer(int u, int v) {
		int lca = lca_object->getLCA(u, v);
		Node n1 = queryChain(u, lca);
		Node n2 = queryChain(v, lca);
		Node merged;
		merged.merge(n1, n2);
		Node n3 = Node(s1.make_query(label[lca], label[lca]));
		Node ans;
		ans.merge(merged, n3);
		return ans.val;
	}
	void makeUpdateatIndex(int u, ll val) {
		s1.make_update(label[u], val);
	}
};
// Change accordingly for edge weights instead of node values
void solve() {
	int n, q;
	cin >> n >> q;
	vector<ll> values(n);
	for (int i = 0; i < n; i++)
		cin >> values[i];
	vector<int> *edges = new vector<int>[n];
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a - 1].pb(b - 1);
		edges[b - 1].pb(a - 1);
	}
	BinaryLifting bl_object = BinaryLifting(n, edges, n, 0);
	LCA lca_object = LCA(n, edges, 0, &bl_object);
	HLD<Node1, Update1> hld = HLD<Node1, Update1>(n, edges, 0, values, &lca_object);
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			hld.makeUpdateatIndex(b - 1, c);
		} else {
			cout << hld.findAnswer(b - 1, c - 1) << " ";
		}
	}
}
