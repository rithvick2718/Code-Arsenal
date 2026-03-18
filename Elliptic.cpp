#include<bits/stdc++.h>
using namespace std;
int inv( int x, int p){
    long long ans = 1;
    long long a = x%p;
    long long n = p-2;
    while(n>0){
        if(n&1) ans=(ans*a)%p;
        a=(a*a)%p;
        n>>=1;
    }
    return (int) ans;
}
pair<int,int> add(const pair<int,int> &p1, const pair<int,int> &p2, const int &p, const int &a){
    pair<int,int> inf = {-1,-1};
    if(p1 == inf) return p2;
    if(p2 == inf) return p1;
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    int x3,y3;
    int l;
    if(p1 == p2){
        if(y1 == 0) return inf; // -1,-1 is treated as inf.
        l = ( (3*x1*x1 + a) * inv(2*y1,p) )%p;
        l = (l+p)%p;
    }
    else if(x1 == x2 ) return inf; // the code will treat -1,-1 as inf.
    else if(x1 != x2){ // covers horizontal line too.
        l =( (y1-y2)*inv(x1-x2,p) )%p;
        l = (l+p)%p;
    }
    x3 = (l*l - x1 -x2)%p;
    y3 = (l*(x1 -x3)-y1)%p;
    x3 = (x3+p)%p;
    y3 =(y3+p)%p;
    return {x3,y3};
}
bool is_primitive(pair<int,int> xy, const int &a, const int &p,int grp_size){
    auto [x,y] = xy;
    pair<int,int> id = {-1,-1};
    auto val = xy;
    for(int i=2; i<grp_size; i++){
        val = add(val,xy,p,a); // after this val = i(xy) -> xy added i times.
        if(val == id) return false;
    }
    return true;
}
pair<int,int> find_primitive_element(const vector<pair<int,int>> &group_elements,const int &a, const int &p){
    int grp_size = group_elements.size() + 1;
    for(auto p1 : group_elements){
        if(is_primitive(p1,a,p,grp_size)) return p1;
    }
    return {-1,-1};
}
int main(){
    int p,a,b; // x^3 + a*x + b is our elliptic curve
    cin>>p>>a>>b;
    vector<vector<int>> possible_y(p);
    vector<pair<int,int>> group_elements;
    for(int y=0; y<p; y++){
        possible_y[((y*y)%p)].push_back(y);
    }
    for(int x=0; x<p; x++){
        int val = (x*x*x + a*x + b)%p;
        val = (val+p)%p;
        for(auto y : possible_y[val]){
            group_elements.push_back({x,y});
        }
    }
    cout<<"Group size is "<<group_elements.size() + 1<<"\n";
    cout<<"The group elements are ";
    for(auto [x,y] : group_elements){
        cout<<"("<<x<<","<<y<<"),";
    }
    cout<<"point of infinty\n";
    auto [x,y] = find_primitive_element(group_elements,a,p);
    cout<<"Primitive element is : ("<<x<<","<<y<<")";
}