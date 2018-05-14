// Depth-first search
// Program uses DFS to find all components of undirected graph and shows vertices of each component
// a.exe < input.txt
// input.txt
//      number of vertices
//      adjacency matrix

#include <iostream>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

void dfs(const Graph& graph, int u, vector<char>& states, vector<int>& vertices)
{
    states[u] = 'G';
    vertices.push_back(u);
    for (int i = 0; i < graph[u].size(); ++i)
    {
        if (states[graph[u][i]] == 'W')
        {
            dfs(graph, graph[u][i], states, vertices);
        }
    }
    states[u] = 'B';
}

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
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        if (states[i] == 'W')
        {
            ++num;
            vector<int> vertices;
            dfs(graph, i, states, vertices);
            cout << num << ": ";
            for (auto v: vertices)
            {
                cout << " " << v;
            }
            cout << endl;
        }
    }
    
    return 0;
}