#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void addVertex();
void addEdge();
void removeVertex();
void removeEdge();

int main(){
  char* keyword = new char[20];
  char* input = new char[10];
  //use vectors
  bool loop = true;
  while (loop == true){
    cout << "Type in a keyword:" << endl;
    cin >> keyword;
    cin.ignore();
    if (strcmp(keyword, "ADD VERTEX") == 0){
      cout << "Vertex name:" << endl;
      addVertex();
      
    }
    else if (strcmp(keyword, "ADD EDGE") == 0){
    }
    else if (strcmp(keyword, "REMOVE VERTEX") == 0){
    }
    else if (strcmp(keyword, "REMOVE EDGE") == 0){
    }
    else if (strcmp(keyword, "SHORTEST PATH") == 0){
    }
    else if (strcmp(keyword, "QUIT") == 0){
      cout << "Have a nice day!" << endl;
      loop = false;
      return 0;
    }
    else{
      cout << "Make sure the keyword is capitalized." << endl;
    }
  }
  cout << endl;
  return 0;
}

