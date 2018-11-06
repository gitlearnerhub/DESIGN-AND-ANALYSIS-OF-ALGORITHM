/*
	Submitted by : VASHU DEV 
	Roll no		 : 41
	Question no. : 2(B)0, To find shortest paths from source to other vertices using bellman's ford algorithm
*/

#include<iostream>
#include<stdlib.h>
#define MAX 1000000
using namespace std;

struct Edge
{
	int src,dest,weight;
};
	
struct Graph
{
	int v,e;
	Edge* edge;			// graph is represented as an array of edges. 
};



Graph* createGraph(int v,int e)				// Creates a graph with v vertices and e edges 
{
	Graph* graph = new Graph;
	graph->v=v;
	graph->e=e;
	graph->edge= new Edge[e];
	return graph;
}

void print(int dis[],int v)
{
	cout<<"\nVertex\tDistance From Source";
	for(int i=0;i<v;i++)
		cout<<"\n"<<i<<"\t"<<dis[i];
}

void Bellman(Graph* graph,int src)
{
	/*
	Objective:To find shortest paths from source to other vertices using bellman's ford algorithm
	*/
	int v=graph->v;
	int e=graph->e;
	int dis[v];
	for(int i=0;i<v;i++)
		dis[i]=MAX;
	dis[src]=0;
	
	for(int i=1;i<=v-1;i++)			//Relax all edges |v| - 1 times
	{
		for(int j=0;j<e;j++)
		{
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			int weight=graph->edge[j].weight;
			if(dis[u]!=MAX && dis[u]+weight<dis[v])
				dis[v]=dis[u]+weight;
		}
	}
	for (int i=0; i<e; i++) 			//check for negative-weight cycles
    { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dis[u] != MAX && dis[u] + weight < dis[v]) 
            cout<<"\nGraph contains negative weight cycle"; 
    } 
  
	
	
	print(dis,v);
	
}


int main()
{
	/*
	Objective:To find shortest paths from source to other vertices using bellman's ford algorithm
	*/
	int v,e;
	cout<<"\nEnter no of vertices : ";
	cin>>v;
	cout<<"\nEnter no of edges : ";
	cin>>e;
	int e1,e2,weight;
	Graph* graph = createGraph(v,e);
	for(int i=0;i<e;i++)
	{
		cout<<"\nEnter edge :\n";
		cin>>e1;
		cin>>e2;
		cin>>weight;
		graph->edge[i].src=e1;
		graph->edge[i].dest=e2;
		graph->edge[i].weight=weight;
	}
	
	Bellman(graph,0);
	return 0;

}
/*
	Time Complexity: O(VE)
		         For Complete Graphs, T(n) = O (V^3).
*/

