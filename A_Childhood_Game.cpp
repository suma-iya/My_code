/* This is a problem based on game theory. By calculating the losing state and winning state it can be solved.
Without applying game theory it can also be solved by checking patterns which is easier.
For Alice, everytime when n%3==1, Bob wins.
For Bob, everytime when n/3==0, Alice wins.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    int cs = 0;
    while(t--){
        int n; cin >> n;
        string name; cin >> name;
        cout << "Case " << ++cs << ": ";
        if(name == "Alice"){
            if(n%3==1) cout << "Bob\n";
            else cout << "Alice\n";
        }else{
            if(n%3==0) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }
}