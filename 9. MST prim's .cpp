//understanding
/* 1. spanning tree connects all vertices of the graph 
   2. no cycle present
   3. single connected component
   4. it's a subset of edges
*/


#include<bits/stdc++.h>
using namespace std;
class Graph{
    //adjacency list
    //v->[{node1,weight1},{node2,weight2}]
    vector<pair<int,int>>*l;
    int V;
    
    public:
        Graph(int n){
            V=n;
            l=new vector<pair<int,int>>[n];
        }
        void addEdge(int x,int y,int w){
            l[x].push_back({y,w});
            l[y].push_back({x,w});
        }
        
        //most important function
        int prim_mst(){
            //init min heap
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
            //visited array that denotes whether a node has been included in MST or not
            bool *visited=new bool[V]{0};
            int ans=0;
            
            //let's begin
            Q.push({0,0}); // weight,node
            
            while(!Q.empty()){
                //pick out the edge with min weight
                auto best=Q.top();
                Q.pop();
                int to=best.second;
                int weight=best.first;
                
                if(visited[to]){
                    //discard the edge ,and continue
                    continue;
                }
                
                //otherwise take the current edge
                ans+=weight;
                visited[to]=1;
                
                //add the new edges in the queue 
                for(auto x:l[to]){
                    if(visited[x.first]==0){
                        Q.push({x.second,x.first});
                    }
                }
            }
            return ans;
        }
};
int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.prim_mst()<<endl;
    return 0;
}
