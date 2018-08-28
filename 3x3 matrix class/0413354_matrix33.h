#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "0413354_vector3.h"

class matrix33
{
    public:
	/* data members */
	vector3 vx,vy,vz ;


public:
	/* constructors */
	// default constructor -- don't do anything with it
	matrix33() {};

	// constructor with initializing float values
	matrix33(vector3 inX, vector3 inY, vector3 inZ);

	// constructor with initializing matrix33
	matrix33(const matrix33 &m);

public:
	/* Operators */

	// access element
	vector3                 &operator [] (unsigned int index);
	const vector3           &operator [] (unsigned int index) const;

	matrix33               &operator =  (const matrix33 &m);
	matrix33               &operator += (const matrix33 &m);
	matrix33               &operator -= (const matrix33 &m);
	matrix33               &operator *= (float f);
	matrix33               &operator /= (float f);
	friend bool           operator == (const matrix33 &a, const matrix33 &b);
	friend bool           operator != (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator - (const matrix33 &a);
	friend matrix33       operator + (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator - (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator * (const matrix33 &m, float f);
	friend matrix33        operator * (float f, const matrix33 &m);
	friend matrix33        operator * (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator / (const matrix33 &m, float f);

 public:
	 /* Methods */

	 // set values (e.g. x = xIn, ...)
	 void set(vector3 xIn, vector3 yIn, vector3 zIn);

	 // calculate length
	 float determinant() const;

	  // print matrix using std::cout
	 void printMatrix() const;

      //identity matrix
      matrix33 identity() ;

      //invert matrix
     matrix33 invert() ;


};

#endif

