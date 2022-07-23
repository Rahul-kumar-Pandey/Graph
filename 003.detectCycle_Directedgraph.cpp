//cycle detection using bfs(kahn's algo)
/*
idea: Topological sort can be applied for DAG ,so if a graph has cycle then we cannot get topo sort .
*/
bool isCycleUsingTopological_sort(){
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
	    int cnt=0;            
            //start removing elements from the queue
            while(!q.empty()){
                T node =q.front();
                cnt++;	
                q.pop();
                
                //iterate over nbrs of that node and reduce their indegree
                for(auto nbr:l[node]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0)
                        q.push(nbr);
                }
            }
	if(cnt==V) return false;
	return true;
}


/***************************************************************************************************/
//cycle detection using dfs 
bool isCyclicUtil(int v,vector<bool>&visited,vector<bool>&recStack,vector<int> adj[]){
		visited[v]=true;
        	recStack[v]=true;
        	for(auto a:adj[v]){
            		if(!visited[a]){
                		if(isCyclicUtil(a,visited,recStack,adj))
                    			return true;
            		}
            
            		else if(visited[a] && recStack[a]){
                		return true;
            		}
        	}
 
		recStack[v]=false;
		return false;
    }
	bool isCyclic(int V, vector<int> adj[]) {
	   	// Mark all the vertices as not visited and not part of recursion 
		// stack
		vector<bool> visited(V, false); 
		vector<bool> recStack(V, false); 

		// Call the recursive helper function to detect cycle in different 
		// DFS trees(this will work for multiple components of graph;
		for(int i = 0; i < V; i++) 
			if (isCyclicUtil(i, visited, recStack, adj)) 
				return true; 

		return false;
	}

/***
testing testcase
1->{2}
2->{3,4}
3->{7,8}
4->{5}
5->{6}
6->{4}
7->{}
8->{7}
***/
