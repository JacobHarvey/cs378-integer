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

	int tasks;
	int rules;


	vector<vector<bool> > adjMatrix;
	queue<int> results;
	priority_queue <int, vector<int>, greater<int> > runq;
	priority_queue <int, vector<int>, greater<int> > stageq;
	vector<bool> freevector;


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
#endif // PFD_h
