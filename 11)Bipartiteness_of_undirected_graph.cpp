#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define U unsigned int
#define pb push_back
using namespace std;
map<int,list<int>>G;
//function to add Edge
void addEdge(int x,int y){
	G[x].pb(y);
	G[y].pb(x);
}
//bfs function to check whether a graph is bipartite or not
bool isBipartite(){
	//vector to store color of vertex 
	//first assign all to -1
	int V=G.size();
	vector<int>colorarr(V,-1);
	
	//make a queue and implement using bfs
	//queue for BFS storing {vertex,color}
	queue<pair<int,int>>q;
	
	// loop incase graph is not connected
	//because in case of not connected we will check bipartiteness of all component
	for(auto i:G){
	    int node=i.first;
	    //if not coloured
	    if(colorarr[node]==-1){
	        //colouring with 0 i.e. red
            q.push({ node, 0 });
            colorarr[node] = 0;
	    }
	    
	    while(!q.empty()){
	        pair<int, int> p = q.front();
                q.pop();
               
                  //current vertex
                int v = p.first;
                  //colour of current vertex
                int c = p.second;
                
                //traversing vertexes connected to current vertex
                for(auto j:G[v]){
                    //if already coloured with parent vertex color
                    //then bipartite graph is not possible
                    if (colorarr[j] == c)
                        return false;
                        
                    //if uncoloured
                    if (colorarr[j] == -1) {
                      //colouring with opposite color to that of parent
                        colorarr[j] = 1-c;
                        q.push({ j, colorarr[j] });
                    }
                }
	    }
	    
	}
	
	return true;
}
int main(){

 	  addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(6, 1);
 	//we are using bfs here
    isBipartite() ? cout << "Yes" : cout << "No";


	return 0;
}
