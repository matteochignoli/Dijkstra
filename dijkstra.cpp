#include <bits/stdc++.h>
#define INF 9999999

using namespace std;

//graph
list<pair<int,int>> grafo[10001];
//N=node M=edge
int N,M;

//dijkstra algorithm whit a priority queue
int dijkstra(int inizio, int fine){
    priority_queue<pair<int,int>> coda;
    vector<int> distanza(N+1,INF);
    distanza[inizio] = 0;
    coda.push(make_pair(0,inizio));

    while(!coda.empty()){
        //curr -> current node;  distCurr -> distance from start to curr
        const int curr = coda.top().second;
        //check if current node is the finish node
        if(curr == fine){
            break;
        }
        const int distCurr = distanza[curr];
        coda.pop();

        //looking at all the neighbor of the current node and updating the distance vector
        for(auto i=grafo[curr].begin();i!=grafo[curr].end();i++){
            const int v = i->second;
            const int weight = i->first;
            if(distanza[v]>distCurr+weight){
                distanza[v] = distCurr + weight;
                coda.push(make_pair(distanza[v]*(-1),v));
            }
        }
    }

    return distanza[fine];
}

int main(){
    //input from "input.txt" file
    freopen("input.txt","r",stdin);
    int inizio,fine;
    cin>>N>>M;
    cin>>inizio>>fine;
    
    //graph input
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        grafo[a].push_back(make_pair(c,b));
        grafo[b].push_back(make_pair(c,a)); //comment this line if you want a directed graph
    }

    //output on the screen the length of the shortest path
    cout<<dijkstra(inizio,fine)<<endl;
}