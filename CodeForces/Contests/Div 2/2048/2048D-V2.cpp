#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(m); // collected ratings and problems
        for(int i=0; i<n; i++){ // collected ratings
            cin>>a[i];
        }
        for(int i=0; i<m; i++){ // collected problems
            cin>>b[i];
        }
        int kev_rating = a[0]; // this is Kevin's rating
        sort(a.begin(),a.end()); // sort it!
        int low = kev_rating; // low > Kevin's rating
        int high = a.back(); // so this is the rating of the higested rated person.
        vector<int> problematic; // So any problem that lies between  low and high is a problem some one can solve but Kevin cannot
        for(int i=0; i<m; i++){
            if(low< b[i] && b[i]<= high){
                problematic.push_back(b[i]);
            }
        }
        sort(problematic.begin(),problematic.end());
        int p = problematic.size();
        vector<int> nums(p); // this will push us to our glorious ans. It is the number of people that can solve problematic[i]
        vector<int>::iterator it;
        for(int i=0; i<p; i++){
            it = lower_bound(a.begin(),a.end(),problematic[i]);
            nums[i] = a.end() - it; // number of people who can solve problematic[i]
        }
        for(int k=1; k<=m; k++){
            long long ans = (m-p)/k;
            for(int j = p +((m-p)%k) -k; j>=0; j-=k){
                // cout<<"e ";
                ans=ans+(long long)(1+nums[j]);
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}