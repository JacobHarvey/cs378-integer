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
bool Graph::PFD_read (istream& r) {
	// cout << " PFD_read " << endl;

    string s;
    int key;
    int task;
    int values=0;
    //WHY IS IT <= RULES???
    for(int i=0; i<= rules; i++){
          getline(r,s);
          istringstream sin(s);
          sin >> key;
          sin >> values;
          int iter = 0;
          while(sin >> task && iter < values){
//        	  cout << "  < " << key << " " << values  << " " << task << endl;
        	  adjMatrix[key][task]=true;
              ++iter;
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

    /* cout << "printing freevector ";
     for (int c=1; c<tasks; c++){
         cout << freevector[c] << " ";
     }
     cout << endl;
    */
    //freevector has 0 in it, but should be ignored since tasks start at number 1, need <=, tasks=100, we need to run vector[100]
    //if freevector[c]==false, it has no dependencies
    for (int c=1; c<tasks; c++)
    {
        if (!freevector[c]){       
    //        cout << c << " ";
            runq.push(c);
        }else{
            freevector[c]=false;
        }
    //    cout << endl;

   }

    // if(!runq.empty())
    // cout << " runq: " << runq.top() << " " << runq.size() << endl;

    // PFD_print (cout);    

    // cout << "  -------------------START -------  " << endl;

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
 //if(!stageq.empty())
    // cout << " stageq: "<< stageq.top() << " " << stageq.size() << endl;       
/*
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
            if (ready && freevector[cur]==false){
                freevector[cur]=true;
                runq.push(cur);
            }
        }
*/    
    // if(!runq.empty())
    // cout << " runq: " << runq.top() << " " << runq.size() << endl;

    //    PFD_print (cout);
    // cout << " ----------------------- END ------- " << endl;

    }

    while(!results.empty()){
        cout << results.front();
        results.pop();
        if(!results.empty())
            cout << " ";     
    }


    cout<< endl;
return 1;}



// -------------
// PFD_print
// -------------

void Graph::PFD_print (ostream& w) {
	// cout << " PFD_print " << endl;
    assert (tasks > 0);
    assert (rules > 0);
    int idx = 0; 
    

    cout << "  " ;
    for(int i =0; i< tasks;i++){
    	cout <<  i << " ";
    }
    cout << endl;

    for(vector < vector < bool > >::iterator i = adjMatrix.begin(); i!=adjMatrix.end(); i++){
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
	// cout << " PFD_solve " << endl;
        Graph a(r);
        a.PFD_read(r);
        a.PFD_eval();
        // a.PFD_print(w);
}
