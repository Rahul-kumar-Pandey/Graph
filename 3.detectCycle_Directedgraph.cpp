//cycle detection using bfs


//cycle detection using dfs 
bool isCyclicUtil(int v,vector<bool>&visited,vector<bool>&recStack,vector<int> adj[]){
	if(visited[v]==false){
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
