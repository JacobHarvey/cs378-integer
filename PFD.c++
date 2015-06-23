/** \file PFD.c++
 *   Main PFD file containing.
 *  Without the worlds end.
 */


/*! \mainpage CS371P PFD
 *
 * \section intro_sec Introduction
 *
 *
 * "Background:
 * Project managers, such as the UNIX utility make, are used to maintain large software projects made up from many components. Users write a project file specifying which components (called tasks) depend on others and the project manager can automatically update the components in the correct order. ."
 * http://www.spoj.com/problems/PROBTNPO/
 * \section time_est Time
 * Estimate: 8 hours
 * Actual: 10 hours
 *
 * \section install_sec The Problem
 *  Write a program that reads a project file and outputs the order in which the tasks should be performed
 *  Input
 *  For simplicity we represent each task by an integer number from <b>1,2,...,N</b> (where \b N is the total number of tasks). The first line of input specifies the number \b N of tasks and the number \bM of rules, such that \bN leq 100,; Mleq 100.
 *  The rest of the input consists of \bM rules, one in each line, specifying dependencies using the following syntax:
 *  <b> T_0    k    T_1    T_2    ...    T_k</b>
 *  This rule means that task number \bT_0 depends on \bk tasks <b>T_1, T_2, ... T_k</b> (we say that task \bT_0 is the target and <b>T_1 ... T_k<\b> are dependents).
 *  Note that tasks numbers are separated by single spaces and that rules end with a newline. Rules can appear in any order, but each task can appear as target only once.
 *  Your program can assume that there are no circular dependencies in the rules, i.e. no task depends directly or indirectly on itself.
 *  Output
 *  The output should be a single line with the permutation of the tasks \b1ldots N\b to be performed, ordered by dependencies (i.e. no task should appear before others that it depends on).
 *  To avoid ambiguity in the output, tasks that do not depend on each other should be ordered by their number (lower numbers first).
 *
 */


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
	// Shouldn't be used.
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
	if(tasks == 0 || rules == 0 ) return false;

    // Run through the free array and push all tasks with no dependencies
    for (int c=1; c<tasks; c++)
    {
        if (!freevector[c]){       
            runq.push(c);
        }else{
            freevector[c]=false;
        }

   }

    // Now we loop through the Run priority_queue until it becomes empty
    // Once it turns empty we are done and all tasks have been exhausted.

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
            // Stage Q is a intermediatery queue where all items are placed
            // here we check whether they are ready and have no dependents.
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
// loops through the results queue and shoves the characters into the output stream
//
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
// Creates the main Graph class, reads the data, and processes.
void PFD_solve (istream& r, ostream& w) {
	bool success;
        Graph a(r);
        a.PFD_read(r);
        success = a.PFD_eval();
        if( success )
        		a.PFD_print(w);
}
