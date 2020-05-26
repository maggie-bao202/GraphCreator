#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

struct Node{
  char* label;
  vector<Node*> connect;
  vector<int> weights;
};

void addVertex(vector<Node*> vlist){
  Node* temp = new Node();
  temp->label = new char(50);
  cout << "Vertex Label:" << endl;
  cin.getline(temp->label, 50);
  vlist.push_back(temp);
}

bool addEdge(vector<Node*> vlist){
  char* ione = new char(50);
  char* itwo = new char(50);
  bool yone = false;
  bool ytwo = false;
  int weight = 0;
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
     cout << "Edge Weight: " << endl;
     cin >> weight;
     cin.ignore();
     one->connect.push_back(two);
     one->weights.push_back(weight);
     return true;
   }
   cout << "Invalid Nodes!" << endl;
   return false;
}
void removeVertex(vector<Node*> vlist){
  char* input = new char(50);
  bool found = false;
  vector<Node*> :: iterator it;
  cout << "Vertex Label: " << endl;
  cin.getline(input, 50);
  do{
  for(it = vlist.begin(); it != vlist.end(); it++){
    if (((*it)->label, input) == 0) {
      Node* temp = *(it);
      found = true;
    }
  }
  } while (found == false);
  for(it = vlist.begin(); it != vlist.end(); it++){
    if ((*it)->connect == find) {
    }
  }
}
  
    

void removeEdge(vector<Node*> vlist){
  char* ione = new char(50);
  char* itwo = new char(50);
  bool yone = false;
  bool ytwo = false;
  int weight = 0;
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
    one->connect.erase(one->connect.begin() + index);
    one->weights.erase(one->weights.begin() + index);



int main(){
  vector<Node*> vlist;
  char* keyword = new char[20];
  //use vectors
  bool loop = true;
  bool found = false;
  while (loop == true){
    cout << "Type in a keyword:" << endl;
    cin >> keyword;
    cin.ignore();
    if (strcmp(keyword, "ADD VERTEX") == 0){
      addVertex(vlist);
    }
    else if (strcmp(keyword, "ADD EDGE") == 0){
      do{
	found = addEdge(vlist);
      } while (found == false);
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

