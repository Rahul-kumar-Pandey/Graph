//understanding
/* 1. spanning tree connects all vertices of the graph 
   2. no cycle present
   3. single connected component
   4. it's a subset of edges
*/


#include<stdc++.h>
using namespace std;
//DSU data structure (for helping owr implementation)
//path compression + union by rank
class DSU{
    int *parent,*rank;
    public:
        DSU(int n){
            parent=new int[n];
            rank=new int[n];
            
            //initially make parent -1 and rank 1 
            for(int i=0;i<n;i++){
                parent[i]=-1;
                rank[i]=1;
            }
        }
        //find function
        int find(int i){
            if(parent[i]==-1){
                return i;
            }
            parent[i]=find(parent[i]);
            return parent[i];
        }
        
        //union function
        void make_union(int x,int y){
            int s1=find(x);
            int s2=find(y);
            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]==s2;
                    rank[s2]+=rank[s1];
                }  
                else{
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};

//main part of implementation
class Graph{
  vector<vector<int>> edgelist;
  int V;
  public:
    Graph(int V){
        this->V=V;
    }
    void addEdge(int x,int y,int w){
        edgelist.push_back({w,x,y});
    }
    
    int kruskal_mst(){
        //1.sort all edges based upon weight
        sort(edgelist.begin(),edgelist.end());
        //init a DSU
        DSU s(V);
        int ans=0;
        for(auto edge:edgelist){
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            
            //2.take that edge in mst if it doesnot form a cycle
            if(s.find(x)!=s.find(y)){
                s.make_union(x,y);
                ans+=w;
            }
        }
        return ans;
    }
};
int main(){
    Graph g(4);
    //g.addEdge(vertex1,vertex2,weight);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    
    cout<<g.kruskal_mst()<<endl;
    return 0;
}
