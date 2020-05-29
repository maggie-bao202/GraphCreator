#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;
/*5/28/2020 Author: Maggie Bao Description: A graph is a data structure which consists of vertices, connected by edges. The program prompts the user to add and remove vertexes and edges. Additionally, the program can print out an adjacency matrix/table, which displays which vertices are connected.*/

struct Node{ //Vertex structure--unrelated to a node within linked lists
  char* label; //label of vertex
  vector<Node*> connect; //list of vertices the vertex is connected to(edge is present)
  vector<int> weightlist; //list of weights corresponding to edges
};
/*
struct Queue{
  int length;
  int index;
};*/

int distance(Node* x, Node* y);
void addVertex(vector<Node*>* vlist);
void addEdge(vector<Node*>* vlist);
void removeVertex(vector<Node*>* vlist);
void removeEdge(vector<Node*>* vlist);
void printTable(vector<Node*> vlist);
void dijkstra(vector<Node*> vlist, Node* start, Node* stop);

int main(){
  vector<Node*> vlist;
  char* keyword = new char[20];
  bool loop = true;
  while (loop == true){
    cout << "Type in a keyword; \"AV\"(add vertex), \"AE\"(add edge), \"RV\"(remove vertex), \"RE\"(remove edge), \"SP\"(shortest path), \"P\"(print), or \"Q\"(quit):" << endl;
    cin >> keyword;
    cin.ignore();
    if (strcmp(keyword, "AV") == 0){
      addVertex(&vlist);//pass by reference to manipulate actual vector
    }
    else if (strcmp(keyword, "AE") == 0){
      addEdge(&vlist);
    }
    else if (strcmp(keyword, "RV") == 0){
      removeVertex(&vlist);
    }
    else if (strcmp(keyword, "RE") == 0){
      removeEdge(&vlist);
    }
    else if (strcmp(keyword, "P") == 0){
      printTable(vlist);//pass by value
    }
    else if (strcmp(keyword, "SP") == 0){
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
       for(it = vlist.begin(); it != vlist.end(); it++){//check if both vertices exist
	 if (strcmp((*it)->label, ione) == 0){
	   one = *(it);
	   yone = true;
	 }
	 if (strcmp((*it)->label, itwo) == 0){
	   two = *(it);
	   ytwo = true;
	 }
       }
       if (yone == true && ytwo == true){//if both exist, shortest path
	 dijkstra(vlist, one, two);
       }
       else{
	 cout << "Invalid Vertices!" << endl;
       }
	 
    }
    else if (strcmp(keyword, "Q") == 0){
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

int distance(Node* x, Node* y){//returns the distance from current vertex to the first element of vertex--speifically used for edges, connected list
  vector<Node*> :: iterator it;
  for(it = x->connect.begin(); it != x->connect.end(); it++){
    if ((*it) == y){//if the node is within list of connected vertices
      return it - x->connect.begin();//return the distance
     }
   }
  return -1;//else return negative value
}

void addVertex(vector<Node*>* vlist){//take in user input and adds vertex to vertexlist
  Node* temp = new Node();
  char* input = new char(50);
  cout << "Vertex Label:" << endl;
  cin.getline(input, 50, '\n');
  temp->label = input;//store input in temp->label, then push temp into vertexlist
  vlist->push_back(temp);
}

void addEdge(vector<Node*>* vlist){//takes two existing vertices and assigns edge weight between them, then connects them.
  char* ione = new char(50);
  char* itwo = new char(50);
  bool yone = false;
  bool ytwo = false;
  int weight = 0;
  Node* one = NULL;
  Node* two = NULL;
  
  if (vlist->size() < 2 ){//if less than two exising vertices, return
    cout << "Not Enough Nodes!" << endl;
    return;
  }
  vector<Node*> :: iterator it;
  cout << "Vertex 1: " << endl;
  cin.getline(ione, 50);
  cout << "Vertex 2: " << endl;
  cin.getline(itwo, 50);
  for(it = vlist->begin(); it != vlist->end(); it++){//searches vertexlist to see if the two vertices exists
     if (strcmp((*it)->label, ione) == 0){
       one = (*it);
       yone = true;
     }
     if (strcmp((*it)->label, itwo) == 0){
       two = *(it);
       ytwo = true;
     }
   }
  if (yone == true && ytwo == true){//if both exist, assign weight
     cout << "Edge Weight: " << endl;
     cin >> weight;
     cin.ignore();
     one->connect.push_back(two);//vertex 2 is connected to vertex 1 in vertex 1's connected vertices list
     one->weightlist.push_back(weight);//store the weight in a list as well
     return;
   }
   cout << "Invalid Vertices!" << endl;
}

void removeVertex(vector<Node*>* vlist){//removes corresponding vertex in vertex list from input, as well as edges present in connect lists
  char* input = new char[20];
  Node* temp = NULL;
  int d = 0;
  cout << "Vertex Label: " << endl;
  cin.getline(input, 50);
  vector<Node*> :: iterator it;
  for (it = vlist->begin(); it != vlist->end(); it++){//find the vertex to be deleted
    if (strcmp((*it)->label, input) == 0){
      temp = *(it);//store address in temp
    }
  }
  if (temp == NULL){//if vertex is not found, return
    cout << "Invalid Node!" << endl;
    return;
  }
  vector<Node*> :: iterator ite;
  for (ite = vlist->begin(); ite != vlist->end(); ite++){//go through vlist
    d = distance((*ite), temp);//if temp is present within element, function will not return -1
    if (d != -1){//if connected, disconnect
      (*ite)->connect.erase((*ite)->connect.begin() + d);//both connect and weightlist should have the same distance because of how they are added in
      (*ite)->weightlist.erase((*ite)->weightlist.begin() + d);
    }
  }
  vector<Node*> :: iterator iter;
  for(iter = vlist->begin(); iter != vlist->end(); iter++){
    if (temp == (*iter)){//go to vertex in vlist
      vlist->erase(iter);//clear memory
      iter--;//fixes seg fault--erasing element causes to skip an interation, since size is tempered
      delete temp;//delete pointer
    }
  }
}

void removeEdge(vector<Node*>* vlist){//removes the vertex from any connection lists and weightlists
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
  cin.getline(itwo, 50);//get the two vertices that edge is between
  for(it = vlist->begin(); it != vlist->end(); it++){//check if both vertices exist
    if (strcmp((*it)->label, ione) == 0){
      one = *(it);
      yone = true;
    }
    if (strcmp((*it)->label, itwo) == 0){
      two = *(it);
      ytwo = true;
    }
  }
  if (yone == true && ytwo == true){//if both exist
    i = distance(one, two);//find distance of second vertex from first element--if they are not connected will return -1
    if (i != -1){//if connected
      one->connect.erase(one->connect.begin() + i);//erase the vertex in connectedlist and weightlist
      one->weightlist.erase(one->weightlist.begin() + i);
      return;
    }
  }//if vertices don't exist or if vertices are not adjacent
  cout << "Invalid Vertices!" << endl;
}

void printTable(vector<Node*> vlist){
  vector<Node*> :: iterator it;
  vector<Node*> :: iterator i;
  vector<Node*> :: iterator j;
  int d = 0 ;
  cout << "Adjacency Table:" << endl << endl;
  cout << "\t";
  for (it = vlist.begin(); it != vlist.end(); it++){//first row, label headers
    cout << (*it)->label;
    cout << "\t";
  }
  cout << endl;
  for (i = vlist.begin(); i!= vlist.end(); i++){//iterate through vertex list
    cout << (*i)->label;//print label, then
    cout << "\t";
    for (j = vlist.begin(); j != vlist.end(); j++){//check for connection/weight between each combination of labels
      d = distance((*i),(*j));//check for connection/distance of weight
      if (d != -1) {//if connected
	cout << (*i)->weightlist[d];//print the weight of the connected vertices
	cout << "\t";
      }
      else{///if no weight, print stars
	cout << "*";
	cout << "\t";
      }
    }
    cout << endl;
  }
}

void dijkstra(vector<Node*> vlist, Node* start, Node* stop){//Dijkstra's algorithm, shortest path from one node to every other node in graph
  cout << "nothing..." << endl;
/*stop node is needed for optimization. Weights must be positive.
initialize integer array "distance" the number of vertices and all elements set to infinity
structure priority queue: index, distance
start at first node-- index = 0, distance = 0. in queue: (0,0), in distance array: 0
iterate through first node's connectedlist, and pick the lowest edge value to go to the next node. insert weight+previous value information into priority queue and distance array, go to the next optimal node. 
check next node's connected vertices list. compare the distance and update as needed.
if best route was already found, skip 
Source: https://www.youtube.com/watch?v=pSqmAO-m7Lk
*/
}
