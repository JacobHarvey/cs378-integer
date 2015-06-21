
// -------------------------------
// projects/PFD/RunPFD.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------------------------
// projects/PFD/PFD.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

// --------
// includes
// --------


#include <cassert>  // assert
#include <sstream>  // istringstream
#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include "map"
#include "list"
#include "queue"
#include "stack"

using namespace std;

struct Graph{
int tasks;
int rules;


vector<vector<bool> > adjMatrix;
queue<int> results;
priority_queue <int, vector<int>, greater<int> > runq;
priority_queue <int, vector<int>, greater<int> > stageq;
vector<bool> freevector;

public:

Graph();
Graph(istream& r);

// ------------
// PFD_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
void PFD_read (istream& r);

// ------------
// PFD_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
bool PFD_eval ();

// -------------
// PFD_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void PFD_print (ostream& w);

};

// -------------
// PFD_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void PFD_solve (istream& r, ostream& w);

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

int main () {
    using namespace std;
    PFD_solve(cin, cout);
    return 0;}
