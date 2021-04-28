

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
   map<T,list<pair<T,int>>>m;
   
   public:
   
        void addEdge(T u,T v,int dist,bool bidir=true){
            m[u].push_back(make_pair(v,dist));
            if(bidir){
                m[v].push_back(make_pair(u,dist));
            }
        }
        
        /**********printing adjacency list 
         
        void printadjlist(){
            for(auto j:m){
                cout<<j.first<<"->";
                for(auto l:j.second){
                    cout<<"("<<l.first<<","<<l.second<<")";
                }
                cout<<endl;
            }
        }            ***********/
        
        
        
        /*************printing shortest path
         
        void printUtil(T dest,map<T,T>parent){
            if(parent[dest]==-1)
            {
                cout<<dest<<" ";
                return ;
            }
                
            printUtil(parent[dest],parent);
            cout<<dest<<" ";
        }
        
        void printshortestpath(T src,map<T,int>dist,map<T,T>parent){
            for(auto x:m){
                T node =x.first;
                printUtil(node,parent);
                cout<<endl;
            }
        }
        *******************/


        //main part of implementation;
        void dijsktaSSSP(T src){
            map<T,int>dist;
            //using parent map to get shortest path;
            map<T,T>parent;
            //set all distance to infinity
            for(auto j:m){
                parent[j.first]=-1;
                dist[j.first]=INT_MAX;
            }
            
            //make a set to find out node with the minimum distance
            //first element of set will be smallest always;
            set<pair<int,T>>s;    //{distance,node}
            dist[src]=0;
            s.insert(make_pair(0,src));
            
            while(!s.empty()){
                //find the pair at the front of set;
                auto p=*(s.begin());
                T node=p.second;
                int nodedist=p.first;
                s.erase(s.begin());
                
                //iterate over neighbours/children of the current node
                for(auto childpair:m[node]){
                    if(nodedist+childpair.second<dist[childpair.first]){
                        //we have to remove the old pair and insert the new pair to simulation updation
                        T destination=childpair.first;
                        auto f=s.find(make_pair(dist[destination],destination));
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        //insert the new pair
                        dist[destination]=nodedist+childpair.second;
                        s.insert(make_pair(dist[destination],destination));
                        
                        parent[destination]=node;
                        
                    }
                }
            }
            
            //lets print distance to all other node from src
            for(auto d:dist){
                cout<<d.first<<" is located at distance of "<<d.second<<endl;
            }
            
            //print shortest path
            
            //printshortestpath(src,dist,parent);
            
        }
};
int main(){
    Graph<int>g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    
    g.dijsktaSSSP(1);
    return 0;
}
