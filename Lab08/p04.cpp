// Bellman-Ford algorithm
// a.exe < input.txt
// input.txt
//    <number of vertices> <number of edges>
//    list of edges in following order: <start_vertex> <end_vertex> <weight>
// Program finds shortest path from vertex 0 to all other vertices.
// If graph has a negative cycle program prints corresponding message 
// otherwise prints weights of shortest paths to all vertices (inf means "vertex unreachable")

#include<iostream>
#include<vector>

struct Edge
{
	int u, v, w;
};

const int UNDEFINED = 0;
const int DEFINED = 1;

int main()
{
	using namespace std;

	int n; cin >> n;
	int m; cin >> m;
    
	vector<Edge> edges;
	for (int i = 0; i < m; ++i)
	{
		Edge e; cin >> e.u >> e.v >> e.w;
		edges.push_back(e);
	}
	
	vector<int> d(n, -1);
	vector<int> r(n, UNDEFINED);
	
	d[0] = 0;
    r[0] = DEFINED;
	
    for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			Edge e = edges[j];
			if (r[e.u] == DEFINED && r[e.v] == DEFINED)
			{
				if (d[e.v] > d[e.u] + e.w)
				{
					d[e.v] = d[e.u] + e.w;
					r[e.v] = DEFINED;
				} 
			}
			else if (r[e.u] == DEFINED && r[e.v] == UNDEFINED)
			{
				d[e.v] = d[e.u] + e.w;
				r[e.v] = DEFINED;
			}
		}
	}
    
    bool hasNegCycle = false;
    for (int i = 0; i < m and not hasNegCycle; ++i)
    {
        Edge e = edges[i];
        if (r[e.u] == DEFINED && r[e.v] == DEFINED)
        {
            if (d[e.v] > d[e.u] + e.w)
            {
                hasNegCycle = true;
            } 
        }
        else if (r[e.u] == DEFINED && r[e.v] == UNDEFINED)
        {
            hasNegCycle = true;
        }
    }
    
	
    if (not hasNegCycle)
    {
        for (int  i = 0; i < n; ++i)
        {
            if (r[i] == DEFINED)
            {
                cout << d[i];
            }
            else
            {
                cout << "inf";
            }
            cout << ' ';
        }
    }
    else
    {
        cout << "negative cycle" << endl;
    }
	
    cout << endl;
	
	return 0;
}
