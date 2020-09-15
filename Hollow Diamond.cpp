#include <bits/stdc++.h>
using namespace std;

string rep(char s,int k){
  string _;
  for(int i=0;i<k;i++) _+=s;
  return _;
}

int main() {
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cout<<rep('*',n-i)+rep(' ',1+2*i)+rep('*',n-i)<<endl;
  }
  for(int i=n-1;i>=0;i--){
    cout<<rep('*',n-i)+rep(' ',1+2*i)+rep('*',n-i)<<endl;
  }
}
