
#include "dijkstra.hpp"

Dijkstra::Dijkstra(void)
{
    this->v = 1;

    this->infinite = 99999999;
}

Dijkstra::Dijkstra(const int vertices)
{
    this->v = vertices;
    adj = new list<pair<int, int>>[this->v];

    this->infinite = 99999999;
}

Dijkstra::Dijkstra(Dijkstra &obj)
{
    this->v = obj.getV();
}

Dijkstra::~Dijkstra(void)
{
    delete[] this->adj;
}

void Dijkstra::operator=(Dijkstra &obj)
{
    this->v = obj.getV();
}

void Dijkstra::setV(const int vertices)
{
    this->v = vertices;
}

int Dijkstra::getV(void)
{
    return this->v;
}

void Dijkstra::addEdge(const int v_base, const int v_destiny, const int vd_coast)
{
    this->adj[v_base].push_back(make_pair(v_destiny, vd_coast));
}

int Dijkstra::dijkstra(const int origin, const int destity) const
{
    int dist[this->v]{0};

    int visited[this->v]{0};

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>, greater<pair<int, int>>>
        p_queue;

    for (register int counter = 0; counter < this->v; counter++)
    {
        dist[counter] = infinite;

        visited[counter] = 0;
    }

    dist[origin] = 0;

    p_queue.push(make_pair(dist[origin], origin));

    while (!p_queue.empty())
    {
        pair<int, int> top = p_queue.top();

        int v_top = top.second;

        p_queue.pop();

        if (!visited[v_top])
        {
            visited[v_top] = 1;

            list<pair<int, int>>::iterator it;

            for (it = adj[v_top].begin(); it != adj[v_top].end(); it++)
            {
                int v_ = it->first;

                int c_ = it->second;

                if (dist[v_] > (dist[v_top]))
                {
                    dist[v_] = dist[v_top] + c_;

                    p_queue.push(make_pair(dist[v_], v_));
                }
            }
        }
    }

    return dist[destity];
}