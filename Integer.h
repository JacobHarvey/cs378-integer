// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <deque>
// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
using namespace std;
template <typename II, typename OI>
OI shift_left_digits (II b, II e, int n, OI x) {
    	// <your code> - edited
	//this is if we have the least significant digit first
	while (n > 0){
                *x = 0;
                ++x;
		--n;
        }
	while(b != e){
		*x = *b;
		++x;
		++b;
	}
	
    	return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename OI>
OI shift_right_digits (II b, II e, int n, OI x) {
    	// <your code> - edited
	b += n;
	while(b != e){
		*x = *b;
		++x;
		++b;
	}
    	return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    	// <your code> - edited
	int carry = 0;
	while(b1 != e1 || b2 != e2){
		*x += carry;
		if(b1 != e1){
			*x += *b1;
			++b1;
		}
		if(b2 != e2){
			*x += *b2;
			++b2;
		}
		carry = *x / 10;
		*x %= 10;
		++x;
	}
	if(carry != 0){
		*x = carry;
		++x;
	}
    	return x;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename OI>
OI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    	// <your code> - editing
	bool remove = false;
	while(b1 != e1){
		if(remove){
			--*b1;
			remove = false;
		}
		if(b2 != e2){
			if(*b1 < *b2){
				remove = true;
				*b1 += 10;
			}
			*x = *b1 - *b2;
			++b2;
		}
		else
			*x = *b1;
		++b1;
		++x;	
	}

    	return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */

template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    int add=0;
    auto b2_t = b2;
    while (b1!=e1){
        auto output = x;
        add=0;
        int carry = 0;
        int var_1 = *b1;
        //cout << *b1 << endl;
        b2_t = b2;
        while (b2_t!=e2){
            int temp = carry + (var_1 * *b2_t) + *output;
            //cout << temp << "  ";
            carry = temp / 10;
            *output = temp % 10;
            ++output;
            ++b2_t;
        }
        while (carry!=0){
            ++add;
            *output+=carry%10;
            carry/=10;
            ++output;
        }
        //cout << endl;
        ++b1;
        //++temp;
        ++x;
    }
    return x+add;}


// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    return x;}

// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code> - editing
	typename C::iterator b1 = lhs._x.begin();
	typename C::iterator e1 = lhs._x.end();
	typename C::iterator b2 = rhs._x.begin();
	typename C::iterator e2 = rhs._x.end();
	if((e2-b2) != (e1-b1))
		return false;
	while(b1 != e1){
		if(*b1 != *b2)
			return false;
		++b1;
		++b2;
	}
        return true;}

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
	if(lhs.neg && !rhs.neg)
		return true;
	else if (!lhs.neg && rhs.neg)
		return false;
	else{
		typename C::iterator b1 = lhs._x.begin();
        	typename C::iterator e1 = lhs._x.end();
        	typename C::iterator b2 = rhs._x.begin();
        	typename C::iterator e2 = rhs._x.end();
		int l = 0;
		int r = 0;
		int i = 1;
		while(b1 != e1){
			l += (*b1 * i);
			i *= 10;
			++b1;
		}	
		i = 1;
		while(b2 != e2){
                        r += (*b2 * i);
                        i *= 10;
                        ++b2;
                }
		if(!lhs.neg && l < r)
			return true;
		else if(lhs.neg && r < l)
			return true;
		else
			return false;	
	}
    }

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        	// <your code> - edited
		typename C::iterator e = rhs._x.end();
		typename C::iterator b = rhs._x.begin();
		while(e != b){
			lhs << *e;
			--e;	
		}
        	return lhs << std::endl;}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container
        // <your data>
	bool neg;

    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            auto iter = _x.begin();
            while (iter != _x.end()){
                if (*iter<0 || *iter>9)
                    return false;
            }
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Integer (int value) {
            	// <your code> - edited
		while(value != 0){
			_x.push_back(value % 10);
			value /= 10;
		}
		neg = value<0;
        assert(valid());}

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            for (int c= value.size()-1; c>=0; c--){
                _x.push_back((int)(value[c]-'0'));
            }
            if (!valid())
                throw std::invalid_argument("Integer::Integer()");}

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        Integer operator - () const {
            	// <your code> - edited
		neg = (!neg);
        	return *this;}

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            int size= rhs._x.size()+*this._x.size();
            vector <int> temp (_x);
            _x.clear();
            for (int i=0; i<size; i++)
                _x.push_back(0);

            multiplies_digits (rhs.begin(), rhs.end(), *this.begin(), *this.end(), temp.begin());
            auto iter_end = temp.end();
            if (*(--iter_end)==0){
                temp.resize(--size);
            }
            _x=temp;
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            // <your code>
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            return *this;}};

#endif // Integer_h
