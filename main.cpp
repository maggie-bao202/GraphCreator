//#include "Node.h"
//#include "Edge.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

struct Node{
  char* label;
  vector<Node*> connect;
};

struct Edge{
  Node* one;
  Node* two;
  Node* weight;
};

void addVertex(vector<Node*> vlist){
  Node* temp = new Node();
  temp->label = new char(50);
  cout << "Vertex Label:" << endl;
  cin.getline(temp->label, 50);
  vlist.push_back(temp);
}

bool addEdge(vector<Edge*> elist, vector<Node*> vlist){
  char* ione = new char(50);
  char* itwo = new char(50);
  bool yone = false;
  bool ytwo = false;
  vector<Node*> :: iterator it;
  cout << "Vertex 1: " << endl;
  cin.getline(ione, 50);
  cout << "Vertex 2: " << endl;
  cin.getline(itwo, 50);
   for(it = vlist.begin(); it != vlist.end(); it++){
     if (strcmp((*it)->label, ione) == 0){
       Node* one = *(it);
       yone = true;
     }
     if (strcmp((*it)->label, itwo) == 0){
       Node* two = *(it);
       ytwo = true;
     }
   }
   if (yone = true && ytwo = true){
     return true;
   }
   return false;
}
void removeVertex();
void removeEdge();

int main(){
  vector<Node*> vlist;
  vector<Edge*> elist;
  char* keyword = new char[20];
  char* input = new char[10];
  //use vectors
  bool loop = true;
  bool truefalse = false;
  while (loop == true){
    cout << "Type in a keyword:" << endl;
    cin >> keyword;
    cin.ignore();
    if (strcmp(keyword, "ADD VERTEX") == 0){
      addVertex(vlist);
    }
    else if (strcmp(keyword, "ADD EDGE") == 0){
      do{
	truefalse = addEdge(elist);
      } while (truefalse == true);
      cout << "Edge Weight: " << endl;
      int weight = 0;
      cin >> weight;
      cin.ignore();
      one->connect.push_back(two);
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

