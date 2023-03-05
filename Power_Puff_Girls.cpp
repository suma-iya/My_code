#include<bits/stdc++.h>
using namespace std;
int dirr[] = {0, 0, -1, 1};
int dirc[] = {-1, 1, 0, 0};
bool vis[25][25];
char ar[25][25];
int dis[25][25];
int n , m, mx = 0;
int bfs(int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j]=true;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(ar[a][b]=='a' or ar[a][b]=='b' or ar[a][b]=='c'){
            mx = max(mx, dis[a][b]);
        }
        for(int k = 0; k<4; ++k){
            int r = a+dirr[k];
            int c = b+dirc[k];
            if(r>=0 and c>=0 and r<n and c<m and !vis[r][c] and ar[r][c]!='#' and ar[r][c]!='m'){
                vis[r][c]= true;
                q.push({r,c});
                dis[r][c] = dis[a][b]+1;
            }
        }
    }
    return mx;
}

int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                dis[i][j]=0;
                vis[i][j]=0;
            }
        }
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                cin >> ar[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(ar[i][j]=='h'){
                    ans = bfs(i, j);
                    mx = 0;
                }
            }
        }
        cout << "Case " << ++cs << ": " << ans << '\n';
    }
}