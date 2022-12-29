#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int V;
int E;
int maxcost;
vector<int> upper;
vector<int> rankV;
vector<pair<tuple<int,int>, int> > Vec;

void processInput(){
    int a=0,b=0, w=0;
    tuple <int,int> path;
    cin >> V;
    cin >> E;
    for(int i = 0; i < E;i++){
        cin >> a;
        cin.ignore();
        cin >> b;
        cin.ignore();
        cin >> w;
        path = make_tuple(a,b);
        Vec.push_back({path,w});
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

void union1(int i, int j){
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
    sort(Vec.begin(), Vec.end(), cmp);
    for(auto & i : Vec) {
        if (find(get<0>(i.first)-1) != find(get<1>(i.first)-1)) {
            union1(get<0>(i.first)-1, get<1>(i.first)-1);
            maxcost += i.second;
        }

    }
}

int main(){
    std::ios::sync_with_stdio(false);
    processInput();
    getmaxcost();
    printf("%d\n", maxcost);
    return 0;
}