#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        int n; cin >> n;
        ll sum = 0, cnt = 0;
        for(int i = 0; i<n; ++i){
            ll x; cin >> x;
            sum+=abs(x);
            if(x>0){
                cnt++;
            }
        }
        cout << "Case " << ++cs << ": ";
        if(cnt==0){
            cout << "inf\n"; 
        }else{
            ll x = __gcd(sum, cnt);
            cout << sum/x << "/" << cnt/x << '\n';
        }
    }
}