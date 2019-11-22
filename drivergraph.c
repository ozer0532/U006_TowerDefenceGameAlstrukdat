#include "graph.h"

int main(){
    Graph G;
    CreateEmptyGraph(&G);
    AddRelation(&G,1,2);
    AddRelation(&G,2,3);
    AddRelation(&G,2,4);
    AddRelation(&G,1,5);
    AddRelation(&G,3,2);
    AddRelation(&G,2,1);
    AddRelation(&G,4,2);
    AddRelation(&G,5,1);

}