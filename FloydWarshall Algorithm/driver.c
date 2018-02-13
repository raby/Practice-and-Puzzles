#include <stdio.h>
#include <limits.h>
//Created by David Pynes
//Coded in Sublime / Compiled with GCC


/*
PSUEDO CODE:
let dist be a |V| × |V| array of minimum distances initialized to infinity
for each vertex v
    dist[v][v] = 0
for each edge (u,v)
    dist[u][v] = w(u,v)  // the weight of the edge (u,v)
 for k from 1 to |V|
    for i from 1 to |V|
       for j from 1 to |V|
          if dist[i][j] > dist[i][k] + dist[k][j]
             dist[i][j] = dist[i][k] + dist[k][j]
         end if
*/

int add( int a, int b)
{
    int c = a & b;
    int res = a ^ b;
    while(c != 0)
    {
        int sc = c << 1;
        c = res & sc;
        res ^= sc;
    }
    return res;
}

int main(int argc, char *argv[]) {

   int v = *argv[1]-'0';
   int i,j,k;

   long graph[v][v];
   long dist[v][v];

   printf("There are %d vertices in the graph. Let's make some edges.\n", v);

   for(i=0;i<v;i++)
   	for(j=0;j<v;j++)
   		graph[i][j] = INT_MAX;

	printf("\nSelect vertices and assign a cost to the edge between vertices.\nInput -1 when complete.\n");
   while(1)
   {

 	  printf("Select 0 to %d for the first vertex.\n", v-1);
 	  scanf ("%d",&i);
 	  printf("Select 0 to %d for the second vertex.\n", v-1);
 	  scanf("%d",&j);
 	  printf("Assign a positive or negative value as the cost of the edge.\n");
 	  scanf("%d",&k);

 	  if(i==-1 || j==-1)
 	  	break;

 	  if(i>v || j>v)
 	  	printf("Error: select a vertex in graph.");
 	  else
 	  	graph[i][j] = k;
   }

   for(i=0;i<v;i++)
   	for(j=0;j<v;j++)
   		dist[i][j] = INT_MAX;

   	for(i=0;i<v;i++)
   		dist[i][i] = 0;

   	for(i=0;i<v;i++)
   		for(j=0;j<v;j++)
   			if(graph[i][j]!=INT_MAX)
   				dist[i][j] = graph[i][j];

   	for(k=0;k<v;k++)
   		for(i=0;i<v;i++)
   			for(j=0;j<v;j++)
        {
          if( !(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) )
          {
   				 if(dist[i][j] > add( dist[i][k] , dist[k][j]) )
   					  dist[i][j] = add( dist[i][k] , dist[k][j] );
          }
        }


	printf("Printing results of Floyd Warshall Algorithm: \n  ");
	for(i=0;i<v;i++)
   		printf ("%d\t\t", i);

   	printf("\n");
   	for(i=0;i<v;i++)
  	{
  		printf ("%d ", i);
   		for(j=0;j<v;j++)
   		{
   			if(dist[i][j]>=INT_MAX)
   				printf("N/A\t\t");
   			else
   				printf ("%d\t\t", dist[i][j]);
   		}
   		printf("\n");
   	}

   system("pause");
   return 0;
}
