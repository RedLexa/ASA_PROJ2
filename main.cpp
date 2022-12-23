//
// Created by alexa on 22/12/2022.
//
#include <bits/stdc++.h>
#include <map>
#include <tuple>
#include <vector>
#include <list>
using namespace std;
int V;
int E;
unsigned long long maxcost;
vector<int> upper;
vector<int> rankV;
map<tuple<int,int>,int> graph;

void processInput(){
    int a=0,b=0, w=0;
    tuple <int,int> path;
    cin >> V;
    cin >> E;
    for(int i = 0; i < 6;i++){
        cin >> a;
        cin.ignore();
        cin >> b;
        cin.ignore();
        cin >> w;
        path = make_tuple(a,b);
        graph.insert({path,w});
    }
    for (int i = 0; i < V; i++){
        upper.push_back(-1);
        rankV.push_back(1);
    }

}

int find(int i){
    if (upper[i] == -1)
        return i;

    return upper[i] = find(upper[i]);
}

void uni(int i, int j){
    int a = find(i);
    int b = find(j);

    if (a != b) {
        if (rankV[a] < rankV[b]) {
            upper[a] = b;
        }
        else if (rankV[a-1] > rankV[b-1]) {
            upper[b] = a;
        }
        else {
            upper[b] = a;
            rankV[a] += 1;
        }
    }
}
bool cmp(pair<tuple<int,int>, int>& a,
         pair<tuple<int,int>, int>& b){
    return a.second > b.second;
}

void getmaxcost(){

    vector<pair<tuple<int,int>, int> > Vec;
    for (auto& it : graph) {
        Vec.emplace_back(it);
    }
    sort(Vec.begin(), Vec.end(), cmp);

    for(auto & i : Vec) {
        if (find(get<0>(i.first)-1) != find(get<1>(i.first)-1)) {
            uni(get<0>(i.first)-1, get<1>(i.first)-1);
            maxcost += i.second;
        }

    }
}



int main(){
    processInput();
    getmaxcost();
    printf("%llu\n", maxcost);
    return 0;
}

/* #include <bits/stdc++.h>
using namespace std;

#define V 8
int parent[V];

// Find set of vertex i
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V])
{
    int mincost = 0; // Cost of min MST.

    // Initialize sets of disjoint sets.
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = 0, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] > min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union(a, b);
        edge_count++;
        mincost += min;
    }
    printf("\n Max cost= %d \n", mincost);
}

// driver program to test above function
int main()
{

    int cost[][V] = {
            { 0, 2, 0, 0, 4, 0,0, 3},
            { 1, 0, 0, 0, 4, 8,0, 9},
            { 0, 0, 0, 1, 0, 0,3, 0},
            { 0, 0, 1, 0, 0, 0,4, 0},
            { 4, 4, 0, 0, 0, 8,0, 0},
            { 0, 8, 0, 0, 8, 0,0, 5},
            { 0, 0, 3, 4, 0, 0,0, 0},
            { 3, 9, 0, 0, 0, 5,0, 0},
    };

    // Print the solution
    kruskalMST(cost);

    return 0;
} */