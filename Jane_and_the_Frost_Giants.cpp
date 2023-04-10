#include<bits/stdc++.h>
using namespace std;
char ar[205][205];
int dirr[] = {1, -1, 0, 0};
int dirc[] = {0, 0, -1, 1};
int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        queue<pair<int,int>>q;
        int n, m, starti, startj;
        cin >> n >> m;
        bool vis[n][m];
        int dis[n][m];
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                cin >> ar[i][j];
                if(ar[i][j]=='F'){
                    q.push({i,j});
                    vis[i][j] = true;
                }else{
                    vis[i][j] = false;
                }
                if(ar[i][j]=='J'){
                    starti = i;
                    startj = j;
                }
                dis[i][j] = 0;
            }
        }
        q.push({starti, startj});
        bool ans = false; int cnt = 0;
        vis[starti][startj] = true;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            vis[r][c] = true;
            q.pop();
            if(ans) break;
                for(int i = 0; i<4; ++i){
                    int row = r + dirr[i];
                    int col = c + dirc[i];
                    if(row<n and col<m and row>-1 and col>-1 and ar[row][col]=='.' and !vis[row][col]){
                        if(ar[r][c]=='F'){
                            ar[row][col] = 'F';
                        }else if((row==n-1 or col==0 or row==0 or col==m-1)){
                            cnt = dis[r][c]+1;
                            ans = true;
                            break;
                        }else{
                            ar[r][c] = '#';
                            dis[row][col] = dis[r][c]+1;
                        }
                        q.push({row,col});
                        vis[row][col] = true;
                    }
                }
        }
        cout << "Case " << ++cs << ": "; 
        if(ans) cout << cnt+1 << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}