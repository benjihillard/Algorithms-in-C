#include<stdio.h>
#include<stdlib.h>
#define NUMBER_OF_NODES 6
#define INFINITY 99999
 struct Node
   {
    int arrow[NUMBER_OF_NODES];
   };

void travel(int next, int j, int* distance, int* predecessor, int* allowed, struct Node *node);

int find_next(int* distance, int* allowed);

int terminate(int* allowed,int destination);

int main(){

 

FILE *inputp;

struct Node node[NUMBER_OF_NODES];

int i, j;
int distance[NUMBER_OF_NODES];
int allowed[NUMBER_OF_NODES];
int predecessor[NUMBER_OF_NODES];
int start, destination;
int stop, next, route;

 

printf("Please enter the start node \n");

scanf(" %d", &start);

printf("Please enter the destination node \n");

scanf(" %d", &destination);

 
//setting up arrays
 
//set up distance
for(i=0; i<NUMBER_OF_NODES; i++)
   {
    if(i==start)
      {
       distance[i]=0;
      }
    else
       {
       distance[i]=INFINITY;
       }
   }

 
//set up allowed
for(i=0; i<NUMBER_OF_NODES; i++)
   {
    if(i==start)
      {
      allowed[i]=0;
      }
    else
      {
      allowed[i]=0;
      }
   }

 
//set up pred
for(i=0; i<NUMBER_OF_NODES; i++)
   {
    if(i==start)
      {
      predecessor[i]=start;
      }
    else
      {
      predecessor[i]=-1;
      }
   }

//bulk of the work

inputp = fopen("graph.txt", "r");
for(j=0; j<NUMBER_OF_NODES; j++)
   {
    for(i=0; i<NUMBER_OF_NODES; i++)
       {
        fscanf(inputp, "%d", &node[j].arrow[i]);
       }
   }
for(j=0; j<NUMBER_OF_NODES; j++, printf("\n"))

for(i=0; i<NUMBER_OF_NODES; i++)

{ 



printf( "%d  ", node[j].arrow[i]); 

}
while(stop!=1){

travel(next,j,distance,predecessor,allowed,node);
stop=terminate(allowed,destination);

}

next=start;

//printing results

 printf("The predecessor array  is \n");

 

for(i=0; i<NUMBER_OF_NODES; i++)

printf("%d ", predecessor[i]);

 

printf(" \n");

printf("The distance array  is \n");

 

for(i=0; i<NUMBER_OF_NODES; i++)

printf("%d ", distance[i]);

printf(" \n");

 

printf("The allowed array  is \n");

 
for(i=0; i<NUMBER_OF_NODES; i++)

printf("%d ", allowed[i]);

printf(" \n");

printf(" Your shortest route is from %d ",destination);
route=destination;
while(route!=start)
     {
     route=predecessor[route];
     printf("to %d ",route);
     }
printf("\n");

return 0;

}




void travel(int next, int j, int* distance, int* predecessor, int* allowed, struct Node *node){
int i;
j=find_next(distance,allowed);
for(i=0; i<NUMBER_OF_NODES; i++)
   {
   if(allowed[i]<1)
     {
     if((node[j].arrow[i])>(-1))
       {
       if(((node[j].arrow[i])+distance[j])<distance[i])
         {
         predecessor[i]=j;
         distance[i]=((node[j].arrow[i])+distance[j]);
         }
       }
     }
   }
}

int find_next(int* distance, int* allowed){
int min=9999;
int next,i;
for(i=0; i<NUMBER_OF_NODES; i++)
   {
   if(allowed[i]<1)
     {
     if(distance[i]<min)
       {
       min=distance[i];
       }
     }
   }
for(i=0; i<NUMBER_OF_NODES; i++)
   {
   if(distance[i]==min)
     {
     next=i;
     allowed[i]=1;
     }
   }
return next;
}
int terminate(int* allowed,int destination){
int i;
int stop=0;
for(i=0; i<NUMBER_OF_NODES; i++)
   {
   if(allowed[destination]==1)
     {
     stop=1;
     }
   else
    {
    stop=0;
    }
   }
return stop;
}
