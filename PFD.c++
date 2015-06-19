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

#include "PFD.h"

using namespace std;

int CACHESIZE = 100000;
#define CACHE true
#ifdef CACHE
int cache [100000];
#endif

// ------------
// PFD_read
// ------------
int PFD_eval_simple (int i, int j);
pair<int, int> PFD_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    assert (i > 0);
    assert (j > 0); 
    return make_pair(i, j);}

// ------------
// PFD_eval
// ------------

int PFD_eval (int i, int j) {
    //Set i as lower bound and j as uppper
    int max =1;
    int cur;
    if (i>j){
        cur=j;
        j=i;
        i=cur;
    }
    assert (i>0);
    assert (j< 1000000);
    assert (CACHESIZE > 0);
    if (i <= j/2 +1){
        i=j/2+1;
    }
    int cycles=1;
    for (int c=i; c<=j; c++){
        cycles=1;
        cur=c; //cur is the current value/ mover for the func
        //loop for PFD
        while (cur!=1){
            if (cur < CACHESIZE && cache[cur]!= 0){
                cycles += cache[cur] -1;
                break;
            }
            else if ((cur%2) == 0){
                cur /= 2;
                ++cycles;
            }
            else{
                cur=cur+ (cur/2)+1; // (3n+1)/2
                cycles+=2;
            }
        }
        if (c < CACHESIZE){
            cache[c] = cycles;
        }
        assert (cycles>0);
        if (cycles>max)
            max=cycles;
    }
    
    // if x%2==0, >>1, else x=x+x/2+1
    //
    // <your code>
    assert (max>0);
    return max;}

int PFD_eval_simple (int i, int j){
    int max =1;
    int cur;
    if (i>j){
        cur=j;
        j=i;
        i=cur;
    }
    assert (i>0);
    assert (j< 1000000);
    
    if (i <= j/2 +1){
        i=j/2+1;
    }
    int cycles=1;
    for (int c=i; c<=j; c++){
        cycles=1;
        cur=c; //cur is the current value/ mover for the func
        //loop for PFD
        while (cur!=1){
            if ((cur%2) == 0){
                cur /= 2;
                ++cycles;
            }
            else{
                cur=cur+ (cur/2)+1; // (3n+1)/2
                cycles+=2;
            }
        }
        assert (cycles>0);
        if (cycles>max)
            max=cycles;
    }
    
    // if x%2==0, >>1, else x=x+x/2+1
    //
    // <your code>
    assert (max>0);
    return max;}
// -------------
// PFD_print
// -------------

void PFD_print (ostream& w, int i, int j, int v) {
    assert (i > 0);
    assert (j > 0);
    assert (v > 0);
    w << i << " " << j << " " << v << endl;}

// -------------
// PFD_solve
// -------------

void PFD_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = PFD_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = PFD_eval(i, j);
        PFD_print(w, i, j, v);}}
