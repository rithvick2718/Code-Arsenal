#include<bits/stdc++.h>
using namespace std;
char direction(int u, int v, int m){
    int i = u/m - v/m;
    int j = u%m - v%m;
    if( i == 0 && j == 1) return 'R';
    if( i == 0 && j == -1) return 'L';
    if( i == 1 && j == 0) return 'D';
    if( i == -1 && j == 0) return 'U';
    return 'E';
}
int INF = INT_MAX;
int main(){
    int n,m;
    cin>>n>>m;
    int start;
    int u;
    string s;
    vector<vector<bool>> grid(n+1,vector<bool>(m+1,false));
    vector<int> M_D(n*m, INF);
    vector<int> S_D(n*m, INF);
    vector<int> parent(n*m,-1);
    queue<int> M; // all the monsters here, used for multi-source BFS
    queue<int> S; // I use this to apply BFS
    for(int i = 0; i < n; i++){ // getting grid, monsters and start
        cin>>s;
        for(int j = 0; j < m; j++){
            if(s[j] != '#'){
                grid[i][j] = true;
                if(s[j] == 'A'){
                    start = m*i+j;
                    S.push(start);
                    S_D[start] = 0;
                }
                else if(s[j] == 'M'){
                    M.push(m*i+j);
                    M_D[m*i+j] = 0;
                }
            }
        }
    }
    vector<int> edges[n*m];
    for(int i = 0; i < n; i++){  // constructing edges i.e. adjacnency list
        for(int j = 0; j < m; j++){
            if(grid[i][j] && grid[i+1][j]){
                edges[m*i+j].push_back(m*(i+1)+j);
                edges[m*(i+1)+j].push_back(m*i+j);
            }
            if(grid[i][j] && grid[i][j+1]){
                edges[m*i+j].push_back(m*i+j+1);
                edges[m*i+j+1].push_back(m*i+j);
            }
        }
    }
    while(!M.empty()){
        u = M.front();
        M.pop();
        for(auto v : edges[u]){
            if(M_D[v] == INF){
                M_D[v] = 1 + M_D[u];
                M.push(v);
            }
        }
    }
    while(!S.empty()){
        u = S.front();
        S.pop();
        for(auto v : edges[u]){
            if(S_D[v] == INF){
                S_D[v] = 1 + S_D[u];
                parent[v] = u;
                S.push(v);
            }
        }
    }
    bool found = false;
    int Border = -1;
    for(int i = 0; i<m && !found; i++){
        if(S_D[i] < M_D[i]){
            found = true;
            Border = i;
        }
        if(S_D[m*(n-1) + i] < M_D[m*(n-1) + i]){
            found = true;
            Border = m*(n-1) + i; 
        }
    }
    for(int i = 0; i<n && !found; i++){
        if(S_D[m*i] < M_D[m*i]){
            found = true;
            Border = m*i;
        }
        if(S_D[m*i + m-1] < M_D[m*i + m-1]){
            found = true;
            Border = m*i + m-1;
        }
    }
    if(found){
        cout<<"YES\n";
        string t;
        while(Border != start){
            t+=direction(Border,parent[Border],m);
            Border = parent[Border];
        }
        cout<<t.length()<<"\n";
        reverse(t.begin(),t.end());
        cout<<t;
    }
    else{
        cout<<"NO";
    }
}