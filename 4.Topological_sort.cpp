#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
template<typename T>
class graph{
    map<T,list<T>>l;
    public:
        void addedge(T x,T y){
        l[x].push_back(y);
    }
    
        //using bfs
        void topological_sort(){
            //indegree
            map<T,int>indegree;
            //make indegree of all nodes zero
            for(auto v:l){
                indegree[v.first]=0;
            }
            
            //update indegree by traversing edges 
            for(auto p:l){
                T x=p.first;
                for(auto y:p.second){
                    indegree[y]++;
                }
            }
            
            //bfs
            queue<T>q;
            //step 1. find nodes with 0 indegree
            for(auto v:l){
                if(indegree[v.first]==0)
                    q.push(v.first);
            }
            
            //start removing elements from the queue
            while(!q.empty()){
                T node =q.front();
                cout<<node<<" ";
                q.pop();
                
                //iterate over nbrs of that node and reduce their indegree
                for(auto nbr:l[node]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0)
                        q.push(nbr);
                }
            }
        }
  
  
        //using dfs
        void dfs_helper(T src,map<T,bool>&visited,list<T>&ordering){
            visited[src]=true;
            //go to nbr of that node that is not visited
            for(auto nbr:l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited,ordering);
                }
            }
            ordering.push_front(src);
            return ;
        }
        
        bool dfs(){
            map<T,bool>visited;
            list<T>ordering;
            //mark all nodes as not visited in the begining
            for(auto p:l){
                T node =p.first;
                visited[node]=false;
            }
            //call the helper function for all component 
            for(auto p: l){
                T  node =p.first;
                if(!visited[node])
                    dfs_helper(node,visited,ordering);
            }
    
            //print topological sorted list
            for(auto x:ordering){
                cout<<x<<" ";
            }
            cout<<endl;
        }
};
int main(){
    graph<string>g;
    g.addedge("python","DataPreprocessing");
    g.addedge("python","pytourch");
    g.addedge("python","ML");
    g.addedge("DataPreprocessing","ML");
    g.addedge("pytourch","DL");
    g.addedge("ML","DL");
    g.addedge("DL","FaceRecogn");
    g.addedge("DataSet","FaceRecogn");
    g.dfs();
    g.topological_sort();
    return 0;
}
