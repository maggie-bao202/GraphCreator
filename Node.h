#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
 public:
  Node(char* newlabel);
  char* getLabel();
  void setLabel(char* newlabel);
  ~Node();
 private:
  char* label;
};


#endif
