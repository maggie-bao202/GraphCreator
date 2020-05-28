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

int isConnected(Node* from, Node* find){
   vector<Node*> :: iterator it;
   int count = 0;
   for(it = from->connect.begin(); it != from->connect.end(); it++){
     if ((*it) == find){
       return count;
     }
     count++;
   }
   return -1;
}


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
  Node* one = NULL;
  Node* two = NULL;
  vector<Node*> :: iterator it;
  cout << "Vertex 1: " << endl;
  cin.getline(ione, 50);
  cout << "Vertex 2: " << endl;
  cin.getline(itwo, 50);
   for(it = vlist.begin(); it != vlist.end(); it++){
     if (strcmp((*it)->label, ione) == 0){
       one = *(it);
       yone = true;
     }
     if (strcmp((*it)->label, itwo) == 0){
       two = *(it);
       ytwo = true;
     }
   }
   if (yone == true && ytwo == true){
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
  int i = 0;
  Node* temp = NULL;
  vector<Node*> :: iterator it;
  cout << "Vertex Label: " << endl;
  cin.getline(input, 50);
  do{
  for(it = vlist.begin(); it != vlist.end(); it++){
    if (((*it)->label, input) == 0) {
      temp = *(it);
      found = true;
    }
  }
  } while (found == false);
  for(it = vlist.begin(); it != vlist.end(); it++){
    i = isConnected((*it), temp);
    if (i != -1){
      (*it)->connect.erase((*it)->connect.begin() + i);
      (*it)->weights.erase((*it)->weights.begin() + i);
    }
  }
  for(it = vlist.begin(); it != vlist.end(); it++){
    if ((*it) == temp){
      vlist.erase(it);
      delete temp;
    }
  }
}

void removeEdge(vector<Node*> vlist){
  char* ione = new char(50);
  char* itwo = new char(50);
  bool yone = false;
  bool ytwo = false;
  Node* one = NULL;
  Node* two = NULL;
  int i = 0;
  vector<Node*> :: iterator it;
  cout << "Vertex 1: " << endl;
  cin.getline(ione, 50);
  cout << "Vertex 2: " << endl;
  cin.getline(itwo, 50);
  for(it = vlist.begin(); it != vlist.end(); it++){
     if (strcmp((*it)->label, ione) == 0){
       one = *(it);
       yone = true;
     }
     if (strcmp((*it)->label, itwo) == 0){
       two = *(it);
       ytwo = true;
     }
  }
  if (yone == true && ytwo == true){
    i = isConnected(one, two);
    if (i != -1){
      one->connect.erase(one->connect.begin() + i);
      one->weights.erase(one->weights.begin() + i);
      return;
    }
    cout << "Nodes Not Connected" << endl;
  }
}


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

