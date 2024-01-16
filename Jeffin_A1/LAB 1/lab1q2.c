#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int data;
	node* next;
	node* nextvertex;
}node;




typedef struct graph
{
	int nodes;
	node* adj_list;
	int ** adj_matrix;
}graph;


node* search(node* head,int x)
{
	node* temp = head;
	while(temp)
	{
		if(temp->data == x)
			return temp;
	}
	
	return temp;
}


addvertex()







node* create(node* list ,int from , int to)
{
	if(search(from))
	{

	}
	else
	{

	}

}
void main()
{	
	graph* g = (graph*)malloc(sizeof(graph));
	
	g->adj_list= create


}
