#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a;
    int b;
    long long int c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

};

vector<Edge> edge_list;
int n, e;
long long int dis[1005];
bool cycle = false;

void belman_ford(int src)
{
    for (int i = 1;i <= n;i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long int  c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    cycle = false;
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long int  c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

}


int main()
{

    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src, t;
    cin >> src >> t;
    for (int i = 1;i <= n;i++)
        dis[i] = LLONG_MAX;
    dis[src] = 0;

    belman_ford(src);
    if (cycle)
        cout << "Negative Cycle Detected" << endl;
    else {
        while (t--)
        {
            int d;
            cin >> d;
            if (dis[d] != LLONG_MAX)
                cout << dis[d] << endl;
            else
                cout << "Not Possible" << endl;
        }
    }

    return 0;
}