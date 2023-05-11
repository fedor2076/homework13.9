
#include "graph.h"

int main()
{
    Graph g;
    g.addVertex("Oleg");
    g.addVertex("Nikita");
    g.addVertex("Nastya");
    g.addVertex("Boris");
    g.addVertex("Ivan");
    g.addVertex("Jenya");
    g.addEdge("Oleg", "Nikita");
    g.addEdge("Nikita", "Nastya");
    g.addEdge("Nastya", "Ivan");
    g.addEdge("Ivan", "Jenya"); 
    g.addEdge("Boris", "Nastya"); 
    g.addEdge("Boris", "Jenya");

 

    g.findMinDistancesFloyd();


}
