/*
    Mainly if a person says 1 people supporting the team other than him, that means they are 
    basically 2 people supporting that team. So before putting the value we need to add 1 with
    the input.
    As we need to find minimum possible population, we will save each number and their counts
    and calculate it using map
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        int n; cin >> n;
        map<int,int>m;
        for(int i = 0; i<n; ++i){
            int x; cin >> x;
            m[++x]++;
        }
        int ans = 0;
        for(auto it = m.begin(); it!=m.end(); ++it){
            int num = it->first, cnt = it->second;
            ans+=(cnt/num)*num;
            if(cnt%num!=0) ans+=num;
        }
        cout << "Case " << ++cs << ": " << ans << '\n';
    }
} 
