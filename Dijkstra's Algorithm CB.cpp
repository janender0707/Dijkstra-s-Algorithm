#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

template<typename T>
class graph{
unordered_map<T,list<pair<T,int>>> n;
public:
    void addEdge(T u,T v,int dist, bool bidir=true){
    n[u].push_back(make_pair(v,dist));
    if(bidir){
        n[v].push_back(make_pair(u,dist));
    }
    }

    void printAdj(){
    for(auto j:n){
        cout<<j.first<<"-->";
        for(auto l:j.second){
            cout<<"("<<l.first<<","<<l.second<<")";
        }
        cout<<endl;
    }
    }

    void dijkstraSSSp(T src){
    unordered_map<T,int> dist;
    for(auto j:n){
        dist[j.first]=INT_MAX;
    }
    set<pair<int,T>> s;
    dist[src]=0;
    s.insert(make_pair(0,src));
    while(!s.empty()){

            auto p=*(s.begin());
            T node=p.second;
            int nodeDist=p.first;
            s.erase(s.begin());

            for(auto childPair:n[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    T dest=childPair.first;
                    auto f=s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest]=nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist){
            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }
    }
};


int main()
{
    graph<string> India;
    India.addEdge("Amritsar","Delhi",1);
    India.addEdge("Amritsar","Jaipur",4);
    India.addEdge("Jaipur","Delhi",2);
    India.addEdge("Jaipur","Mumbai",8);
    India.addEdge("Bhopal","Agra",2);
    India.addEdge("Mumbai","Bhopal",3);
    India.addEdge("Agra","Delhi",1);

    India.dijkstraSSSp("Amritsar");

    return 0;
}
