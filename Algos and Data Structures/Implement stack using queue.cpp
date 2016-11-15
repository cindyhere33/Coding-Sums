#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#define N 100001
using namespace std;
 
 
/*
s = root node
g[x] = all the nodes connected to x
vis[x] = true is node x has already been visited, else vis[x]=false
*/
void bfs(int s, vector<int> g[], bool vis[]){
	vector<int> q;
    q.push_back(s);
    while(q.size()>0){
        int x=*q.begin();
        if(vis[x]){
            q.erase(q.begin());
            continue;
        }
        printf("%d ", x);
        vis[x]=true;
        q.erase(q.begin());
        for(vector<int>::iterator it2 = g[x].begin(); it2!=g[x].end(); ++it2){
            q.push_back(*it2);
        }
    }
}

int main(){
	bool vis[N];
	vector<int> g[N];
	memset(g,0,sizeof g);
    memset(vis,false,sizeof vis);
	int noNodes = 6;
	g[0].push_back(1), g[0].push_back(3), g[0].push_back(5);
	g[1].push_back(5),g[1].push_back(6),g[1].push_back(2);
	g[2].push_back(3),g[2].push_back(5);
	g[3].push_back(4);
	g[4].push_back(2), g[4].push_back(3);
	g[5].push_back(4);
	bfs(0, g, vis);
	return 0;
}
