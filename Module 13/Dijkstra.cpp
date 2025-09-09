#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll, ll>> adj_list[100005];
ll dis[100005];
ll parant[100005];

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({ 0,src });
    dis[src] = 0;

    while (!pq.empty())
    {
        ll par_node = pq.top().second;
        ll par_cost = pq.top().first;
        pq.pop();

        for (auto child : adj_list[par_node])
        {
            ll ch_node = child.second;
            ll ch_cost = child.first;
            if (par_cost + ch_cost < dis[ch_node])
            {
                dis[ch_node] = par_cost + ch_cost;
                pq.push({ dis[ch_node],ch_node });
                parant[ch_node] = par_node;

            }
        }
    }

}

int main()
{
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({ c,b });
        adj_list[b].push_back({ c,a });
    }

    for (ll i = 1;i <= n;i++)
    {
        dis[i] = LLONG_MAX;
        parant[i] = -1;
    }
    dijkstra(1);

    if (dis[n] != LLONG_MAX)
    {
        vector<ll> path;
        ll nd = n;
        while (nd != -1)
        {
            path.push_back(nd);
            nd = parant[nd];
        }
        reverse(path.begin(), path.end());
        for (ll p : path)
        {
            cout << p << " ";
        }
    }else{
        cout << -1 << endl;
    }


    return 0;
}