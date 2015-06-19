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

 
struct Graph{
int tasks=0;
int rules=0;
map<int, list<int>> _map;

Graph(){
  cout << "Initiated graph" <<endl;
 }
 Graph(string s){
    istringstream sin(s);
    sin >> tasks >> rules; 
 }

// ------------
// PFD_read
// ------------
bool PFD_read (istream& r) {
    string s;
    int key;
    int task;
    for(int i=0; i< rules; i++){
          getline(r,s);
          istringstream sin(s);
          sin >> key;
          while(sin >> task){

            _map[key].push_back(task);
          
          }
          assert(s.length() > 0);
    }
    return true;
}

// ------------
// PFD_eval
// ------------

int PFD_eval () {
    //Set i as lower bound and j as uppper
return 1;}



// -------------
// PFD_print
// -------------

void PFD_print (ostream& w) {
    assert (tasks > 0);
    assert (rules > 0);
    for(map<int,list<int>>::iterator i = _map.begin(); i!=_map.end(); i++){
        w << i->first;
       for(list<int>::iterator j = i->second.begin(); j!=i->second.end(); j++){
          w << " " << *j;}
       cout << endl;
       }
    }
};


// -------------
// PFD_solve
// -------------

void PFD_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        Graph a(s);
        a.PFD_read(r);
        a.PFD_eval();
        a.PFD_print(w);
    }
}
