#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int value;
   int nr_edges;
   node_t **edges;
} node_t;

int find_way(node_t nodes[8], int start, int end, int i) {
   if (nodes[i].value == end) {
      return 1;
   }


}

int main(int argc, char const *argv[]) {
   
   node_t nodes[8];

   nodes[0].value = 5;
   nodes[0].nr_edges = 1;
   nodes[0].edges[0] = nodes[3];

   nodes[1].value = 7;
   nodes[1].nr_edges = 2;
   nodes[1].edges[0] = nodes[3];
   nodes[1].edges[1] = nodes[4];

   nodes[2].value = 3;
   nodes[2].nr_edges = 2;
   nodes[2].edges[0] = nodes[4];
   nodes[2].edges[1] = nodes[7];

   nodes[3].value = 11;
   nodes[3].nr_edges = 3;
   nodes[3].edges[0] = nodes[5];
   nodes[3].edges[1] = nodes[6];
   nodes[3].edges[2] = nodes[7];

   nodes[4].value = 8;
   nodes[4].nr_edges = 0;
   nodes[4].edges = NULL;

   nodes[5].value = 2;
   nodes[5].nr_edges = 0;
   nodes[5].edges = NULL;

   nodes[6].value = 9;
   nodes[6].nr_edges = 0;
   nodes[6].edges = NULL;

   nodes[7].value = 10;
   nodes[7].nr_edges = 0;
   nodes[7].edges = NULL;



   return 0;
}