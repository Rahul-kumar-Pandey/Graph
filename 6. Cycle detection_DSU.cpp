/******* Graph has cycle or not using Disjoint set union ********/

#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    //making edge list here for better convention;
    list<pair<int,int> >l;
    
    public:
        Graph(int V){
            this->V=V;
        }
        int addEdge(int u ,int v){
            l.push_back(make_pair(u,v));
        }
        
        //unoptimized find() function 
        int findset(int i,int parent[]){
            if(parent[i]==-1){
                return i;
            }
            return findset(parent[i],parent);
        }
        //union function
        void union_set(int x,int y,int parent[]){
            int s1=findset(x,parent);
            int s2=findset(y,parent);
            if(s1!=s2){
                parent[s1]=s2;
            }
        }
        
        bool contains_cycle(){
            //DSU logic to check if graph contains cycle or not
            int *parent =new int[V];
            for(int i=0;i<V;i++){
                parent[i]=-1;
            }
            
            //iterate over the edge list
            for(auto edge :l){
                int i=edge.first;
                int j=edge.second;
                int s1=findset(i,parent);
                int s2=findset(j,parent);
                
                if(s1!=s2)
                    union_set(s1,s2,parent);
                else
                    return true;
            }
            delete [] parent;
            return false;
        }
};
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<g.contains_cycle()<<endl;

    return 0;
}
