#ifndef EDGE_H
#define EDGE_H
#include <iostream>
#include "Node.h"
using namespace std;

class Edge{
 public:
  Edge(Node* newfirst, Node* newlast, int newweight);
  Node* getFirst();
  Node* getLast();
  int getWeight();
  void setFirst(Node* newfirst);
  void setLast(Node* newlast);
  void setWeight(int newweight);
  ~Edge();
 private:
  Node* first;
  Node* last;
  int weight;
};

#endif