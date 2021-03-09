#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int v)
{
    if (parent[v] == -1)
        return v;
    return find(parent[v]);
}

void union_set(int fromP, int toP)
{
    fromP = find(fromP);
    toP = find(toP);
    parent[fromP] = toP;
}

bool isCycle(vector<pair<int, int>> &edge_list)
{
    for (auto &edge : edge_list)
    {
        int fromP = find(edge.first);
        int toP = find(edge.second);

        if (fromP == toP)
            return true;

        union_set(fromP, toP);
    }
    return false;
}

int main()
{
    int e;
    int v;

    cout << "Enter Number of Edges and Vertices: ";
    cin >> e >> v;

    parent.resize(v, -1);

    vector<pair<int, int>> egde_list;
    for (int i = 0; i < e; ++i)
    {
        int from, to;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> from >> to;
        egde_list.push_back({from, to});
    }

    if (isCycle(egde_list))
    {
        cout << "Its a Cycle" << endl;
        return 0;
    }

    cout << "Not a cycle" << endl;
    return 1;
}