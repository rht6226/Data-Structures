# include <bits/stdc++.h>
using namespace std;

// Disjoint set data structure implemented using union by rank and path comptression

class disjoint_set{
    private:
        int *parent;
        int *rank;
        int size;
    public:
        disjoint_set(int n){
            this->parent = new int[n];
            this->rank = new int[n];
            this->size = n;
            for(int i=0; i<n; i++){
                this->parent[i] = i;
                this->rank[i] = 0;
            }
        }

        int find(int a){
            if(a != this->parent[a])
                this->parent[a] = this->find(this->parent[a]);
            return this->parent[a];
        }

        void Union(int a, int b){
            int a_id = find(a);
            int b_id = find(b);
            if(a_id == b_id)
                return;
            if(rank[a_id] > rank[b_id])
                parent[b_id] = a_id;
            else{
                parent[a_id] = b_id;
                if(rank[a_id] == rank[b_id])
                    rank[b_id] = 1 + rank[b_id];
            }
        }
};

int main(){
    disjoint_set *s = new disjoint_set(11);

    s->Union(2, 4);
    s->Union(4, 6);
    s->Union(6, 8);

    s->Union(3, 9);
    s->Union(0, 1);
    s->Union(1, 10);

    for(int i=0; i<=10; i++)
        cout << i << " -> " << s->find(i) << endl;

    return 0;
}
