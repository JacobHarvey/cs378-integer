// --------------------------
// projects/PFD/PFD.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef PFD_h
#define PFD_h

// --------
// includes
// --------



#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include "map"
#include "list"
#include "queue"
#include "stack"

using namespace std;


struct Graph{

public:

	int tasks; //!<number of tasks
	int rules; //!<number of rules/ lines to read from the input to generate the adjMatrix


	vector<vector<bool> > adjMatrix; //!<Used to store the vertex pairs and the dependencies, size is tasksXtasks large, sets value to 1 at adjMatrix[x][c] if Task x depends on Task c. Can be used to check dependencies or successors by iterating through either rows or columns 
	queue<int> results;  //!<Stores the list of ordered output
	priority_queue <int, vector<int>, greater<int> > runq; //!<Holds the tasks that have 0 dependencies left and are good to run
	priority_queue <int, vector<int>, greater<int> > stageq; //!<Holds all of the vectors that were changed as a result of iterating through the runq vertex. These vectors may or may not have dependencies left. If no dependencies left, they will be added to the runq
	vector<bool> freevector; //!<Used to start the PFD_eval() func, sizeof(freevector)==tasks, holds whether each task has a dependency or not

Graph();
// ------------
// Graph
// ------------
/**
 * Reads in the first line from the istream, sets int tasks and int rules.
 * Creates the freevector
 * Creates the adjacency Matrix used to hold the Task relationship pairs
 * @param istream& r must be a string that follows the guidelines mentioned in the PFD sphere page
 * Line1:    #Tasks #Rules
 * Line 2-N: #task #dependencies_for_this_task dependency_1 depedency_2
 *
 */
Graph(istream& r);

// ------------
// PFD_read
// ------------

/**
 * Reads in a string that must follow the format:
 * #Tasks #Rules
 * #task #dependencies_for_this_task dependency_1 depedency_2
 * Generate the adjacency matrix, set int key, task in the Graph class. 
 * @param s a string
 */
void PFD_read (istream& r);

// ------------
// PFD_eval
// ------------

/**
 * Has to have the graph initialized, else the function returns false. 
 * Evals returns the run order for a list of tasks and their dependencies
 * The Given graph must not have any cycles!!!
 * Must be a DAG graph
 * The graph must follow the guidelines outlined in the sphere page
 * Output: the resulting list of tasks is put into the resultqueue defined within the graph class
 * @return boolean if the eval was successful, false otherwise
 */
bool PFD_eval ();

// -------------
// PFD_print
// -------------

/**
 * prints the results from PFD_eval in one line with spaces delineating the tasks
 * @param w an ostream
 */
void PFD_print (ostream& w);

};

// -------------
// PFD_solve
// -------------

/**
 * Creates a graph by calling PFD_read
 * Solves the PFD problem using the graph from PFD_read as the input
 * PFD_prints prints the result queue that pfd_eval creates
 * @param r an istream
 * @param w an ostream
 */
void PFD_solve (istream& r, ostream& w);
#endif // PFD_h
