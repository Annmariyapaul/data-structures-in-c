//GRAPH TRAVERSALS
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void enqueue(int item);
int dequeue();
void bfs(int sv);
void push(int item);
int pop();
void dfs(int sv);
void setupGraph();

int q[MAX],a[MAX],nv,am[MAX][MAX],visited[MAX];
int f=-1;
int r=-1;
int top=-1;


void main()
{
int choice,sv;
setupGraph();

do
{
printf("\n\nGRAPH TRAVERSALS:\n");
printf("Menu\n");
printf("1.BFS\n");
printf("2.DFS\n");
printf("3.Exit.\n");
printf("Enter your choice: ");
scanf("%d",&choice);

switch(choice)
{
case 1:
{
printf("Enter the starting vertex for BFS(0 to %d): ",nv-1);
scanf("%d",&sv);
if(sv<0 || sv>=nv)
printf("\nInvalid starting index");
else
bfs(sv);

break;
}

case 2:
{
int i;
for(i=0;i<nv;i++)
{
visited[i]=0;
}
printf("Enter the starting vertex for DFS(0 to %d): ",nv-1);
scanf("%d",&sv);
if(sv<0 || sv>=nv)
printf("\nInvalid starting index");
else
{
printf("DFS Traversal: ");
dfs(sv);
printf("\n");
}
break;
}

case 3:
{
printf("\nEXIT.\n");
break;
}

default:
{
printf("\nWRONG CHOICE!!!\n");
break;
}
}
}while(choice!=3);
}

void enqueue(int item)
{
if(r==MAX-1)
{
printf("Queue Overflow\n");
return;
}

if(f==-1)
f=r=0;

else
{
r++;
}
q[r]=item;
}

int dequeue()
{
if(f==-1)
{
printf("Queue is empty\n");
return -1;
}

int item=q[f];

if(f==r)
f=r=-1;

else
{
f++;
}
return item;
}

void bfs(int sv)
{
int i;
for(i=0;i<nv;i++)
{
visited[i]=0;
}

visited[sv]=1;
enqueue(sv);
printf("BFS TRAVERSAL:\n");
while(f!=-1)
{
int cv=dequeue();
printf("v%d ",cv);
for(i=0;i<nv;i++)
{
if(am[cv][i]==1 && visited[i]==0)
{
visited[i]=1;
enqueue(i);
}}}
printf("\n");
}

void push(int item)
{
if(top==MAX-1)
printf("Stack is full\n");
else
{
a[++top]=item;
}}

int pop()
{
if(top==-1)
{
printf("Stack is empty\n");
return -1;
}

else
return a[top--];
}

void dfs(int sv)
{
int i;
push(sv);
printf("DFS TRAVERSAL:\n");
while(top!=-1)
{
int cv=pop();
if(visited[cv]==0)
{
visited[cv]=1;
printf("v%d ",cv);
}
for(i=0;i<nv;i++)
{
if(am[cv][i]==1 && visited[i]==0)
{
push(i);
}}}
printf("\n");
}

void setupGraph()
{
int e;
int i,j;
printf("Enter the number of vertices: ");
scanf("%d",&nv);

if(nv<=0 || nv>MAX)
{
printf("Invalid NUmber of vertices");
}

for(i=0;i<nv;i++)
{
visited[i]=0;
for(j=0;j<nv;j++)
{
am[i][j]=0;
}}

for(i=0;i<nv;i++)
{
for(j=0;j<nv;j++)
{
if(i!=j)
{
printf("Do you want to create an edge between v%d and v%d: ",i,j);
scanf("%d",&e);
if(e==1)
{
am[i][j]=1;
}}}}
printf("Adjacency Matrix:\n");
for(i=0;i<nv;i++)
{
for(j=0;j<nv;j++)
{
printf("%d ",am[i][j]);
}
printf("\n");
}}

/*
OUTPUT:
Enter the number of vertices: 5
Do you want to create an edge between v0 and v1: 1
Do you want to create an edge between v0 and v2: 1
Do you want to create an edge between v0 and v3: 1
Do you want to create an edge between v0 and v4: 0
Do you want to create an edge between v1 and v0: 1
Do you want to create an edge between v1 and v2: 1
Do you want to create an edge between v1 and v3: 0
Do you want to create an edge between v1 and v4: 0
Do you want to create an edge between v2 and v0: 1
Do you want to create an edge between v2 and v1: 1
Do you want to create an edge between v2 and v3: 1
Do you want to create an edge between v2 and v4: 1
Do you want to create an edge between v3 and v0: 1
Do you want to create an edge between v3 and v1: 0
Do you want to create an edge between v3 and v2: 1
Do you want to create an edge between v3 and v4: 0
Do you want to create an edge between v4 and v0: 0
Do you want to create an edge between v4 and v1: 0
Do you want to create an edge between v4 and v2: 1
Do you want to create an edge between v4 and v3: 0
Adjacency Matrix:
0 1 1 1 0
1 0 1 0 0
1 1 0 1 1
1 0 1 0 0
0 0 1 0 0


GRAPH TRAVERSALS:
Menu
1.BFS
2.DFS
3.Exit.
Enter your choice: 1
Enter the starting vertex for BFS(0 to 4): 0
BFS TRAVERSAL:
v0 v1 v2 v3 v4


GRAPH TRAVERSALS:
Menu
1.BFS
2.DFS
3.Exit.
Enter your choice: 2
Enter the starting vertex for DFS(0 to 4): 0
DFS Traversal: DFS TRAVERSAL:
v0 v3 v2 v4 v1



GRAPH TRAVERSALS:
Menu
1.BFS
2.DFS
3.Exit.
Enter your choice: 3

EXIT.
*/