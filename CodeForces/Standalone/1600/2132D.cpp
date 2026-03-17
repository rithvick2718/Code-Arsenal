#include<bits/stdc++.h>
#define ll long long
using namespace std;
int D = 17;
vector<ll> vals_k(D,0);
ll pwr(ll a, ll n){
    ll ans = 1LL;
    while(n>0LL){
        if(n&1LL) ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}
ll num_construct(const vector<int> &digits, int start){
    ll ans = digits[start];
    int d = digits.size();
    for(int i = start+1; i<d; i++){
        ans*=10;
        ans+=digits[i];
    }
    return ans;
}
ll sum(const vector<int> &digits, int start){
    int d = digits.size() - start;
    if(d <= 0) return 0LL;
    if (d == 1){
        return (ll) ( ( (digits[start] + 1) * (digits[start]) )>>1 );
    } // from here on d>=2
    if(digits[start] == 0) return sum(digits,start + 1);
    // now digits[start] is atleast 1.
    // so we must add all the numbers with digits less than or equal to d-1 i.e. 45LL*(d-1)*pwr(10LL,d-2)
    // and fixing the first digit we must add the above ( 0,1,2, digit[start] - 1) -> digit[start] times
    // so we covered inner part
    // and now each of the fixed digits appear pwr(10,d-1) times
    // so add ( ( digit[start] * (digit[start] - 1) )>>1 )*pwr(10,d-1)
    // and now digits[start] appears 1 + num_construct(digits, start+1) times.
    ll ans = ((ll) digits[start]) * (45LL) * (d-1) * pwr(10LL,d-2)
            + ( ( digits[start] * (digits[start] - 1) )>>1 )*pwr(10,d-1)
            + digits[start]*( num_construct(digits,start+1) + 1);
    return (ans + sum(digits, start+1));
}
vector<int> make_digit_vector(ll k){
    vector<int> ans;
    stack<int> s;
    while(k>0){
        s.push(k%10);
        k/=10;
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
void initialize_vectors(){
    for(int i=1; i<D; i++){
        vals_k[i] += vals_k[i-1] + i*9LL*pwr(10LL,i-1);
    }
}
ll cal(ll k){
    int d = lower_bound(vals_k.begin(), vals_k.end(), k) - vals_k.begin(); // now I know the no. of digits of last num.
    ll r = ( k - vals_k[d-1] )%d;
    ll m = (k-r-vals_k[d-1])/d + pwr(10,d-1) - 1;
    vector<int> v = make_digit_vector(m);
    ll ans = sum(v,0);
    m++;
    v = make_digit_vector(m);
    for(int i=0; i<r; i++){
        ans+=v[i];
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    initialize_vectors();
    while(tt--){
        ll k;
        cin>>k;
        cout<<cal(k)<<"\n";
    }
}