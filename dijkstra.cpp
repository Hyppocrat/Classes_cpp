#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct edge{
	int u, time, cups;
};
bool can(const vector<vector<edge> > &gr, int k, int n){
	vector <int> d(n + 1, 1e9);
	set< pair<int, int> > st;
	d[1] = 0;
	st.insert(make_pair(d[1], 1));
	while (!st.empty()){
		int v = st.begin() ->second;
		st.erase(st.begin());
		for(int i = 0; i < gr[v].size(); i++){
			int to = gr[v][i].u, len = gr[v][i].time, c = gr[v][i].cups;
			if (c >= k){
				if (d[v] + len < d[to]){
                    st.erase(make_pair(d[to], to));
                    d[to] = d[v] + len;
                    st.insert(make_pair(d[to], to));
                }
			}
		}
	}
	return (d[n] <= 1440);
}
int main(){
	int n, m;
	cin >> n >> m;
	if (n == 1){
		cout << 10000000;
		return 0;
	}
	vector< vector<edge> > gr(n + 1);
	int u, v, t;
	long long w;
	edge e;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> t >> w;
		e.u = u;
		e.time = t;
		w = (w - 3e6) / 100;
		e.cups = w;
		gr[v].push_back(e);
		e.u = v;
		gr[u].push_back(e);
	}
	int l = 0, r = 10000000;
	int ans = 0;
	while (l < r){
		int m = (l + r) >> 1;
		if (can(gr, m, n)){
			ans = m;
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	if (can(gr, l, n)){
		ans = l;
	}
	cout << ans;
}
