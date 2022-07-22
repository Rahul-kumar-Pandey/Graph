#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
  public:
    
    //l[source]->[{destination,weight},{},{}];
    map<T,list<pair<T,int>>>l;
    
    //make graph
    void addEdge(T src ,T dest ,int dist,bool isbidir){
        l[src].push_back(make_pair(dest,dist));
        if(isbidir)
            l[dest].push_back(make_pair(src,dist));
    }
    //printAdjacencyList
    void printAdjacencyList(){
        for(auto x:l){
            cout<<x.first<<" : ";
            for(auto y:x.second){
                cout<<"{ "<<y.first<<" , "<<y.second<<" }";
            }
            cout<<endl;
        }
    }
    
    //bfs traversal in graph
    void bfs(T src){
        map<T,bool>visited;
        queue<T>q;
        q.push(src);
	visited[src]=true;
        while(!q.empty()){
            T node =q.front();
            q.pop();
	    cout<<node<<" ";
            
            for(auto x:l[node]){
                if(!visited[x]){
                    q.push(x);
		    visited[x]=true;
                }
            }
        }
        
    }
    
    //find single source sortest path for unweighted graph
    // distance calculation by level order traversal(bfs) is minimum in case of unweighted graph
    void bfs_sssp(T src){
        map<T,int>distance;
	//THIS INDICATES NODES NOT VISITED 
        for(auto a:l){
            distance[a.first]=INT_MAX;
        }
        distance[src]=0;
        queue<T>q;
        q.push(src);
        while(!q.empty()){
            T node =q.front();
            q.pop();
            for(auto nbr:l[node]){
		T dest=nbr.first;   
                if(distance[dest]==INT_MAX){
                    q.push(dest);
                    distance[dest]=distance[node]+1;
                }
            }
        }
	//NOW, PRINT DISTANCE OF EACH NODE FROM SOURCE
        
    }
    
    void dfs_helper(T src ,map<T,bool>&visited){
        visited[src]=true;
        cout<<src<<"->";
        for(auto a:l[src]){
            if(!visited[a.first]){	//a.first means node adjacent to src . since l[source]->[{destination,weight},{},{}]
                dfs_helper(a.first,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool>visited;
        dfs_helper(src,visited);
    }
    
};

int main(){
    graph<char>g;
	
	//source,destination,weight,isbidirectional
    	g.addEdge('0', '1',4, 0);
	g.addEdge('0', '7',8, 0);
	g.addEdge('1', '7',11, 0);
	g.addEdge('1', '2',8, 0);
	g.addEdge('7', '8',7, 0);
	g.addEdge('2', '8',2, 0);
	g.addEdge('8', '6',6, 0);
	g.addEdge('2', '5',4, 0);
	g.addEdge('6', '5',2, 0);
	g.addEdge('2', '3',7, 0);
	g.addEdge('3', '3',14, 0);
	g.addEdge('3', '4',9, 0);
	g.addEdge('5', '4',10, 0);
	g.addEdge('7', '6',1, 0);
	g.printAdjacencyList();
}
