# include <bits/stdc++.h>

using namespace std;

class Graph{
    private:
        int V;
        vector<int> *adj;

        void explore(int s, bool *visited, int *CC, int CCnumber){
            // Explores and labels all the vertices present in a connected component
            visited[s] = true;

            CC[s] = CCnumber;

            for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
                if(!visited[*it])
                    explore(*it, visited, CC, CCnumber);
            }
        }

    public:
        Graph(int v){
            this->V = v;
            this->adj = new vector<int>[v];
        }

        void addEdge(int s, int d){
            adj[s].push_back(d);
            adj[d].push_back(s);
        }

        void explore(int s, bool *visited){
            // Explores all the edges reachable from a sourse S in DFS order.
            // The boolean array visited is required to be passed by the calling function.
            visited[s] = true;

            cout << s << " ";

            for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
                if(!visited[*it])
                    explore(*it, visited);
            }
        }

        void explore(int s, bool *visited, int *preVisit, int *postVisit, int &clock){
            // Explores all the edges reachable from a sourse S in DFS order and labes their previsit and postvisit orderings.
            // The int arrays preVisit and postVisit are passed by reference to store the ordering.
            // clock is also passed by reference;
            visited[s] = true;
            preVisit[s] = clock++;
            
            for(auto it=adj[s].begin(); it!=adj[s].end(); it++){
                if(!visited[*it])
                    explore(*it, visited, preVisit, postVisit, clock);
            }

            postVisit[s] = clock++;
        }

        void DFS(){
            // Standard DEPTH FIRST SEARCH of the

            bool *visited = new bool[this->V];
            for(int i=0; i<this->V; i++)
                visited[i] = 0;

            for(int i=0; i<this->V; i++){
                if(!visited[i])
                    explore(i, visited);
            }
        }

        int* connectedComponents(){
            // Returns an array of size this->V containg all the different connected components labelled.
            // The index i and j having same label means that they are part of the same connected component and are reachable from each other...
            bool *visited = new bool[this->V];
            for(int i=0; i<this->V; i++)
                visited[i] = 0;

            int *CC = new int[this->V];

            int CCnumber = 1;

            for(int i=0; i<this->V; i++){
                if(!visited[i]){
                    explore(i, visited, CC, CCnumber);
                    CCnumber++;
                }
            }

            return CC;
        }

        void DFS(int *preVisit, int *postVisit){
            // This function takes pointers to two arrays called preVisit and postVisit and sotores the DFS ordering of vertices in the arrays
            bool *visited = new bool[this->V];
            for(int i=0; i<this->V; i++)
                visited[i] = 0;

            int clock = 0;

            for(int i=0; i<this->V; i++){
                if(!visited[i])
                    explore(i, visited, preVisit, postVisit, clock);
            }
        }

};

int main(){
    Graph *g = new Graph(10);
    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(8, 9);

    int *prev = new int[10];
    int *post = new int[10];

    g->DFS(prev, post);

    for(int i=0; i<10; i++)
        cout << i << " : " << prev[i] << " / " << post[i] << endl;

    return 0;
}