#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    string in;
    int start=0;
    int end=0;
    vector<vector<bool>> grid(n+1, vector<bool>(m+1, false));
    for(int i = 0; i < n; i++){
        cin>>in;
        for(int j = 0; j < m; j++){
            if(in[j] != '#'){
                grid[i][j] = true;
                if(in[j] == 'A'){
                    start = m*i+j;
                }
                else if(in[j] == 'B'){
                    end = m*i+j;
                }
            }
        } //getting the grid
    }
    vector<int> vrtx(n*m,-1);
    vector<int> edges[n*m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]){
                if(grid[i+1][j]){
                    edges[m*i+j].push_back(m*(i+1)+j);
                    edges[m*(i+1)+j].push_back(m*i+j);
                }
                if(grid[i][j+1]){
                    edges[m*i+j].push_back(m*i+j+1);
                    edges[m*i+j+1].push_back(m*i+j);
                }
            }
        }
    }
    vrtx[start] = 0;
    queue<int> q;
    q.push(start);
    int temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(auto v : edges[temp]){
            if(vrtx[v] == -1){
                vrtx[v] = vrtx[temp] + 1;
                q.push(v);
            }
        }
    }
    if(vrtx[end] != -1){
        cout<<"YES\n"<<vrtx[end]<<"\n";
        string ans;
        temp = end;
        int i,j;
        while(vrtx[temp]>0){
            for(auto x : edges[temp]){
                if(vrtx[x] == vrtx[temp] - 1){
                    i = temp/m - x/m;
                    j = temp%m - x%m;
                    if((i == 0) && (j == 1)){
                        ans += 'R';
                    }
                    if((i == 0) && (j == -1)){
                        ans += 'L';
                    }
                    if((i == 1) && (j == 0)){
                        ans += 'D';
                    }
                    if((i == -1) && (j == 0)){
                        ans += 'U';
                    }
                    temp = x;
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
    else cout<<"NO\n";
}