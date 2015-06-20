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
#include <map>      // adjMatrix
#include <list>
#include <vector>   // freevector
#include <queue>    // priority_queue runq, stage q


#include "PFD.h"

using namespace std;
 


Graph::Graph(){
  cout << "Initiated graph" <<endl;
 }

 Graph::Graph(istream& r){
    r >> tasks >> rules;
    ++tasks;
    
    freevector= vector<bool>(tasks, false);
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
          if (values!=0){
            freevector[key]=true;
          }
    }
    return true;
}

// ------------
// PFD_eval
// ------------

int Graph::PFD_eval () {
    //Set i as lower bound and j as uppper
    //initializing the runq
    for (int c=1; c<tasks; c++)
            if (!freevector[c])
                runq.push(c);
    while (!runq.empty() && !stageq.empty()){
       while(!runq.empty()){
            int cur = runq.top();
            runq.pop();
            for (int i=0; i<tasks; i++){
                if (adjMatrix [i][cur]){
                    adjMatrix[i][cur]=false;
                    stageq.push(i);
                }
            }
        }
        PFD_print (cout);
        while (!stageq.empty()){
            int cur =stageq.top();
            stageq.pop();
            bool ready=true;
            for (int i=0; i<tasks; i++){
                if (adjMatrix [cur][i]){
                    ready=false;
                    break;
                }
            }
            if (ready)
                runq.push(cur);
        }

    }
return 1;}



// -------------
// PFD_print
// -------------

void Graph::PFD_print (ostream& w) {
	cout << " PFD_print " << endl;
    assert (tasks > 0);
    assert (rules > 0);
    int idx = 0;
    
    
    for (int c=0; c<tasks; c++){
        cout << freevector[c] << " ";
    }
    cout << endl;
    
    

    cout << "  " ;
    for(int i =0; i< tasks;i++){
    	cout <<  i << " ";
    }
    cout << endl;

    for(vector<vector<bool>>::iterator i = adjMatrix.begin(); i!=adjMatrix.end(); i++){
        w << idx ++;

       for(vector<bool>::iterator j = i->begin(); j!= i->end(); j++){
          w << " " << *j;}
       cout << endl;
   }
   
    cout << " runq: ";
    for(vector<int>::iterator i = runq.begin() ; i != runq.end(); i++){
    w<< " " << *i;
    }
    w<< endl;

    cout << " stageq: " << stageq.top() << " " 



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
