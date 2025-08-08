#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int numCourses,numDependency; // number of courses, number of Dependencies
    cin>>numCourses>>numDependency;
    vector<int> dependencies[numCourses]; // dependencies
    vector<int> inDegree(numCourses,0);
    vector<int> afterBFS(numCourses,0);
    int u,v;
    queue<int> q;
    for(int i=0; i<numDependency; i++){ // getting dependencies
        cin>>u>>v;
        dependencies[u].push_back(v);
        inDegree[v]++;
    }
    for(int i=0; i<numCourses; i++){ // collecting free Courses
        if(inDegree[i] == 0) q.push(i);
    }
    while(!q.empty()){ // multi-source BFS on directed graph
        v = q.front();
        q.pop();
        for(auto t : dependencies[v]){
            afterBFS[t]++;
            if(afterBFS[t] == inDegree[t]) q.push(t); // now this course can be taken
        }
    }
    bool yes = true;
    for(int i=0; i<numCourses; i++){ // checking if all courses can be taken
        if(inDegree[i] != afterBFS[i]){
            yes = false;
            break;
        }
    }
    if(yes) cout<<"YES\n";
    else cout<<"NO\n";
}
/*
The Problem Statement :
    A student can take a course if and only if they have taken all the prerequisites of the course.
    If a course has no prerequisite then the student can take the course.
    You will be given a dependency list in the form prerequisite , course.
    Your task is to figure out if a student can take all courses or not.
Input :
    The first line contains 2 integers number of courses and number of dependencies say n,m respectively
    Next m lines contains prerequisite course , course as integers.
    0 - based indexing is used
Output : "YES" or "NO"
*/