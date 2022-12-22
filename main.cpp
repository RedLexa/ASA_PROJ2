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
unsigned long long solution;
vector<int> upper;
map<tuple<int,int>,int> graph;
void processInput(){
    int a,b, w;
    tuple <int,int> path;
    scanf("%d\n",&V);
    scanf("%d\n",&E);
    for(int i = 1; i < V;i++) {
        upper[i] = i;
    }
    for(int i = 1; i < E;i++){
        scanf("%d %d %d\n",&a,&b,&w);
        path = make_tuple(a,b);
        graph.insert({path,w});
    }
}





int main(){
    processInput();
    return 0;
}