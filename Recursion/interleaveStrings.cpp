#include<bits/stdc++.h>
using namespace std;

void helper(string& a, string& b, int i, int j, string op){
    
    if( i == a.size() && j == b.size()){
        cout << op << endl;
        return;
    }
    if( i == a.size()){
        op += b.substr(j);
        cout << op << endl;
        return;
    }
    if( j == b.size()){
        op += a.substr(i);
        cout << op << endl;
        return;
    }

    helper(a,b,i+1,j,op+a[i]);
    helper(a,b,i,j+1,op+b[j]);
}

int main(){
    string a,b;
    cin >> a >> b;
    helper(a,b,0,0,"");
    return 0;
}
