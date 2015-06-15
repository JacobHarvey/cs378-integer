// ----------------------------
// projects/collatz/Collatz.c++
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

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    //Set i as lower bound and j as uppper
    /*
    int max =1;
    int cur;
    if (i>j){
        cur=j;
        j=i;
        i=cur;
    }
    if (i <= j/2 +1){
        i=j/2+1;
    }
    
    int cycles=1;
    for (int c=i; c<=j; c++){
        cur=c;
        //loop for collatz
        while (cur!=1){
            if (cur%2==0)
                cur/=2;
            else
                cur=cur+ (cur/2)+1; // (3n+1)/2
            cycles++;
        }

    }
    */
    // if x%2==0, >>1, else x=x+x/2+1
    //
    // <your code>
    return 1;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
