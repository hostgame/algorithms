// Breadth-first search
// Program shows distances, predecessors and path from start to destination
// 
// a.exe < input.txt
// input.txt: 
//       number of vertices
//       adjacency matrix for graph on picture 22.3 (Cormen 3rd edition)
//       start
//       destination

 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int nil = -1;
const int inf = -2;

using Graph = vector<vector<int>>;

int main()
{
    int n; cin >> n;
    
    Graph graph(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char c; cin >> c;
            if (c == '1')
            {
                graph[i].push_back(j);
            }
        }
    }
    
    vector<char> states(n, 'W');
    vector<int> distances(n, inf);
    vector<int> predecessors(n, nil);
    
    int start; cin >> start;
    
    queue<int> q;
    q.push(start);
    states[start] = 'R';
    distances[start] = 0;
    while (not q.empty())
    {
        int u = q.front(); q.pop();
        states[u] = 'B';
        for (auto v: graph[u])
        {
            if (states[v] == 'W')
            {
                states[v] = 'R';
                distances[v] = distances[u] + 1;
                predecessors[v] = u;
                q.push(v);
            }
        }
    }
  
    cout << "distances:";
    for (auto d: distances)
    {
        cout << " " << d;
    }
    cout << endl;
    
    cout << "predecessors:";
    for (auto p: predecessors)
    {
        cout << " " << p;
    }
    cout << endl;
    
    int dest; cin >> dest;
    vector<int> path;
    if (predecessors[dest] == nil)
    {
        cout << "no path" << endl;
    }
    else
    {
        cout << "path to " << dest << ": "; 
        path.push_back(dest);
        while (dest != start)
        {
            dest = predecessors[dest];
            path.push_back(dest);
        }
        reverse(path.begin(), path.end());
        
        for (auto v: path)
        {
            cout << " " << v;
        }
        cout << endl;
    }
    
    return 0;
}