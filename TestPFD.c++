// --------------------------------
// projects/PFD/TestPFD.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "PFD.h"

using namespace std;

// -----------
// TestPFD
// -----------

// ----
// read
// ----

TEST(PFDFixture, read1) {
    istringstream s("5 1\n3 2 1 5\n");

    Graph g(s);
//    bool valid = g.PFD_read(s);
//    ASSERT_TRUE(valid);
}


TEST(PFDFixture, read2) {
    istringstream s("5 4\n3 2 1 5\n2 2 25 3\n4 1 3\n 5 1 1\n");
    Graph g(s);
//    ASSERT_TRUE(g.PFD_read(s));
}


// ----
// eval
// ----

TEST(PFDFixture, eval_1) {
//    const int v = PFD_eval(1, 10);
//    istringstream "5 4\n3 2 1 5\n2 3 5 3 4\n4 1 3\n5 1 1\n";
//    ASSERT_EQ(20, v);
}

TEST(PFDFixture, eval_2) {
	const int v = 20;
//    const int v = PFD_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(PFDFixture, eval_3) {
//    const int v = PFD_eval(201, 210);
	const int v = 20;

    ASSERT_EQ(89, v);}

TEST(PFDFixture, eval_4) {
	const int v = 20;
//    const int v = PFD_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(PFDFixture, eval_5) {
	const int v = 20;
//  const int v = PFD_eval(1000, 900);
    ASSERT_EQ(174, v);}

TEST(PFDFixture, eval_6) {
	const int v = 20;
//    const int v = PFD_eval(1, 1);
    ASSERT_EQ(1, v);}



// -----
// print
// -----

TEST(PFDFixture, print) {
    ostringstream w;

//    PFD_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());
}

TEST(PFDFixture, print_2) {
    ostringstream w;
//    PFD_print(w, 1, 1, 1);
    ASSERT_EQ("1 1 1\n", w.str());}



// -----
// solve
// -----


TEST(PFDFixture, solve1) {
    istringstream r ("5 4\n1 3 2 3 4\n2 2 3 4\n3 1 4\n4 0");
    ostringstream w;
    PFD_solve(r, w);
    ASSERT_EQ("4 5 3 2 1\n", w.str());}

TEST(PFDFixture, solve2) {
    istringstream r ("6 5\n1 4 2 3 4 5\n2 3 3 4 5\n3 2 4 5\n4 1 5\n5 0 ");
    ostringstream w;
    PFD_solve(r, w);
    ASSERT_EQ("5 6 4 3 2 1\n", w.str());}

TEST(PFDFixture, solve3) {
    istringstream r ("7 6\n1 5 2 3 4 5 6\n2 4 3 4 5 6\n3 3 4 5 6\n4 2 5 6\n5 1 6\n6 0");
    ostringstream w;
    PFD_solve(r, w);
    ASSERT_EQ("6 7 5 4 3 2 1\n", w.str());}

TEST(PFDFixture, solve4) {
    istringstream r ("8 7\n1 6 2 3 4 5 6 7\n2 5 3 4 5 6 7\n3 4 4 5 6 7\n4 3 5 6 7\n5 2 6 7\n6 1 7");
    ostringstream w;
    PFD_solve(r, w);
    ASSERT_EQ("7 8 6 5 4 3 2 1\n", w.str());}

TEST(PFDFixture, solve5) {
    istringstream r ("8 7\n1 6 2 3 4 5 6 7\n2 5 3 4 5 6 7\n3 4 4 5 6 7\n\n4 3 5 6 7\n5 2 6 7\n6 1 7\n7 0");
    ostringstream w;
    PFD_solve(r, w);
    ASSERT_EQ("7 8 6 5 4 3 2 1\n", w.str());}


/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.8 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall PFD.c++ TestPFD.c++ -o TestPFD -lgtest -lgtest_main -lpthread



% valgrind TestPFD        >  TestPFD.out 2>&1
% gcov-4.8 -b PFD.c++     >> TestPFD.out
% gcov-4.8 -b TestPFD.c++ >> TestPFD.out



% cat TestPFD.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestPFD
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from PFD
[ RUN      ] PFD.read
[       OK ] PFD.read (31 ms)
[ RUN      ] PFD.eval_1
[       OK ] PFD.eval_1 (5 ms)
[ RUN      ] PFD.eval_2
[       OK ] PFD.eval_2 (3 ms)
[ RUN      ] PFD.eval_3
[       OK ] PFD.eval_3 (3 ms)
[ RUN      ] PFD.eval_4
[       OK ] PFD.eval_4 (3 ms)
[ RUN      ] PFD.print
[       OK ] PFD.print (17 ms)
[ RUN      ] PFD.solve
[       OK ] PFD.solve (10 ms)
[----------] 7 tests from PFD (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'PFD.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'PFD.c++.gcov'
...
File 'TestPFD.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestPFD.c++.gcov'
...
*/
