#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>>m;
map<string,int>vis;
bool ok = true;
set<string>s;
void dfs(string par){
    vis[par] = 1;
    for(auto ch : m[par]){
        if(!vis[ch]){
            dfs(ch);
        }else if(vis[ch]==1){
            ok = false;
            break;
        }
    }
    vis[par] = 2;
}

void clear(){
    ok = true;
    s.clear();
    m.clear();
    vis.clear();
}

int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        clear();
        int n; cin >> n;
        for(int i = 0; i<n; ++i){
            string a, b;
            cin >> a >> b;
            m[a].push_back(b);
            vis[a] = vis[b] = 0;
            s.insert(a); s.insert(b);
        }
        for(auto it = s.begin(); it!=s.end(); ++it){
            dfs(*it);
            if(!ok) break;
        }
        cout << "Case " << ++cs << ": ";
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
