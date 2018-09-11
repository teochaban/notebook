#include <bits/stdc++.h>
#define MAXN 3000
typedef long long ll;

using namespace std;

int n;
int g[MAXN][MAXN], rg[MAXN][MAXN], parent[MAXN];

bool bfs(int source, int sink){
	bool visited[MAXN];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(source);
	visited[source] = true;
	parent[source] = -1;
	while(!q.empty()){
		int i = q.front();
		q.pop();
		for(int j = 0; j < MAXN; j++){
			if(!visited[j] && rg[i][j] > 0){
				q.push(j);
				parent[j] = i;
				visited[j] = true;
			}
		}
	}
	return visited[sink];
}

int maxFlow(int source, int sink){
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			rg[i][j] = g[i][j];
		}
	}
	int max_flow = 0;
	while(bfs(source, sink)){
		int path_flow = 99999999;
		for(int i = sink; i != source; i = parent[i]){
			int j = parent[i];
			path_flow = min(path_flow, rg[j][i]);
		}
		for(int i = sink; i != source; i = parent[i]){
			int j = parent[i];
			rg[j][i] -= path_flow;
			rg[i][j] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			rg[i][j] = g[i][j] = 0;
		}
	}
}
