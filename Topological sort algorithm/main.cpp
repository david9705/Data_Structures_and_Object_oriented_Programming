#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

typedef struct Node
{
  int color;
  int discover;
  int predecessor;
};

class Graph
{
public:
    Graph(){};
    Graph(int N);
    void addEdge(int src, int dst);
    void DFS(int Start);
    void DFSVisit(int vertex, int &time);
    list< int> TopologicalSort(int Start);

    int num_vertex;
private:
    vector< list<int> > AdjList;
    list<int> TopoList;
    int *color,
        *finish,
        *discover,
        *predecessor;


};

Graph::Graph(int N)
{
    num_vertex = N;
    AdjList.resize(N);
    TopoList.clear();
}

void Graph::addEdge(int src, int dst)
{
    AdjList[src].push_back(dst);
}

void Graph::DFS(int Start)
{
    color = new int[num_vertex];
    discover = new int[num_vertex];
    finish = new int[num_vertex];
    predecessor = new int[num_vertex];

    int time = 0;
    for(int i = 0; i < num_vertex; i++)
    {
        color[i] = 0;       //0:white 1:gray 2:black
        discover[i] = 0;
        finish[i] = 0;
        predecessor[i] = -1;
    }

    int n = Start;
    for(int i = 0; i < num_vertex+1; ++i)
    {
        if( color[n] == 0)
        {
            DFSVisit(n, time);
        }
        n = i;
    }

}

void Graph::DFSVisit(int vertex, int &time)
{
    color[vertex] = 1;
    discover[vertex] = ++time;
    for ( list<int>::iterator itr = AdjList[vertex].begin(); itr != AdjList[vertex].end(); itr++)
    {
        if (color[*itr] == 0)                  //
        {
            predecessor[*itr] = vertex;        // update predecessor
            DFSVisit(*itr, time);              // change vertex, do new DFSVisit
        }
    }
    color[vertex] = 2;
    finish[vertex] = ++time;
    TopoList.push_back(vertex);
    cout<<vertex<<" ";
}

list<int> Graph::TopologicalSort(int Start)
{
    DFS(Start);
    return TopoList;


}

FILE *fin = fopen("sample data.txt", "rb");
FILE *fout = fopen("TP_Sort_0413354.txt", "wb");
map< int, int> datamap;
map< int, int> datamap_inv;
map<int,int>::iterator it;


int main()
{

    char line[1000], *sep = " ", *p;
    int num, graph_size, n, constraint[2];
    list< int> result;

    while(fgets(line, 1000, fin))
    {
        graph_size =  atoi(strtok(line, sep));
        Graph graph(graph_size);
        n = 0;

        //initialize graph
        fgets(line, 1000, fin);
        p = strtok(line, sep);
        while(p)
        {
            num = atoi(p);
            datamap[num] = n;
            datamap_inv[n] = num;
            cout<<"datamap "<<num<<" = "<<datamap[num]<<endl;
            p = strtok(NULL, sep);
            n++;
        }

        // get layer constraint
        fgets(line, 1000, fin);
        n =  atoi(strtok(line, sep));
        while(n--)
        {
            fgets(line, 1000, fin);
            num = atoi(strtok(line, sep));
            constraint[0] = datamap.find(num)->second;
            p = strtok(NULL, sep);
            num = atoi(strtok(NULL, sep));
            constraint[1] = datamap.find(num)->second;
            graph.addEdge(constraint[0], constraint[1]);
        }

        // start from 0
        result = graph.TopologicalSort(0);

        cout<<endl<<graph_size<<" "<<result.size()<<" "<<"Result: ";
        for( list<int>::iterator it = result.begin(); it != result.end(); ++it)
        {
            num = datamap_inv.find(*it)->second;
            cout<<num<<" ";
            fprintf(fout, "%d ", num);
        }
        fprintf(fout, "\n");
        cout<<endl;
        fgets(line, 1000, fin);
    }

    fclose(fin);
    fclose(fout);
    return 0;

}


