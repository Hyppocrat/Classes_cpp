#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct edge{
	int left, right, value;
	char color;
	edge(): left(-1), right(-1), value(-1), color('B'){}
	edge(int left, int right, int value, char color): left(left), right(right), value(value), color('B'){}
};

pair<int, char> parent[100013];
pair<edge, edge> children[100013];
edge edges[100013];

int str_to_int(string s){
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		ans = ans * 10 + (s[i] - '0');
	}
	return ans;
}

bool check_search_tree(edge *edges, pair<edge, edge> *children, int N){
	for(int i = 1; i <= N; i++){
		if (edges[i].left != -1){
			if (children[i].first.value >= edges[i].value){
				return 0;
			}
		}
		if (edges[i].right != -1){
			if (children[i].second.value <= edges[i].value){
				return 0;
			}
		}
	}
}

bool check_colors_and_parents(edge *edges, pair<int, char> *parent, int N){
	for(int i = 1; i <= N; i++){
		if (parent[i].first == -1 && edges[i].color == 'R'){
			return 0;
		}
		if (edges[i].color != 'R' && edges[i].color != 'B'){
			return 0;
		}
		if (edges[i].color == 'R' && parent[i].first != -1){
			if (parent[i].second != 'B'){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int N, root;
	cin >> N;
	if (N == 0){
		return 0;
	}
	cin >> root;
	int t, left, right, key;
	string left_son, right_son;
	char color;
	string s;
	for(int i = 1; i <= N; i++){
		cin >> t >> key >> left_son >> right_son >> color;
		if (left_son == "null"){
			left = -1;
		}
		else {
			left = str_to_int(left_son);
		}
		if (right_son == "null"){
			right = -1;
		}
		else {
			right = str_to_int(right_son);
		}
		edges[i] = edge(left, right, key, color);
		parent[i].first = -1;
		parent[i].second = 'B';
	}
	for(int i = 1; i <= N; i++){
		edge left_v, right_v;
		if (edges[i].left == -1 ){
			left_v = edge();
		}
		else {
			left_v = edges[edges[i].left];
			parent[edges[i].left] = make_pair(i, edges[i].color);
		}
		if (edges[i].right == -1 ){
			right_v = edge();
		}
		else {
			right_v = edges[edges[i].right];
			parent[edges[i].right] = make_pair(i, edges[i].color);
		}
		children[i] = make_pair(left_v, right_v);
	}
	if (check_search_tree(edges, children, N) && check_colors_and_parents(edges, parent, N)){
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
