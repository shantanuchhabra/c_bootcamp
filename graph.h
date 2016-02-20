#include <stdbool.h>
#include <inttypes.h>

#ifndef _GRAPH_H
#define _GRAPH_H

typedef unsigned int vertex;
typedef struct graph_header* graph;
typedef struct adjlist_node adjlist;

struct adjlist_node {
  vertex vert;
  adjlist *next;
};

graph graph_new(unsigned int numvert); // New graph with numvert vertices
void graph_free(graph G);
unsigned int graph_size(graph G); // Number of vertices in the graph

bool graph_hasedge(graph G, vertex v, vertex w);
  //@requires v < graph_size(G) && w < graph_size(G);
void graph_addedge(graph G, vertex v, vertex w); // Edge can't be in graph!
  //@requires v < graph_size(G) && w < graph_size(G);
  //@requires !graph_hasedge(G, v, w);

/* Returns a linked list of the neighbors of vertex v. This adjacency
   list is owned by the graph and should not be modified by the
   user. */
adjlist *graph_connections(graph G, vertex v);
  //@requires v < graph_size(G);

#endif

