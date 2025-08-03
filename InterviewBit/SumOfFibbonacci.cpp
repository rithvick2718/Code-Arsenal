#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int Solutionfibsum(int A) {
    vector<ll> fib = {1LL,2LL};
    ll  a = 1LL;
    ll b = 2LL;
    while( a + b <= 1'000'000'000LL){
        fib.push_back(a+b);
        a = b;
        b = fib.back();
    }
    vector<ll>::iterator it;
    int c = 0;
    while(A>0){
        it = upper_bound(fib.begin(),fib.end(),A);
        --it;
        c+=A/(*it);
        A=A%(*it);
    }
    return c;
}
int main(){
    cout<<Solutionfibsum(804289383);
}