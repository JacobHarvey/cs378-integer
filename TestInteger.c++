// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <vector>   // vector

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

// -----------
// TestInteger
// -----------

// ----
// shift_left_digits
// ----

TEST(IntegerFixture, shift_left_digits_1) {

    	int array[] = {1, 1, 1};
    	vector<int> og (array, array + sizeof(array) / sizeof(int));
    	int n = 2;
	int real[] = {0, 0, 1, 1, 1};
	vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
	std::vector<int> output(5, 0);
	std::vector<int>::iterator og_b = og.begin();
	std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator output_b = output.begin();

	std::vector<int>::iterator output_e = shift_left_digits(og_b, og_e, n, output_b);
	
    	ASSERT_EQ(real_answer, output);
        
}

TEST(IntegerFixture, shift_left_digits_2) {

        int array[] = {2, 1, 1, 8};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int n = 7;
        int real[] = {0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 8};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        std::vector<int> output(11, 0);
        std::vector<int>::iterator og_b = og.begin();
        std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator output_b = output.begin();

        std::vector<int>::iterator output_e = shift_left_digits(og_b, og_e, n, output_b);

        ASSERT_EQ(real_answer, output);

}

TEST(IntegerFixture, shift_left_digits_3) {

        int array[] = {5};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int n = 7;
        int real[] = {0, 0, 0, 0, 0, 0, 0, 5};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        std::vector<int> output(8, 0);
        std::vector<int>::iterator og_b = og.begin();
        std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator output_b = output.begin();

        std::vector<int>::iterator output_e = shift_left_digits(og_b, og_e, n, output_b);

        ASSERT_EQ(real_answer, output);

}

// ----
// shift_right_digits
// ----

TEST(IntegerFixture, shift_right_digits_1) {

        int array[] = {1, 1, 1};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int n = 2;
        int real[] = { 1};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        std::vector<int> output(1, 0);
        std::vector<int>::iterator og_b = og.begin();
        std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator output_b = output.begin();

        std::vector<int>::iterator output_e = shift_right_digits(og_b, og_e, n, output_b);

        ASSERT_EQ(real_answer, output);

}


TEST(IntegerFixture, shift_right_digits_2) {

        int array[] = {2, 3, 4, 6, 7};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int n = 3;
        int real[] = {6, 7};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(2, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = shift_right_digits(og_b, og_e, n, output_b);

        ASSERT_EQ(real_answer, output);

}

TEST(IntegerFixture, shift_right_digits_3) {

        int array[] = {2, 3, 4};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int n = 1;
        int real[] = {3, 4};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(2, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = shift_right_digits(og_b, og_e, n, output_b);

        ASSERT_EQ(real_answer, output);

}

// ----
// plus_digits
// ----

TEST(IntegerFixture, plus_digits_1) {
	//(11 ) <- carries
	// 432
	//+
	// 789
	//------
	//1221
        int array[] = {2, 3, 4};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
	int array2[] = {9, 8, 7};
	vector<int> og2 (array2, array2 + sizeof(array2) / sizeof(int));

        int real[] = {1, 2, 2, 1};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(4, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
	vector<int>::iterator og2_b = og2.begin();
        vector<int>::iterator og2_e = og2.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = plus_digits(og_b, og_e, og2_b, og2_e, output_b);

        ASSERT_EQ(real_answer, output);

}

TEST(IntegerFixture, plus_digits_2) {
        //( 1 ) <- carries
        // 002
        //+
        // 789
        //------
        // 791
        int array[] = {2};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int array2[] = {9, 8, 7};
        vector<int> og2 (array2, array2 + sizeof(array2) / sizeof(int));

        int real[] = {1, 9, 7};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(3, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
        vector<int>::iterator og2_b = og2.begin();
        vector<int>::iterator og2_e = og2.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = plus_digits(og_b, og_e, og2_b, og2_e, output_b);

        ASSERT_EQ(real_answer, output);

}

TEST(IntegerFixture, plus_digits_3) {
        //(1  ) <- carries
        // 888
        //+
        //  20
        //------
        // 908
        int array[] = {8, 8, 8};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int array2[] = {0, 2};
        vector<int> og2 (array2, array2 + sizeof(array2) / sizeof(int));

        int real[] = {8, 0, 9};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(3, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
        vector<int>::iterator og2_b = og2.begin();
        vector<int>::iterator og2_e = og2.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = plus_digits(og_b, og_e, og2_b, og2_e, output_b);

        ASSERT_EQ(real_answer, output);

}

// ----
// minus_digits
// ----

TEST(IntegerFixture, minus_digits_1) {
        //(   ) <- borrows
        // 789
        //-
        // 432
        //------
        // 357
        int array[] = {9, 8, 7};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int array2[] = {2, 3, 4};
        vector<int> og2 (array2, array2 + sizeof(array2) / sizeof(int));

        int real[] = {7, 5, 3};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(3, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
        vector<int>::iterator og2_b = og2.begin();
        vector<int>::iterator og2_e = og2.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = minus_digits(og_b, og_e, og2_b, og2_e, output_b);

        ASSERT_EQ(real_answer, output);

}

TEST(IntegerFixture, minus_digits_2) {
        //( 1 ) <- borrows
        // 987
        //-
        // 009
        //------
        // 978
        int array[] = {7, 8 ,9};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int array2[] = {9};
        vector<int> og2 (array2, array2 + sizeof(array2) / sizeof(int));

        int real[] = {8, 7, 9};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(3, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
        vector<int>::iterator og2_b = og2.begin();
        vector<int>::iterator og2_e = og2.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = minus_digits(og_b, og_e, og2_b, og2_e, output_b);

        ASSERT_EQ(real_answer, output);

}

TEST(IntegerFixture, minus_digits_3) {
        //( 1 ) <- borrows
        // 955
        //-
        // 587
        //------
        // 368
        int array[] = {5, 5, 9};
        vector<int> og (array, array + sizeof(array) / sizeof(int));
        int array2[] = {7, 8, 5};
        vector<int> og2 (array2, array2 + sizeof(array2) / sizeof(int));

        int real[] = {8, 6, 3};
        vector<int> real_answer (real, real + sizeof(real) /sizeof(int));
        vector<int> output(3, 0);
        vector<int>::iterator og_b = og.begin();
        vector<int>::iterator og_e = og.end();
        vector<int>::iterator og2_b = og2.begin();
        vector<int>::iterator og2_e = og2.end();
        vector<int>::iterator output_b = output.begin();

        vector<int>::iterator output_e = minus_digits(og_b, og_e, og2_b, og2_e, output_b);

        ASSERT_EQ(real_answer, output);

}

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
