#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
template<typename T>
class graph{
    map<T,list<T>>l;
    map<T,list<T>>rl;
    public:
        void addedge(T x,T y){
            l[x].push_back(y);
        }
        
        
        //step1. make dfs call and add elements in stack according to topological sort.
        void dfs_helper(T node,map<T,bool>&visited,stack<T>&st){
            visited[node]=true;
            //go to nbr of that node that is not visited
            for(auto nbr:l[node]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited,st);
                }
            }
            st.push(node);
        }
        //step2. reverse graph;
        void reverse_graph(){
            for(auto x:l){
                for(auto a:l[x.first]){
                    rl[a].push_back(x.first);
                }
            }
            
            //printing reversed graph
            
            // for(auto x:rl){
            //     cout<<x.first<<"->";
            //     for(auto a:rl[x.first]){
            //         cout<<a<<" ";
            //     }
            //     cout<<endl;
            // }
        }
        
        //step3. finally get connected component
        void dfs_reversed(T node,map<T,bool>&visited){
            // Mark the current node as visited and print it
            visited[node]=true;
            cout<<node<<" ";
            // Recur for all the vertices adjacent to this vertex
            for(auto a:rl[node]){
                if(!visited[a]){
                    dfs_reversed(a,visited);
                }
            }
        }
        void dfs_utility(){
            map<T,bool>visited;
            stack<T>st;
            //mark all nodes as not visited in the begining
            for(auto p:l){
                T node =p.first;
                visited[node]=false;
            }
            //call the helper function for all component 
            for(auto p: l){
                T  node =p.first;
                if(!visited[node])
                    dfs_helper(node,visited,st);
            }
            
            //after step 1. reverse graph;
            reverse_graph();
            
            //after making reverse graph 
            //traverse reversed graph and make visited false for all nodes
            for(auto p:rl){
                T node =p.first;
                visited[node]=false;
            }
            //call helper for reversed graph
             while(!st.empty()){
                 T node=st.top();
                 st.pop();
                 if(!visited[node]){
                     dfs_reversed(node,visited);
                     cout<<endl;
                 }
             }
        }
        
};
int main(){
    graph<int>g;
    g.addedge(1, 0);
    g.addedge(0, 2);
    g.addedge(2, 1);
    g.addedge(0, 3);
    g.addedge(3, 4);
    g.dfs_utility();
    return 0;
}
