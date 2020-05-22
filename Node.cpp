#include <iostream>
#include "Node.h"

using namespace std;

Node :: Node(char* newlabel){
  label = newlabel;
}

char* Node :: getLabel(){
  return label;
}

void Node :: setLabel(char* newlabel){
  label = newlabel;
}

Node :: ~Node(){
}
