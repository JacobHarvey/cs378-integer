// ----------------------------
// projects/PFD/PFD.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <map>
#include <list>


#include "PFD.h"

using namespace std;

int CACHESIZE = 100000;
#define CACHE true
#ifdef CACHE
int cache [100000];
#endif

 


Graph::Graph(){
  cout << "Initiated graph" <<endl;
 }

 Graph::Graph(istream& r){
    r >> tasks >> rules;
    adjMatrix = vector<vector<bool>>(tasks,vector<bool>(tasks,0));
 }

// ------------
// PFD_read
// ------------
bool Graph::PFD_read (istream& r) {
	cout << " PFD_read " << endl;

    string s;
    int key;
    int task;
    int values=0;
    for(int i=0; i< rules; i++){
          getline(r,s);
          istringstream sin(s);
          sin >> key;
          sin >> values;
          while(sin >> task){
//        	  cout << "  < " << key << " " << values  << " " << task << endl;
        	  adjMatrix[key][task]=true;
          }
    }
    return true;
}

// ------------
// PFD_eval
// ------------

int Graph::PFD_eval () {
    //Set i as lower bound and j as uppper
return 1;}



// -------------
// PFD_print
// -------------

void Graph::PFD_print (ostream& w) {
	cout << " PFD_print " << endl;
    assert (tasks > 0);
    assert (rules > 0);
    int idx = 0;
    string firstLine;
    firstLine += " " ;
    for(int i =0; i< tasks;i++){
    	firstLine += i;
    	firstLine += " ";
    }

    cout << firstLine <<  endl;

    for(vector<vector<bool>>::iterator i = adjMatrix.begin(); i!=adjMatrix.end(); i++){
        w << idx ++;

       for(vector<bool>::iterator j = i->begin(); j!= i->end(); j++){
          w << " " << *j;}
       cout << endl;
   }
}


// -------------
// PFD_solve
// -------------

void PFD_solve (istream& r, ostream& w) {
	cout << " PFD_solve " << endl;
        Graph a(r);
        a.PFD_read(r);
        a.PFD_eval();
        a.PFD_print(w);
}
