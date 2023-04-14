#include<bits/stdc++.h>
using namespace std;

map<int,int>money;
vector<int>adj[1010];
bool vis[1010];
bool ans = true;
int sum = 0, num = 0;
void clr(){
    money.clear();
    memset(vis, 0, sizeof vis);
    ans = true;
    for(int i = 0; i<1010; ++i){
        adj[i].clear();
    }
}
void dfs(int node){
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int par = q.front();
        vis[par] = true;
        num++;
        sum+=money[par];
        q.pop();
        for(auto ch : adj[par]){
            if(!vis[ch]){
                vis[ch] = true;
                q.push(ch);
            }
        }
    }
}
int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        clr();
        int n, m;
        cin >> n >> m;
        int total = 0;
        for(int i = 1; i<=n; ++i){
            int x; cin>> x;
            money[i] = x;
            total += x;
        }
        for(int i = 0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(total%n!=0){
            ans = false;
        }else{
            int avg = total/n;
            for(int i = 1; i<n+1; ++i){
                if(!vis[i]){
                    sum = 0;
                    num = 0;
                    dfs(i);
                    if(sum%num!=0){
                        ans = false;
                    }else if(sum/num!=avg){
                        ans = false;
                    }
                }
            }
        }
        cout << "Case " << ++cs << ": ";
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
}