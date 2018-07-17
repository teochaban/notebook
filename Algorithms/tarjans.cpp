#include <bits/stdc++.h>
#define MAXN 300100
typedef long long ll;

using namespace std;

int n, m, cost[MAXN], idx[MAXN], lowlink[MAXN], index = 0;
bool onStack[MAXN];
vector<int> g[MAXN];
vector<vector<int> > components;

stack<int> s;

void tarjans(int x){
     lowlink[x] = idx[x] = index++;
     s.push(x);
     onStack[x] = true;
     for(int i = 0; i < g[x].size(); i++){
        int w = g[x][i];
        if(idx[w] == -1){
            tarjans(w);
            lowlink[x] = min(lowlink[x], lowlink[w]);            
        } else if(onStack[w]){  //backedge
            lowlink[x] = min(lowlink[x], idx[w]);
        }
     }
     if(lowlink[x] == idx[x]){
    //cout << x;
        vector<int> v;
        int w = s.top();
        while(true){
            s.pop();
            onStack[w] = false;
            v.push_back(w);
            if(w == x) break;
            w = s.top();
        }
        components.push_back(v);
     }
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> cost[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	g[a - 1].push_back(b - 1);
    }
    for(int i = 0; i < n; i++){
        idx[i] = -1;
        onStack[i] = false;
    }
    for(int i = 0; i < n; i++){
        if(idx[i] == -1) tarjans(i);
    }
    ll ans1 = 0, ans2 = 1;
    for(int i = 0; i < components.size(); i++){
        vector<int> v = components[i];
        ll mi = 9999999999, num = 0;
        for(int j = 0; j < v.size(); j++){
            //cout << v[j];
            if(cost[v[j]] < mi){
                mi = cost[v[j]];
                num = 1;
            } else if(cost[v[j]] == mi){
                num++;
            }
        }
        //cout << "\n";
        ans1 += mi;
        ans2 *= num;
        ans2 %= 1000000007;
    }
    cout << ans1 << ' ' << ans2;
}
