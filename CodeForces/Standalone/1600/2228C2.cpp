#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll pwr(ll a, int n);
vector<int> make_digits(ll a);
ll spl_num(int digit, int len);
ll glb(vector<int> &a, vector<int> &dgts, int head);
ll lub(vector<int> &a, vector<int> &dgts, int head);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        ll a;
        int n;
        cin>>a>>n;
        vector<int> digits(n);
        for(auto &x : digits) cin>>x;
        vector<int> A = make_digits(a);
        ll ans = a;
        ll l = lub(A,digits,0);
        ll g = glb(A,digits,0);
        if(l != -1) ans = l - a;
        if(g != -1) ans = min(ans,a - g);
        cout<<ans<<"\n";
    }
}

ll pwr(ll a, int n){
    ll ans = 1LL;
    ll mul = a;
    while(n>0){
        if(n&1) ans*=mul;
        mul*=mul;
        n>>=1;
    }
    return ans;
}

vector<int> make_digits(ll a){
    if(a == 0) return {0}; 
    vector<int> ans;
    while(a>0){
        ans.push_back((int)(a%10LL));
        a/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

ll spl_num(int digit, int len){
    if(len <= 0) return 0;
    ll ans = 0LL;
    ll mul = 1LL;
    while(len--){
        ans+=(digit*mul);
        mul*=10LL;
    }
    return ans;
}// spl_num(7,3) should return 777

ll lub(vector<int> &a, vector<int> &dgts, int head){

    int size = a.size();
    if(head >= size) return 0;
    
    vector<int>::iterator it = upper_bound(dgts.begin(), dgts.end(), a[head]);

    if(it == dgts.begin()){
        return(spl_num(dgts[0], size - head)); // fine
    } // now we are allowed to do --it

    if(it == dgts.end() && dgts.back() != a[head]){ // this means all the allowed digits are less the a[head] so we can't form a number that has same digits from head to tail that's greater
        if(head == 0){
            if(dgts[0] !=0 ) return spl_num(dgts[0],size + 1);
            if( dgts.size() > 1) return (ll) dgts[1] * pwr(10LL, size);
            return -1;
        }
        return -1;
    }

    if(it == dgts.end()){ //in this case we know dgts.back() == a[head]
        ll b = lub(a,dgts,head+1);
        if(b != -1) return ((ll) a[head]*pwr(10LL,size - head - 1) + b);
        if(head == 0){
            if(dgts[0] !=0 ) return spl_num(dgts[0],size + 1);
            if( dgts.size() > 1) return (ll) dgts[1] * pwr(10LL, size);
            return -1;
        }
        return -1;
    } //after this we can do *it

    int b = *it;
    ll ans = (ll) b*pwr(10LL, size -head -1) + spl_num(dgts[0], size - head - 1);
    --it;
    int c =*it;
    if(c == a[head]){
        ll d = lub(a,dgts,head+1);
        if(d!=-1) ans = (ll) a[head]*pwr(10LL,size - head - 1) + d;
    }
    return ans;
}

ll glb(vector<int> &a, vector<int> &dgts, int head){
    int size = a.size();
    if(head >= size) return 0;
    vector<int>::iterator it = upper_bound(dgts.begin(), dgts.end(), a[head]);
    if(it == dgts.begin()){
        if(head == 0 && size !=1 ) return spl_num(dgts.back(), size - 1);
        return -1;
    }
    --it;
    int b = *it;
    if( b != a[head] ) return b*pwr(10LL, size - head - 1) + spl_num(dgts.back(), size - head - 1);
    if( b == a[head] ){
        ll c = glb(a, dgts, head + 1);
        if( c != -1) return (ll) a[head] * pwr(10LL , size - head - 1) + c;
        if(it != dgts.begin()){
            --it;
            b = *it;
            return b*pwr(10LL, size - head - 1) + spl_num(dgts.back(), size - head - 1);
        }
        if(head==0 && size != 1) return spl_num(dgts.back(), size - 1);
        return -1;
    }
    return -1;
}