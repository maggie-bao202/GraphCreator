#include <iostream>
#include "Edge.h"
#include "Node.h"
using namespace std;

Edge :: Edge(Node* newfirst, Node* newlast, int newweight){
  first = newfirst;
  last = newlast;
  weight = newweight;
}

Node* Edge :: getFirst(){
  return first;
}

Node* Edge :: getLast(){
  return last;
}

int Edge :: getWeight(){
  return weight;
}

void Edge :: setFirst(Node* newfirst){
  first = newfirst;
}

void Edge :: setLast(Node* newlast){
  last = newlast;
}

void Edge :: setWeight(int newweight){
  weight = newweight;
}

Edge :: ~Edge(){
}
