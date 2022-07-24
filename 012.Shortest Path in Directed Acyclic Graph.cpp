/*For a general weighted graph, we can calculate single source shortest distances in O(VE) time using Bellman–Ford Algorithm.
For a graph with no negative weights, we can do better and calculate single source shortest distances in O(E + VLogV) time using Dijkstra’s algorithm. 
Can we do even better for Directed Acyclic Graph (DAG)? 
We can calculate single source shortest distances in O(V+E) time for DAGs. The idea is to use Topological Sorting.*/
  
void findTopoSort(int src,int vis[],vector<pair<int,int>>adj[],stack<int>&st){
  vis[src]=1;
  for(auto nbr:adj[src]){
    if(!vis[nbr.first]){
      findTopoSort(nbr.first,vis,adj,st);
    }
  }
  
  st.push(src);
}
void shortestpath(int src,int N,vector<pair<int,int>>adj[]){
  
  //find topological sorting and store in st
  int vis[N]={0};
  stack<int>st;
  for(int i=0;i<N;i++){
    if(!vis[i]) findTopoSort(i,vis,adj,st);
  }
  
  //distance of all nodes is INF in starting 
  int dist[N];
  for(int i=0;i<N;i++){
    dis[i]=INT_MAX;
  }
  //distance of src is 0
  dist[src]=0;
  
  //go through topological sort and find distance
  while(!st.empty()){
   int u=st.top();
    st.pop();
    
    if(dist[u]!=INT_MAX){
      for(auto nbr:adj[u]){
        int v=nbr.first;
        if(dist[v]>dist[u]+nbr.second){
          dist[v]=dist[u]+nbr.second;
        }
      }
    }
  }
  
  //print distance for every node stored in dist[N]
}

int main(){
  shortestPath(0,N,adj);
  return 0;
}
