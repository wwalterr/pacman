
#ifndef DIJKSTRA_H

#define DIJKSTRA_H

#include <iostream>

#include <queue>

#include <list>

using namespace std;

class Dijkstra
{
  protected:
    int v;

    int infinite;

    list<pair<int, int>> *adj;

  public:
    Dijkstra(void);

    Dijkstra(const int);

    Dijkstra(Dijkstra &);

    virtual ~Dijkstra(void);

    void operator=(Dijkstra &);

    void setV(const int);

    int getV(void);

    virtual void addEdge(const int, const int, const int);

    int dijkstra(const int, const int) const;
};

#endif