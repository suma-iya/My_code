#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int ar[mx];
int tree[mx*3];
void init(int node, int b, int e){
    if(b==e){
        tree[node] = ar[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = min(tree[left],tree[right]);
}
int query(int node, int b, int e, int i, int j){
    if(i>e || j<b) return INT_MAX;
    if(b>=i and e<=j) return tree[node];
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1,e, i, j);
    return min(p1,p2);
}
int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i = 1; i<=n; ++i){
            cin >> ar[i];
        }
        init(1, 1, n);
        cout << "Case " << ++cs << ":\n";
        for(int i = 0; i<q; ++i){
            int from, to;
            cin >> from >> to;
            int ans = query(1, 1, n, from, to);
            cout << ans << '\n';
        }
    }
}