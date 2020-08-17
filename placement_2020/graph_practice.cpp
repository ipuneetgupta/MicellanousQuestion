//depth first search
#include<bits/stdc++.h>
#include<cstring>
#include<queue>
#include<stack>
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
      // this->adj[v].push_back(u);
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
     cout<<endl;
     
   }
    //iterative functoion to find dfs
    void iter_dfs(int node){
      bool *isVisited = new bool[this->v];
      for(int i = 0;i<this->v;i++){
        isVisited[i] = false;
      }
      stack<int> s;
      s.push(node);
      while(!s.empty()){
        int currNode = s.top();
        s.pop();
        if(!isVisited[currNode]){
          cout<<currNode<<" ";
          isVisited[currNode] = true;
        }        
        for(auto i : this->adj[currNode]){
          if(!isVisited[i]){
            s.push(i);
          }
        }
      }
      cout<<endl;
    }


    // iterative breadth first search
    void iter_bfs(int node){

      bool *isVisited = new bool[this->v];
      for(int i=0;i<this->v;i++){
        isVisited[i] = false;
      }
      //intitate queue for bfs

      queue<int> q;
      q.push(node);
      while(!q.empty()){
        int currNode = q.front();
        q.pop();
        if(!isVisited[currNode]){
          cout<<currNode<<" ";
          isVisited[currNode] = true;
        }
        //find neighboures
        for(auto i : this->adj[currNode]){
          if(!isVisited[i]) q.push(i);
        } 
      }
      cout<<endl;
    }


    // isbipartite or coloring a graph
    bool isBipartite(){
      
    }
};


  
int main() 
{ 
   Graph g = Graph(5);
   g.addEdge(1, 0); 
   g.addEdge(0, 2); 
   g.addEdge(2, 1); 
   g.addEdge(0, 3); 
   g.addEdge(1, 4); 
   cout<<"recursive DFS::"<<endl;
   g.rec_dfs(0);
   cout<<"iterative DFS::"<<endl;
   g.iter_dfs(0);
   cout<<"Iterative bfs::"<<endl;
   g.iter_bfs(0);
   cout<<"recursive BFS::"<<endl;
   g.isBipartite(0);
} 