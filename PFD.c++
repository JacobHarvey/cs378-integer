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
    //freevector should be 1 bigger?? Given 100 tasks, we want to index from vector[1]-[100],meaning we need size of 101
    freevector= vector<bool>(tasks, false);
    adjMatrix = vector < vector < bool > >(tasks,vector<bool>(tasks,0));
 }

// ------------
// PFD_read
// ------------
void Graph::PFD_read (istream& r) {

    string s;
    int key;
    int task;
    int values=0;
    for(int i=0; i<= rules; i++){
          getline(r,s);
          istringstream sin(s);
          sin >> key;
          sin >> values;
          int iter = 0;
          while(sin >> task && iter < values){
        	  adjMatrix[key][task]=true;
              ++iter;
          }
          if (values!=0){
            freevector[key]=true;
          }
    }
}

// ------------
// PFD_eval
// ------------

bool Graph::PFD_eval () {
    //Set i as lower bound and j as uppper
    //initializing the runq
    //freevector has 0 in it, but should be ignored since tasks start at number 1, need <=, tasks=100, we need to run vector[100]
    //if freevector[c]==false, it has no dependencies

    for (int c=1; c<tasks; c++)
    {
        if (!freevector[c]){       
            runq.push(c);
        }else{
            freevector[c]=false;
        }

   }

    while (!runq.empty()){
       while(!runq.empty()){
            int cur = runq.top();
            runq.pop();
            results.push(cur);
            for (int i=0; i<tasks; i++){
                if (adjMatrix [i][cur]){
                    adjMatrix[i][cur]=false;
                    stageq.push(i);
                }
            }
            while (!stageq.empty()){
                    int cur =stageq.top();
                    stageq.pop();
                    bool ready=true;
                    for (int i=0; i<tasks && freevector[cur]==false; i++){
                        if (adjMatrix [cur][i]){
                            ready=false;
                            break;
                        }
                    }
                    if (ready && freevector[cur]==false){
                        freevector[cur]=true;
                        runq.push(cur);
                    }
        
            }
       }
    }

return true;
}


// -------------
// PFD_print
// -------------

void Graph::PFD_print (ostream& w) {
    assert (tasks > 0);
    assert (rules > 0);

    while(!results.empty()){
        w << results.front();
        results.pop();
        if(!results.empty())
            w << " ";
       }
    w<<endl;
}


// -------------
// PFD_solve
// -------------

void PFD_solve (istream& r, ostream& w) {
	bool success;
        Graph a(r);
        a.PFD_read(r);
        success = a.PFD_eval();
        if( success )
        		a.PFD_print(w);
}
