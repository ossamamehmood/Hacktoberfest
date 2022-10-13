class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, vector<string>& v) {

		auto check = [&](string & A, string & B) {  //lambda function
			int cnt = 0;
			for (int i = 0; i < A.size(); i++) {
				cnt += (A[i] != B[i]);
			}
			return cnt == 1;
		};

		v.push_back(start);
		int n = (int)v.size();
		vector<vector<int>> adj(n);

		int desti = -1;
		for (int i = 0; i < n; i++) {
			if (v[i] == end) desti = i;
			for (int j = i + 1; j < n; j++) {
				if (check(v[i], v[j])) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		if (desti == -1) {
			return {};
		}

		vector<int> dis(n, INT_MAX); //min distance from source to every other node
        
		auto bfs = [&](int start) { //lambda function
			dis[start] = 0;
			queue<int> Q;
			Q.push(start);

			while (!Q.empty()) {
				int curr = Q.front();
				Q.pop();
				for (auto &to : adj[curr]) {
					if (dis[to] != INT_MAX) {
						continue;
					}
					dis[to] = dis[curr] + 1;
					Q.push(to);
				}
			}
		};
		bfs(n - 1);

		vector<vector<string>> res;
		vector<string> curr = {v[desti]}; //dfs from destination and backtrack for every path

		function<void(int)> dfs = [&](int u) { //recursive lambda function
			if (u == n - 1) {//reached source add this path and return
				res.emplace_back(curr.rbegin(), curr.rend());
				return;
			}
			for (auto &to : adj[u]) {
                //we are going from back so distance at each step should decrease by one
				if (dis[to] == dis[u] - 1) { 
					curr.push_back(v[to]);
					dfs(to);
					curr.pop_back(); //backtracking
				}
			}
		};
		dfs(desti);

		return res;
	}
};
