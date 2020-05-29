#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <iterator>
#include <string.h>
using namespace std;

struct Node{
  char* label;
  vector<Node*> connect;
  vector<int> weights;
};

int distance(Node* x, Node* y);
void addVertex(vector<Node*>* vlist);
void addEdge(vector<Node*>* vlist);
void removeVertex(vector<Node*>* vlist);
void removeEdge(vector<Node*>* vlist);
void printTable(vector<Node*> vlist);
int main(){
  vector<Node*> vlist;
  char* keyword = new char[20];
  //use vectors
  bool loop = true;
  while (loop == true){
    cout << "Type in a keyword (\"AV\", \"AE\", \"RV\", \"RE\", \"SP\"or \"PRINT\"):" << endl;
    cin >> keyword;
    cin.ignore();
    if (strcmp(keyword, "AV") == 0){
      addVertex(&vlist);
      cout << vlist.size() << endl;
    }
    else if (strcmp(keyword, "AE") == 0){
      addEdge(&vlist);
    }
    else if (strcmp(keyword, "RV") == 0){
      removeVertex(&vlist);
      /*char* input = new char[20];
      Node* temp = NULL;
      cout << "Vertex Label: " << endl;
      cin.getline(input, 50);
      vector<Node*> :: iterator it;
      for (it = vlist.begin(); it != vlist.end(); it++){
	if (strcmp((*it)->label, input) == 0){
	  temp = *(it);
	}
      }
      if (temp == NULL){
	cout << "Invalid Node!" << endl;
	continue;
      }
      vector<Node*> :: iterator ite;
      for (ite = vlist.begin(); ite != vlist.end(); ite++){
	int i = isConnected((*ite), temp);
	if (i != -1){//disconnect
	  (*ite)->connect.erase((*ite)->connect.begin() + i);
	  (*ite)->weights.erase((*ite)->weights.begin() + i);
	}
      }
      for(int j = 0; j < vlist.size(); j++){
	if (vlist[j] == temp){
	  vlist.erase(vlist.begin() + j);
	  delete temp;
	}
      }
      printTable(vlist);*/
    }
    else if (strcmp(keyword, "RE") == 0){
      removeEdge(&vlist);
    }
    else if (strcmp(keyword, "PRINT") == 0){
      printTable(vlist);
    }
    else if (strcmp(keyword, "SP") == 0){
    }
    else if (strcmp(keyword, "QUIT") == 0){
      cout << "Have a nice day!" << endl;
      loop = false;
      return 0;
    }
    else{
      cout << "Invalid keyword. All words are case sensitive."<< endl;
    }
  }
  cout << endl;
  return 0;
}

int distance(Node* x, Node* y){
  vector<Node*> :: iterator it;
  for(it = x->connect.begin(); it != x->connect.end(); it++){
     if ((*it) == y){
       return it - x->connect.begin();
     }
   }
   return -1;
}

void addVertex(vector<Node*>* vlist){
  Node* temp = new Node();
  temp->label = new char(50);
  cout << "Vertex Label:" << endl;
  cin.getline(temp->label, 50);
  vlist->push_back(temp);
  cout << vlist->size() << endl;
}

void addEdge(vector<Node*>* vlist){
  char* ione = new char(50);
  char* itwo = new char(50);
  bool yone = false;
  bool ytwo = false;
  int weight = 0;
  Node* one = NULL;
  Node* two = NULL;
  if (vlist->size() < 2 ){
    cout << "Not Enough Nodes!" << endl;
    return;
  }
  vector<Node*> :: iterator it;
  cout << "Vertex 1: " << endl;
  cin.getline(ione, 50);
  cout << "Vertex 2: " << endl;
  cin.getline(itwo, 50);
   for(it = vlist->begin(); it != vlist->end(); it++){
     if (strcmp((*it)->label, ione) == 0){
       cout << (*it)->label<<endl;
       one = (*it);
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
     return;
   }
   cout << "Invalid Vertices!" << endl;
}

void removeVertex(vector<Node*>* vlist){
  char* input = new char[20];
  Node* temp = NULL;
  cout << "Vertex Label: " << endl;
  cin.getline(input, 50);
  vector<Node*> :: iterator it;
  for (it = vlist->begin(); it != vlist->end(); it++){
    if (strcmp((*it)->label, input) == 0){
      temp = *(it);
    }
  }
  if (temp == NULL){
    cout << "Invalid Node!" << endl;
    return;
  }
  vector<Node*> :: iterator ite;
  for (ite = vlist->begin(); ite != vlist->end(); ite++){
    int i = distance((*ite), temp);
    if (i != -1){//disconnect
      (*ite)->connect.erase((*ite)->connect.begin() + i);
      (*ite)->weights.erase((*ite)->weights.begin() + i);
    }
  }
  vector<Node*> :: iterator iter;
  for(iter = vlist->begin(); iter != vlist->end(); iter++){
    if (temp == (*iter)){
      vlist->erase(iter);
      iter--;
      delete temp;
    }
  }
}

void removeEdge(vector<Node*>* vlist){
  char* ione = new char(50);
  char* itwo = new char(50);
  Node* one = NULL;
  Node* two = NULL;
  bool yone = false;
  bool ytwo = false;
  int i = 0;
  vector<Node*> :: iterator it;
  cout << "Vertex 1: " << endl;
  cin.getline(ione, 50);
  cout << "Vertex 2: " << endl;
  cin.getline(itwo, 50);
  for(it = vlist->begin(); it != vlist->end(); it++){
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
    i = distance(one, two);
    if (i != -1){
      one->connect.erase(one->connect.begin() + i);
      one->weights.erase(one->weights.begin() + i);
      return;
    }
  }
  cout << "Invalid Vertices!" << endl;
}

void printTable(vector<Node*> vlist){
  vector<Node*> :: iterator it;
  vector<Node*> :: iterator i;
  vector<Node*> :: iterator j;
  cout << "Adjacency Table:" << endl << endl;
  cout << "\t";
  for (it = vlist.begin(); it != vlist.end(); it++){
    cout << (*it)->label;
    cout << "\t";
  }
  cout << endl;
  for (i = vlist.begin(); i!= vlist.end(); i++){
    cout << (*i)->label;
    cout << "\t";
    for (j = vlist.begin(); j != vlist.end(); j++){
      if (distance((*i), (*j)) != -1) {
	cout << (*i)->weights[distance((*i),(*j))];
	cout << "\t";
      }
      else{
	cout << "*";
	cout << "\t";
      }
    }
    cout << endl;
  }
}
     
