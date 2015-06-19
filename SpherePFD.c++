
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

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
int CACHESIZE = 100000;
#define CACHE true
#ifdef CACHE
int cache [100000];
#endif

using namespace std;
pair<int, int> PFD_read (const string& s); 
int PFD_eval (int i, int j);
void PFD_print (ostream& w, int i, int j, int v);
void PFD_solve (istream& r, ostream& w); 


// ----
// main
// ----

int main () {
    using namespace std;
    PFD_solve(cin, cout);
    return 0;}

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
    if (i > j){
        cur = j;
        j = i;
        i = cur;
    }
    assert (i > 0);
    assert (j < 1000000);
    assert (CACHESIZE > 0);
    if (i <= j/2 +1){
        i= j/2 + 1;
    }
    int cycles=1;
    for (int c = i; c <= j; c++){
        cycles = 1;
        cur = c; //cur is the current value/ mover for the func
        while (cur!=1){
            //test to see if cache
            if (cur < CACHESIZE && cache[cur]!= 0){
                cycles += cache[cur] -1;
                break;
            }
            else if ((cur%2) == 0){
                cur /= 2;
                ++cycles;
            }
            else{
                cur= cur + (cur/2) + 1; // (3n+1)/2
                cycles += 2;
            }
        }
        //add to cache
        if (c < CACHESIZE){
            cache[c] = cycles;
        }
        assert (cycles > 0);
        if (cycles > max)
            max = cycles;
    }

    assert (max > 0);
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
/*
% g++-4.8 -pedantic -std=c++11 -Wall PFD.c++ RunPFD.c++ -o RunPFD



% cat RunPFD.in
1 10
100 200
201 210
900 1000



% RunPFD < RunPFD.in > RunPFD.out



% cat RunPFD.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
