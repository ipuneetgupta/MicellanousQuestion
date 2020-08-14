//depth first search
#include<bits/stdc++.h>
#include<cstring>
#include<list>

using namespace std;

class Graph{
	int v;
    list<int> *adj;

    public:
    	Graph(int v){
          this->v = v; //no of edges
          this->adj = new list<int>[v];//list contain the neighbours 
    	}


    void addEdge(int u,int v){
      this->adj[u].push_back(v);
      this->adj[v].push_back(u);
    }
    // recursive function to find dfs 

   void rec_dfsHelper(int node,bool *isVisited){
	   	cout<<node<<" ";
	     isVisited[node] = true;
	        for(auto p : this->adj[node]){
	           if(!isVisited[p]){
	           	rec_dfsHelper(p,isVisited);
	           }
	     	}
	     }

   void rec_dfs(int node){
   	 bool *isVisited = new bool[v];

     for(int i=0;i<this->v;i++){
     	isVisited[i] = false;
     }

     rec_dfsHelper(node,isVisited);
     
   }
    //iterative functoion to find dfs
    void iter_dfsHelper(){

    }
    void iter_dfs(){

    }
};


  
int main() 
{ 
   Graph g = Graph(5);
   g.addEdge(0,1);
   g.addEdge(2,3);
   g.addEdge(0,4);
   g.rec_dfs(0);
} 