// Topological sort
// a.exe < input.txt
// input.txt
//      number of courses
//      list of edges in format: course1 course2
// Program prints courses in order which satisfies given prerequisites

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Graph = vector<vector<int>>;

void dfs(const Graph& graph, int u, vector<char>& states, vector<int>& courses)
{
    states[u] = 'G';
    for (int i = 0; i < graph[u].size(); ++i)
    {
        if (states[graph[u][i]] == 'W')
        {
            dfs(graph, graph[u][i], states, courses);
        }
    }
    states[u] = 'B';
    
    courses.push_back(u);
}

int main()
{
    int n; cin >> n;
    
    Graph graph(n);
    int u;
    int v;
    while (cin >> u >> v)
    {
        graph[u].push_back(v);
    }
    
    vector<char> states(n, 'W');
    vector<int> courses;
    
    for (int i = 0; i < n; ++i)
    {
        if (states[i] == 'W')
        {
            vector<int> vertices;
            dfs(graph, i, states, courses);
        }
    }
    
    reverse(courses.begin(), courses.end());
    
    for (auto c: courses)
    {
        cout << c << ' ';
    }
    cout << endl;
    
    
    return 0;
}