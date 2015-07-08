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
        int temp = *b1;
		if(remove){
			--temp;
			remove = false;
		}
		if(b2 != e2){
			int temp2 = *b2;
			if(temp < temp2){
				remove = true;
				temp += 10;
			}
			*x = temp - temp2;
			++b2;
		}
		else{
			if (temp == -1){
				temp += 10;
				remove = true;
			}
			*x = temp;
		}
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
     *  @param const Integer& lhs is *this
     * @param const Integer& rhs
     * @return lhs==rhs
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code> - editing
	if(lhs.neg != rhs.neg)
		return false;
	auto b1 = lhs._x.begin();
	auto e1 = lhs._x.end();
	auto b2 = rhs._x.begin();
	auto e2 = rhs._x.end();
	if((e2-b2) != (e1-b1))
		return false;
	while(b1 != e1){
		int temp = *b1;
		int temp2 = *b2;
		//printf("%d, %d\n", temp, temp2);
		if(temp != temp2)
			return false;
		++b1;
		++b2;
	}
        return true;}

    // -----------
    // operator !=
    // -----------

    /**
     * @param const Integer& lhs is *this
     * @param const Integer& rhs
     * @return !(lhs==rhs)
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * @param lhs const Integer class 
     * @param rhs const Integer class 
     * @return   a boolan value if lhs < rhs
     * determines if the Integer lhs < Integer rhs
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
	if(lhs.neg && !rhs.neg)
		return true;
	else if(!lhs.neg && rhs.neg)
		return false;
	else{
        	auto b1 = lhs._x.begin();
        	auto e1 = lhs._x.end();
        	auto b2 = rhs._x.begin();
        	auto e2 = rhs._x.end();
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
		if(l < r && !lhs.neg)
			return true;
		else if(l > r && lhs.neg)
			return true;
		else
			return false;	
	}
    }

    // -----------
    // operator <=
    // -----------

    /**
     * @param lhs const Integer class 
     * @param rhs const Integer class 
     * @return   a boolan value if lhs <= rhs
     * determines if the Integer lhs <= Integer rhs
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * @param lhs const Integer class 
     * @param rhs const Integer class 
     * @return   a boolan value if lhs > rhs
     * determines if the Integer lhs > Integer rhs 
     * */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * @param lhs const Integer class 
     * @param rhs const Integer class 
     * @return   a boolan value if lhs > rhs
     * determines if the Integer lhs > Integer rhs 
     * */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * @param lhs Integer class 
     * @param rhs const Integer class 
     * @return  r-value of lhs + rhs
     * Calls lhs+=rhs. 
     * Adds rhs to lhs. 
     * Lhs is modified 
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * @param lhs Integer class 
     * @param rhs const Integer class 
     * @return  l-value lhs.
     * lhs= lhs-rhs
     * Calls -=
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
	return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * @param lhs Integer class 
     * @param rhs const Integer class 
     * @return  l-value lhs.
     * lhs= lhs*rhs
     * Calls *=
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * @param lhs Integer class 
     * @param rhs const Integer class 
     * @return  l-value lhs.
     * lhs= lhs/rhs
     * Calls /=
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {

        if (rhs.size() == 0 || rhs.size()==1 && rhs._x[0]==0)
            throw std::invalid_argument("integer::integer()");
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * @param lhs Integer class 
     * @param rhs const Integer class 
     * @return  l-value lhs.
     * lhs= lhs % rhs
     * Calls %=
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        if (rhs<=0)
            throw std::invalid_argument("integer::integer()");
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * @param lhs Integer class 
     * @param int rhs 
     * @return  lhs<<rhs
     * lhs= lhs << rhs
     * Calls <<=
     * if lhs== 100, rhs==2, return==10000
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        if (rhs<0)
            throw std::invalid_argument("Integer::Integer()");
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * @param lhs Integer class 
     * @param rhs const Integer class 
     * @return  l-value lhs.
     * lhs= lhs % rhs
     * Calls <<=
     * @throws invalid_argument if (rhs < 0)

     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        if (rhs<0)
            throw std::invalid_argument("Integer::Integer()");
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * @param lhs ostream 
     * @param const Integer rhs
     * @return  void
     * Outputs rhs to lhs
     * Outputs the largest value to smallest, so
     * rhs= Integer <T,C> (12345),
     * output= 12345
     * Goes from end of rhs._x to begining
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        	// <your code> - edited
		if(rhs.neg)
			lhs << '-';
		auto e = rhs._x.end();
		auto b = rhs._x.begin();
		while(e != b){
			--e;
            		lhs << *e;	
		}
        	return lhs << std::endl;}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * @param Integer x
     * @return Integer x. 
     * Makes x positive
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * @param Integer x
     * @param int e
     * @return l-value x, x= x^e.
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     * calls .pow()
     * throw handled in .pow()
     * Raises x to the power of e
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    private:
        // ----
        // data
        // ----

        C _x; // the backing container
	    bool neg; //used to tell if negative or not

    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            auto iter = _x.begin();
            while (iter != _x.end()){
                if (*iter<0 || *iter>9)
                    return false;
                ++iter;
            }
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * @param value, makes an Integer class with default container of vector<int>
         * @return returns an Integer variable where the container within holds a parsed int variable
         * So if Integer(123) was called, _x[0]==3, _x[1]==2, _x[2]==3
         * Can take in negative values
         * @throws exception if value is not valid
         * */
        Integer (int value) {
            	// <your code> - edited
		
	        if(value == 0){
			_x.push_back(value);
			neg = false;
		}
		else{
	        	neg = value < 0;
            		if (value<0)
                		value*=-1;
			while(value != 0){
				_x.push_back(value % 10);
				value /= 10;
			}
		}
       		assert(valid());}

        /**
         * @param std::string value, makes an Integer class with default container of vector<int>
         * @return returns an Integer variable where the container within holds a parsed int variable
         * Parses the string into the backing container _x
         * So if Integer("123") was called, _x[0]==3, _x[1]==2, _x[2]==3
         * Can take in negative values
         * @throws invalid_argument if value is not a valid representation of an Integer (if a character is passed in instead of a valid number
         */
        explicit Integer (const std::string& value) {
            bool is_neg=false;
            if (value[0]=='-'){
                neg=true;
                is_neg=true;
            }
            for (int c= value.size()-1; c>=1; c--){
                _x.push_back((int)(value[c]-'0'));
            }
            if (!is_neg){
                _x.push_back((int)value[0]-'0');
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
         * @result return negation of *this
         */
        Integer operator - () const {
            	// <your code> - edited
        Integer<T, C> temp (*this);
		temp.neg = (!temp.neg);
        return temp;}

        // -----------
        // operator ++
        // -----------

        /**
         * @return returns lvalue of this incremented by 1
         * Calls +=1
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * @return returns rvalue of this, then *this is incremented by 1
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * @return returns lvalue of *this decremented by 1
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * @return return rvalue of *this, then *this is decremented by 1
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * @param const Integer& rhs
         * @return lvalue of *this+=rhs
         * lhs= lhs+rhs
         * Does basic integer addition
         */
        Integer& operator += (const Integer& rhs) {
            
            /*auto b1 = _x.begin();
            auto e1 = _x.end();
            auto b2 = rhs._x.begin();
            auto e2 = rhs._x.end();
             int size= rhs._x.size()+_x.size();
            Integer <T,C> temp (0);
            for (int i=0; i<size; i++)
                temp._x.push_back(0);
        
            plus_digits (b1, e1, b2, e2, temp._x.begin());
            
             auto iter_end = temp._x.end();
            while (*(--iter_end)==0 && temp._x.size()>1){
                temp._x.pop_back();
            }
            
            *this=temp;
            return *this;*/
		Integer<T, C> temp (0);
                int size= rhs._x.size()+_x.size();
                for (int i=0; i<size; i++)
                        temp._x.push_back(0);


                if(!neg && !rhs.neg){
                        plus_digits(_x.begin(), _x.end(), rhs._x.begin(), rhs._x.end(), temp._x.begin());
                        temp.neg = false;
                }
                else if(neg && rhs.neg){
                        plus_digits(_x.begin(), _x.end(), rhs._x.begin(), rhs._x.end(), temp._x.begin());
                        temp.neg = true;
                }
                else{
                        bool normal;
                        Integer o = *this;
                        Integer t = rhs;
                        normal =  o.abs() > t.abs();

                        if (normal){
                                minus_digits (_x.begin(), _x.end(), rhs._x.begin(), rhs._x.end(), temp._x.begin());
                                temp.neg = neg;
                        }
                        else{
                                minus_digits (rhs._x.begin(), rhs._x.end(), _x.begin(), _x.end(), temp._x.begin());
                                temp.neg = neg;
                        }
                }

                auto iter_end = temp._x.end();
                while (*(--iter_end)==0 && temp._x.size()>1){
                        temp._x.pop_back();
                }

                *this=temp;
                return *this;
	}

        // -----------
        // operator -=
        // -----------

        /**
         * @param const Integer& rhs
         * @return lvalue of *this-=rhs
         * lhs= lhs-rhs
         * Does basic integer subtraction
         */
        Integer& operator -= (const Integer& rhs) {
            	Integer<T, C> temp (0);
            	int size= rhs._x.size()+_x.size(); 
            	for (int i=0; i<size; i++)
                    	temp._x.push_back(0);


       	   	if(neg && !rhs.neg){
			plus_digits(_x.begin(), _x.end(), rhs._x.begin(), rhs._x.end(), temp._x.begin());
			temp.neg = true;
	    	}
		else if(!neg && rhs.neg){
			plus_digits(_x.begin(), _x.end(), rhs._x.begin(), rhs._x.end(), temp._x.begin());
                        temp.neg = false;
		}
	    	else{    			
			bool normal;
			Integer o = *this;
			Integer t = rhs;
			normal =  o.abs() > t.abs();
            if(_x.size() > rhs._x.size())
                normal = true;
            if (_x.size() < rhs._x.size())
                normal = false;
                	if (normal){
                    		minus_digits (_x.begin(), _x.end(), rhs._x.begin(), rhs._x.end(), temp._x.begin());
				temp.neg = neg;
			}
                	else{
                    		minus_digits (rhs._x.begin(), rhs._x.end(), _x.begin(), _x.end(), temp._x.begin());
				if(neg && rhs.neg)
					temp.neg = false;
				else
					temp.neg = rhs.neg;
			}
            	}

            	auto iter_end = temp._x.end();
            	while (*(--iter_end)==0 && temp._x.size()>1){ 
			temp._x.pop_back();
            	}
		
            	*this=temp;
            	return *this;}

        // -----------
        // operator *=
        // -----------

        /**:
         * @param const Integer& rhs
         * @return lvalue of *this*=rhs, lvalue.size() <= *this.size()+rhs.size()
         * lhs= lhs*rhs
         * Does basic integer multiplication
         */
        Integer& operator *= (const Integer& rhs) {
            int size= rhs._x.size()+_x.size();
            Integer <T,C> temp (0);
            for (int i=0; i<size; i++)
                temp._x.push_back(0);
            multiplies_digits (rhs._x.begin(), rhs._x.end(), _x.begin(), _x.end(), temp._x.begin());
            
            auto iter_end = temp._x.end();
            
            while (*(--iter_end)==0 && temp._x.size()>1){
                temp._x.pop_back(); 
            }
	     
            temp.neg= neg ^ rhs.neg;
            *this=temp;
            
            return *this;}
	// -----------
        // operator /=
        // -----------

        /**
         * @param const Integer& rhs
         * @return lvalue of *this/=rhs, lvalue.size() <= *this.size()
         * lhs= lhs*rhs
         * Does basic integer division
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            if (rhs._x.size()==0)
                throw std::invalid_argument("Integer::Integer()");
            Integer <T,C> top(*this);
            Integer <T,C> bot (rhs);
            bot.neg=false;
            top.neg=false;
            Integer <T,C> ret (0);
            while (top>=bot){
                top -= bot;
                ++ret;
            }
            *this=ret;
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * @param const Integer& rhs
         * @return lvalue of *this%=rhs, lvalue.size() <= rhs.size()
         * lhs= lhs%rhs
         * Does basic integer modulo

         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            if (rhs._x.size()==0)
                throw std::invalid_argument("Integer::Integer()");
            Integer <T,C> top(*this);
            Integer <T,C> bot (rhs);
            bot.neg=false;
            top.neg=false;
            Integer <T,C> ret (0);
            while (top>=bot){
                top -= bot;
                ++ret;
            }
            *this=top;
            return *this;

            // <your code>
            return *this;}

        // ------------
        // operator <<=
        // ------------
        /**
         * @param int n
         * @return lvalue &this<< n time
         * if *this=100, n=2, result *this==10000
         */
        Integer& operator <<= (int n) {
            int size= _x.size()+n;
            Integer <T,C> temp (0);
            for (int i=0; i<size; i++)
                temp._x.push_back(0);
            shift_left_digits (_x.begin(), _x.end(), n, temp._x.begin());
            //printf ("%d %d %d %d \n", _x[0], _x[1], _x[2], _x[3]);
            auto iter_end = temp._x.end();

            while (*(--iter_end)==0 && temp._x.size()>1){
                temp._x.pop_back();
            }
	    *this = temp;
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * @param int n
         * @return lvalue &this>> n time
         * if *this=100, n=2, result *this==1
         */
        Integer& operator >>= (int n) {
            int size= _x.size();
            Integer <T,C> temp (0);
            for (int i=0; i<size; i++)
                temp._x.push_back(0);
            shift_right_digits (_x.begin(), _x.end(), n, temp._x.begin());
            //printf ("%d %d %d %d \n", _x[0], _x[1], _x[2], _x[3]);
            auto iter_end = temp._x.end();

            while (*(--iter_end)==0 && temp._x.size()>1){
                temp._x.pop_back();
            }
            *this = temp;
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * @return lvalue |*this|
         */
        Integer& abs () {
            neg=false;
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * @param int e, must be >=0
         * @param *this int, _x.size() must be > 0
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         * raises *this to the power of e, so if *this==3, e==3, result==27
         */
        Integer& pow (int e) {
            if ((_x.size()==1 && _x[0]==0 && e==0) || e<0 || _x.size()==0)
                throw std::invalid_argument("Integer::Integer()");


            
            //*this=pow_aux(e, *this);
            if (e==0){
                *this= Integer <T,C> (1);
                return *this;
            }
            else if (e==1)
                return *this;
            else{
                Integer <T,C> temp1(*this);
                Integer <T,C> temp2(*this);
                Integer <T,C> temp3(*this);
             *this=temp1.pow(e/2)*temp2.pow(e/2)*temp3.pow(e%2);
             return *this;}
        }
      
            





};
#endif // Integer_h
