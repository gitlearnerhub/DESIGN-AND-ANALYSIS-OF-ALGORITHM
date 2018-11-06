/*
	Submitted by : VASHU DEV 
	Roll no		 : 41
	Question no. : 2(A), find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree 
*/

#include <stdio.h> 
#include<conio.h>
#include<iostream>
#define INF 100000

using namespace std;
int V;   

int minDistance(int dist[], bool Set[]) 
{ 
   /*
	Objective:to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree 
	*/
   int min = INF, min_index; 
   
   for (int v = 0; v < V; v++) 
     if (Set[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
   

int print(int dist[], int n) 
{ 
   cout<<"Vertex   Distance from Source\n"; 
   for (int i = 0; i < V; i++) 
      cout<<i<<"\t"<<dist[i]<<"\n";
} 
   

void dijkstra(int graph[ ][100], int src) 
{ 
/*
        Objective       : To find shortest paths from source to other vertices using dijkstra algorithm
        				  
        Input parameters: graph, integer array
        Return Value    : none
    */
     int dist[V];     
     bool Set[V]; 
     for (int i = 0; i < V; i++) 
        dist[i] = INF, Set[i] = false; 
   
     dist[src] = 0; 
   
     for (int count = 0; count < V-1; count++) 
     { 
       int u = minDistance(dist, Set); 
     
       Set[u] = true; 
   
       
       for (int v = 0; v < V; v++) 
		{
         if (!Set[v] && graph[u][v] && dist[u] != INF && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
    	}
     } 
   
      print(dist, V); 
} 
   

int main() 
{  
/*
        Objective       : To find shortest paths from source to other vertices using dijkstra algorithm
        				  
        Input parameters: none
        Return Value    : integer
    */

  	char ch;
  	int k=0;
  	int graph[100][100]; 
  	cout<<"\nEnter no of vertices: ";
  	cin>>V;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			graph[i][j]=k;
		}
	}

  	int e1,e2,d;
   	do
	{
		cout<<"\n Enter edge and distance: ";
		cin>>e1;
		cin>>e2;
		cin>>d;
		graph[e1][e2]=graph[e2][e1]=d;
		cout<<"\n Wish to enter more? "; cin>>ch;
	}while(ch=='y');
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<"\n";
	}
   
    dijkstra(graph, 0); 
    getch();
   
    return 0; 
} 
