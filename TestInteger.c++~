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


TEST(IntegerFixture, multiplies_digits_1) {
        using namespace std;
        //std::vector<int> input  (4, 100);

    	int array[] = {3, 2, 1};
        std::vector<int> og (array, array + sizeof(array) / sizeof(int));
        std::vector<int> of (array, array + sizeof(array) / sizeof(int));
    	
        std::vector<int> output(6, 0);
        std::vector<int>::iterator og_b = og.begin();
        std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator of_b = of.begin();
        std::vector<int>::iterator of_e = of.end();
        std::vector<int>::iterator output_b = output.begin();
	    std::vector<int>::iterator result = multiplies_digits(og_b, og_e, of_b, of_e, output_b);
        int r_array[] = {9, 2, 1, 5, 1};
        std::vector<int>  correct (r_array, r_array + sizeof(r_array) / sizeof(int));
        if (*(--result)==0){
            output.resize(5);
        }
        
	    ASSERT_TRUE(equal(correct.begin(), correct.end(), output.begin()));
        
}
    //	ASSERT_TRUE(equal(correct.begin(), correct.end(), output.begin()));
        

TEST(IntegerFixture, multiplies_digits_2) {
        using namespace std;
        //std::vector<int> input  (4, 100);

    	int array[] = {9, 9, 9};
        std::vector<int> og (array, array + sizeof(array) / sizeof(int));
        std::vector<int> of (array, array + sizeof(array) / sizeof(int));
    	
        std::vector<int> output(6, 0);
        std::vector<int>::iterator og_b = og.begin();
        std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator of_b = of.begin();
        std::vector<int>::iterator of_e = of.end();
        std::vector<int>::iterator output_b = output.begin();
	    std::vector<int>::iterator result = multiplies_digits(og_b, og_e, of_b, of_e, output_b);
        int r_array[] = {1,0,0,8,9,9};
        std::vector<int>  correct (r_array, r_array + sizeof(r_array) / sizeof(int));
        if (*(--result)==0){
            output.resize(5);
        }
        
    	ASSERT_TRUE(equal(correct.begin(), correct.end(), output.begin()));
        
}

TEST(IntegerFixture, multiplies_digits_3) {
        using namespace std;
        //std::vector<int> input  (4, 100);

    	int array[] = {9, 9, 9};
        std::vector<int> og (array, array + sizeof(array) / sizeof(int));
        int array2 []= {0};
        std::vector<int> of (array2, array2 + sizeof(array2) / sizeof(int));
    	
        std::vector<int> output(6, 0);
        std::vector<int>::iterator og_b = og.begin();
        std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator of_b = of.begin();
        std::vector<int>::iterator of_e = of.end();
        std::vector<int>::iterator output_b = output.begin();
	    std::vector<int>::iterator result = multiplies_digits(og_b, og_e, of_b, of_e, output_b);
        int r_array[] = {0};
        std::vector<int>  correct (r_array, r_array + sizeof(r_array) / sizeof(int));
    	ASSERT_EQ(*output_b, 0);
        
}
TEST(IntegerFixture, multiplies_digits_4) {
        using namespace std;
        //std::vector<int> input  (4, 100);

    	int array[] = {9, 9, 9};
        std::vector<int> og (array, array + sizeof(array) / sizeof(int));
        int array2 []= {0};
        std::vector<int> of (array2, array2 + sizeof(array2) / sizeof(int));
    	
        std::vector<int> output(6, 0);
        std::vector<int>::iterator og_b = og.begin();
        std::vector<int>::iterator og_e = og.end();
        std::vector<int>::iterator of_b = of.begin();
        std::vector<int>::iterator of_e = of.end();
        std::vector<int>::iterator output_b = output.begin();
	    std::vector<int>::iterator result = multiplies_digits(og_b, og_e, of_b, of_e, output_b);
        int r_array[] = {0};
        std::vector<int>  correct (r_array, r_array + sizeof(r_array) / sizeof(int));
    	ASSERT_TRUE(equal(correct.begin(),correct.end(), output.begin()));
        
}




TEST(IntegerFixture, valid_1) {
        using namespace std;
        //std::vector<int> input  (4, 100)
        try{
            Integer <int> n = Integer<int>("13a");
        }
        catch (exception& e){
            return;
        }
    	ASSERT_EQ( 1, 0);
}

TEST(IntegerFixture, valid_2) {
        using namespace std;
        //std::vector<int> input  (4, 100)
        try{
            Integer <int> n = Integer<int>(125);
        }
        catch (exception& e){
            ASSERT_EQ (1,0);
        }
}
TEST(IntegerFixture, valid_3) {
        using namespace std;
        //std::vector<int> input  (4, 100)
        try{
            Integer <int> n = Integer<int>(129999999);
        }
        catch (exception& e){
            ASSERT_EQ (1,0);
        }
}
TEST(IntegerFixture, valid_4) {
        using namespace std;
        //std::vector<int> input  (4, 100)
        try{
            Integer <int> n = Integer<int>("99999999999999999999999999999999999999999999999999999999999999");
        }
        catch (exception& e){
            ASSERT_EQ (1,0);
        }
}
TEST(IntegerFixture, valid_5) {
        using namespace std;
        //std::vector<int> input  (4, 100)
        try{
            Integer <int> n = Integer<int>(0);
        }
        catch (exception& e){
            ASSERT_EQ (1,0);
        }
}

TEST(IntegerFixture, valid_6) {
        using namespace std;
        
        try{
            Integer <int> n = Integer<int>("");
        }
        catch (exception& e){
            return;    
        }
        //ASSERT_EQ(0,1);

}
TEST(IntegerFixture, valid_7) {
        using namespace std;
        try{
            Integer <int, std::deque<int> > n = Integer<int, std::deque<int> >(129999999);
        }
        catch (exception& e){
            ASSERT_EQ (1,0);
        }
}
TEST(IntegerFixture, valid_8) {
        using namespace std;
        try{
            Integer <int, std::deque<int> > n = Integer<int, std::deque<int> >(-12999);
        }
        catch (exception& e){
            ASSERT_EQ (1,0);
        }
}
TEST(IntegerFixture, valid_9) {
        using namespace std;
        try{
            Integer <int, std::deque<int> > n = Integer<int, std::deque<int> >("-12999999");
        }
        catch (exception& e){
            ASSERT_EQ (1,0);
        }
}





TEST(IntegerFixture, equals_1) {
        using namespace std;
        
        Integer <int> n = Integer<int>(2);
        Integer <int> x = Integer<int> (2);
        ASSERT_TRUE(n==x);
}
TEST(IntegerFixture, equals_2) {
        using namespace std;
        
        Integer <int> n = Integer<int>(3);
        Integer <int> x = Integer<int> (2);
        ASSERT_FALSE(n==x);
}
TEST(IntegerFixture, notequals_1) {
        using namespace std;
        
        Integer <int> n = Integer<int>(2);
        Integer <int> x = Integer<int> (2);
        ASSERT_FALSE(n!=x);
}
TEST(IntegerFixture, notequals_2) {
        using namespace std;
        
        Integer <int> n = Integer<int>(3);
        Integer <int> x = Integer<int> (2);
        ASSERT_TRUE(n!=x);
}






TEST(IntegerFixture, timesequal_1) {
        using namespace std;
        
        Integer <int> n = Integer<int>(123);
        Integer <int> x = Integer<int> (2);
        n *= x;
        Integer <int> result = Integer<int> (246);
        ASSERT_TRUE(result==n);
    	
}

TEST(IntegerFixture, timesequal_2) {
        using namespace std;
        
        Integer <int> n = Integer<int>(999);
        Integer <int> x = Integer<int> (999);
        n *= x;
        Integer <int> result = Integer<int> (998001);
        ASSERT_TRUE(result==n);
    	
}


TEST(IntegerFixture, timesequal_3) {
        using namespace std;
        
        Integer <int> n = Integer<int>(123);
        Integer <int> x = Integer<int> (0);
        n *= x;
        Integer <int> result = Integer<int> (0);
        ASSERT_TRUE(result == n);
}



TEST(IntegerFixture, negation_1) {
        using namespace std;
        
        Integer <int> n = Integer<int>(123);
        n = -n;
	
        Integer <int> result = Integer<int> (-123);
        ASSERT_TRUE(result == n);
}


TEST(IntegerFixture, negation_2) {
        using namespace std;
        
        Integer <int> n = Integer<int>(-123);
        n = -n;
	
        Integer <int> result = Integer<int> (123);
        ASSERT_TRUE(result == n);
}






TEST(IntegerFixture, pow_1) {
        using namespace std;
        
        Integer <int> n = Integer<int>(2);
        n.pow(3);
        Integer <int> result = Integer<int> (8);
        ASSERT_TRUE(result==n);
    	
}


TEST(IntegerFixture, pow_2) {
        using namespace std;
        
        Integer <int> n = Integer<int>(3);
        n.pow(3);
        Integer <int> result = Integer<int> (27);
        ASSERT_TRUE(result==n);
    	
}



TEST(IntegerFixture, pow_3) {
        using namespace std;
        try{
            Integer <int> n = Integer<int>(0);
            n.pow(3);
            Integer <int> result = Integer<int> (0);
            ASSERT_TRUE(result==n);
        }
        catch (exception& e){
            ASSERT_EQ(1,0);
        }
    	
}
TEST(IntegerFixture, pow_4) {
        using namespace std;
        try{
            Integer <int> n = Integer<int>(0);
            n.pow(0);
            Integer <int> result = Integer<int> (0);
            ASSERT_TRUE(result==n);
        }
        catch (exception& e){
            return;
        }
        ASSERT_EQ(1,0);
}


TEST(IntegerFixture, pow_5) {
        using namespace std;
        try{
            Integer <int> n = Integer<int>(4);
            n.pow(-2);
            Integer <int> result = Integer<int> (4);
            ASSERT_TRUE(result==n);
        }
        catch (exception& e){
            return;
        }
    	ASSERT_EQ(1,0);
}






TEST(IntegerFixture, lessthan_1){
        using namespace std;
        Integer <int> n = Integer<int>(23);
        Integer <int> m = Integer<int>(22);
        ASSERT_TRUE(m < n);
}


TEST(IntegerFixture, lessthan_2){
        using namespace std;
        Integer <int> n = Integer<int>(-23);
        Integer <int> m = Integer<int>(-22);
        ASSERT_TRUE(n < m);
}

TEST(IntegerFixture, lessthan_3){
        using namespace std;
        Integer <int> n = Integer<int>(23);
        Integer <int> m = Integer<int>(-22);
        ASSERT_TRUE(m < n);
}

TEST(IntegerFixture, lessthan_4){
        using namespace std;
        Integer <int> n = Integer<int>(-23);
        Integer <int> m = Integer<int>(22);
        ASSERT_TRUE(n < m);
}

TEST(IntegerFixture, minusequals_1){
        using namespace std;
        Integer <int> n = Integer<int>(23);
        Integer <int> m = Integer<int>(22);
        Integer <int> output = Integer<int>(1);
	ASSERT_TRUE((n -= m) == output );
}


TEST(IntegerFixture, minusequals_2){
        using namespace std;
        Integer <int> n = Integer<int>(23);
        Integer <int> m = Integer<int>(12);
        Integer <int> output = Integer<int>(11);
        ASSERT_TRUE((n -= m) == output );
}

TEST(IntegerFixture, minusequals_3){
        using namespace std;
        Integer <int> n = Integer<int>(9000);
        Integer <int> m = Integer<int>(1);
        Integer <int> output = Integer<int>(8999);
        n-=m;
	ASSERT_TRUE((n) == output );
}

TEST(IntegerFixture, minusequals_4){
        using namespace std;
        Integer <int> n = Integer<int>(-9);
        Integer <int> m = Integer<int>(-8);
        Integer <int> output = Integer<int>(-1);
        ASSERT_TRUE((n -= m) == output );
}


TEST(IntegerFixture, minusequals_5){
        using namespace std;
        Integer <int> n = Integer<int>(-8);
        Integer <int> m = Integer<int>(-9);
        Integer <int> output = Integer<int>(1);
        ASSERT_TRUE((n -= m) == output );
}

TEST(IntegerFixture, minusequals_6){
        using namespace std;
        Integer <int> n = Integer<int>(-9);
        Integer <int> m = Integer<int>(1);
        Integer <int> output = Integer<int>(-10);
        n-=m;
	ASSERT_TRUE((n) == output );
}

TEST(IntegerFixture, minusequals_7){
        using namespace std;
        Integer <int> n = Integer<int>(-1);
        Integer <int> m = Integer<int>(9);
        Integer <int> output = Integer<int>(-10);
        ASSERT_TRUE((n -= m) == output );
}

TEST(IntegerFixture, minusequals_8){
        using namespace std;
        Integer <int> n = Integer<int>(234);
        Integer <int> m = Integer<int>(-2);
        Integer <int> output = Integer<int>(236);
        ASSERT_TRUE((n -= m) == output );
}

TEST(IntegerFixture, minusequals_9){
        using namespace std;
        Integer <int> n = Integer<int>(-2);
        Integer <int> m = Integer<int>(234);
	Integer <int> output = Integer<int>(-236);
        ASSERT_TRUE((n -= m) == output );
}

TEST(IntegerFixture, minusequals_10){
        using namespace std;
        Integer <int> n = Integer<int>(-45);
        Integer <int> m = Integer<int>(5);
        Integer <int> output = Integer<int>(-50);
        ASSERT_TRUE((n -= m) == output );
}

TEST(IntegerFixture, minusequals_11){
        using namespace std;
        Integer <int> n = Integer<int>(-45);
        Integer <int> m = Integer<int>(-5);
        Integer <int> output = Integer<int>(-40);
        ASSERT_TRUE((n -= m) == output );
}

TEST(IntegerFixture, plusequals_1){
        using namespace std;
        Integer <int> n = Integer<int>(2);
        Integer <int> m = Integer<int>(22);
        Integer <int> output = Integer<int>(24);
        ASSERT_TRUE((n += m) == output );
}

TEST(IntegerFixture, plusequals_2){
        using namespace std;
        Integer <int> n = Integer<int>(23);
        Integer <int> m = Integer<int>(12);
        Integer <int> output = Integer<int>(35);
        ASSERT_TRUE((n += m) == output );
}

TEST(IntegerFixture, plusequals_3){
        using namespace std;
        Integer <int> n = Integer<int>(8999);
        Integer <int> m = Integer<int>(1);
        Integer <int> output = Integer<int>(9000);
        ASSERT_TRUE((n += m) == output );
}

TEST(IntegerFixture, plusequals_4){
        using namespace std;
        Integer <int> n = Integer<int>(-8999);
        Integer <int> m = Integer<int>(1);
        Integer <int> output = Integer<int>(-8998);
        ASSERT_TRUE((n += m) == output );
}

TEST(IntegerFixture, plusequals_5){
        using namespace std;
        Integer <int> n = Integer<int>(-8);
        Integer <int> m = Integer<int>(-1);
        Integer <int> output = Integer<int>(-9);
        ASSERT_TRUE((n += m) == output );
}

TEST(IntegerFixture, plusequals_6){
        using namespace std;
        Integer <int> n = Integer<int>(9);
        Integer <int> m = Integer<int>(-1);
        Integer <int> output = Integer<int>(8);
        ASSERT_TRUE((n += m) == output );
}

TEST(IntegerFixture, leftshiftequals_1) {

        Integer <int> k = Integer<int>(1111);
        int n = 2;
        k <<= n;
	Integer <int> real = Integer<int>(111100);
        ASSERT_EQ(real, k);

}

TEST(IntegerFixture, leftshiftequals_2) {

        Integer <int> k = Integer<int>(4);
        int n = 6;
        k <<= n;
        Integer <int> real = Integer<int>(4000000);
        ASSERT_EQ(real, k);

}

TEST(IntegerFixture, leftshiftequals_3) {

        Integer <int> k = Integer<int>(70);
        int n = 3;
        k <<= n;
        Integer <int> real = Integer<int>(70000);
        ASSERT_EQ(real, k);

}


TEST(IntegerFixture, rightshiftequals_1) {

        Integer <int> k = Integer<int>(1111);
        int n = 2;
        k >>= n;
        Integer <int> real = Integer<int>(11);
        ASSERT_EQ(real, k);

}

TEST(IntegerFixture, rightshiftequals_2) {

        Integer <int> k = Integer<int>(5678);
        int n = 3;
        k >>= n;
        Integer <int> real = Integer<int>(5);
        ASSERT_EQ(real, k);

}

TEST(IntegerFixture, rightshiftequals_3) {

        Integer <int> k = Integer<int>(1);
        int n = 1;
        k >>= n;
        Integer <int> real = Integer<int>(0);
        ASSERT_EQ(real, k);

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
