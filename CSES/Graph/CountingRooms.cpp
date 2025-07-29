#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    string in;
    cin>>n>>m;
    vector<vector<bool>> grid(n+1,vector<bool>(m+1,false));
    for(int i=0; i<n; i++){
        cin>>in;
        for(int j=0; j<m; j++){
            if(in[j] == '.' ) grid[i][j] = true; 
        }
    } // sucessfully converted the grid into a boolean format
    // note that grid[i][m] and grid[n][j] are always false and intended to be so.
    vector<bool> visited(n*m, false); // n*m vertices
    vector<vector<int>> edges(n*m);// edges[i] contains the edges of vertex i, n*m>i>=0
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!grid[i][j]) visited[m*i + j] = true;
            else{
                if(grid[i+1][j]){
                    edges[m*i+j].push_back(m*(i+1)+j);
                    edges[m*(i+1)+j].push_back(m*i+j);
                }
                if(grid[i][j+1]){
                    edges[m*i+j].push_back(m*(i)+j+1);
                    edges[m*(i)+j+1].push_back(m*i+j);
                }
            }
        }
    }
    queue<int> q;
    int temp;
    int components = 0;
    for(int i = 0; i<n*m; i++){
        if(!visited[i]){
            components ++;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                temp = q.front();
                visited[temp] = true;
                q.pop();
                for(auto j : edges[temp]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    cout<<components;
}