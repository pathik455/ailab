#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    map<T, list<T>> m;
    public:
        void addEdge(T x,T y){
            m[x].push_back(y);
            m[y].push_back(x);
        }

        
        void dfsHelper(T src , map<T,bool> &visited){
                     
            visited[src] = true;            

            for(auto nbr : m[src]){
                if(!visited[nbr]){
                    dfsHelper(nbr, visited);
                }
            }
            cout << src << "-> ";  
        }
        void DFS(T src){
            map<T, bool> visited; 
            for(auto p : m){
                T node = p.first;
                visited[node] = false;
            }
             
            dfsHelper(src, visited);
        }
};

int main(){
  graph<char> g;
    g.addEdge('a', 'b');
    g.addEdge('a', 'c');
    g.addEdge('b', 'd');
    g.addEdge('d', 'e');
    g.addEdge('d', 'f');
    g.addEdge('e', 'g');
    g.addEdge('g', 'h');

    g.DFS('a');
    
    return 0;
}