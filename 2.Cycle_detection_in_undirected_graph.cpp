#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
map<int,list<int>>g;
void addedge(int x,int y){
    g[x].push_back(y);
    g[y].push_back(x);
}
//using bfs
bool bfs(int u)
	{
	    map< int, bool> visited;
	    //make a pair of queue where the first element is node and second is its parent
		queue<pair<int,int>> q;
		q.push(make_pair(u,-1));
		visited[u]=true;
		while (!q.empty())
		{
			pair<int,int> front_element = q.front();
			q.pop();
	
			for (auto nbr : (g[front_element.first]))
			{
				if(!visited[nbr])
				{
				    visited[nbr]=true;
				    q.push(make_pair(nbr,front_element.first));
				}
				//else when nbr is visited and it is not equal to front_element.second(which is parent)
				//in other words we found a cross edge
				else if(visited[nbr]==true && nbr!=front_element.second)
				    return true;
			}
		}
		return false;
}

//using dfs
bool cycle_helper(int node,map<int,bool>&visited,int parent){
    visited[node]=true;
    for(auto nbr:g[node]){
        // when this node 'nbr' is not visited then call function recursively for dfs
        if(!visited[nbr]){
            if(cycle_helper(nbr,visited,node))
                return true;
        }
        
        //when 'nbr' is visited but is not equal to 'parent'
        //that means we found cycle so return true;
        else if(nbr!=parent)
            return true;
    }
    //when everynode visited but we could not get any cycle return false;
    return false;
}
bool dfs(){
    map<int,bool>visited;
    for(auto v:g){
        int node=v.first;
        visited[node]=false;
    }
   return cycle_helper(0,visited,-1);
}
int main(){
    //make some edges for graph
    addedge(0,1);
    addedge(1,2);
    addedge(2,3);
    addedge(3,4);
    addedge(4,0);
    addedge(4,6);
    
    if(dfs()) cout<<"cycle exists in the graph\n";
    else    cout<<"NO cycle in this graph\n";
    
    if(bfs(0)) cout<<"YES\n";
    else    cout<<"No\n";
	return 0;
}
