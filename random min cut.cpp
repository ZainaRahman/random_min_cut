#include <bits/stdc++.h>
using namespace std;

int main() {
    int edge, nodes;
    cin >> edge >> nodes;

    vector<pair<int,int>> adj_list;

    int u, v;
    int maxNode = -1;

    for (int i = 0; i < edge; i++) {
        cin >> u >> v;
        adj_list.push_back({u, v});
        maxNode = max(maxNode, max(u, v));
    }

    int j = 0;

    while (nodes > 2) {

        int node1 = adj_list[j].first;
        int node2 = adj_list[j].second;

        int newnode = ++maxNode;

        vector<pair<int,int>> adj_list1;

        for (auto &e : adj_list) {
            int x = e.first;
            int y = e.second;


            if (x == node1 || x == node2) x = newnode;
            if (y == node1 || y == node2) y = newnode;


            if (x != y) {
                adj_list1.push_back({x, y});
            }
        }

        adj_list = adj_list1;
        nodes--;


        j = 0;
    }

    for(int i=0;i<adj_list.size();i++){
        cout<<adj_list[i].first<<" "<<adj_list[i].second<<endl;
    }


    cout << "Min cut edges count: " << adj_list.size() << endl;

    return 0;
}
