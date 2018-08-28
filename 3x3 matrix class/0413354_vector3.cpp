#include "0413354_vector3.h"
#include <math.h>
#include <iostream>
vector3 :: vector3(float inX, float inY, float inZ){
   x = inX;
   y = inY ;
   z = inZ ;
}

vector3 :: vector3(const vector3 &v){
   x = v.x ;
   y = v.y ;
   z = v.z ;
}

float &vector3 ::operator [] (unsigned int index){
  if(index == 0){
    return x ;
  }
  else if(index == 1){
    return y ;
  }
  else if(index == 2){
    return z ;
  }
}
const float &vector3 ::operator [] (unsigned int index) const{
     if(index == 0){
    return x ;
  }
  else if(index == 1){
    return y ;
  }
  else if(index == 2){
    return z ;
  }
}

vector3 &vector3 :: operator =  (const vector3 &v){
   x = v.x ;
   y = v.y ;
   z = v.z ;
   return *this ;
}

vector3  &vector3 :: operator += (const vector3 &v){
    x = x + v.x ;
    y = y + v.y ;
    z = z + v.z ;
    return *this ;
}

vector3   &vector3 ::operator -= (const vector3 &v){
    x = x - v.x ;
    y = y - v.y ;
    z = z - v.z ;
    return *this ;
}

vector3   &vector3 ::operator *= (float f){
   x = x * f ;
   y = y * f ;
   z = z * f ;
   return *this ;
}

vector3    &vector3::operator /= (float f){
  x = x / f ;
  y = y / f ;
  z = z / f ;
  return *this ;
}

bool  operator == (const vector3 &a, const vector3 &b){
     if(a.x != b.x)
        return false ;
     if(a.y != b.y)
        return false ;
     if(a.z != b.z)
        return false ;
     return true ;
}

bool    operator != (const vector3 &a, const vector3 &b){
    return !(a == b) ;
}

vector3   operator - (const vector3 &a){
   vector3 c ;
   c.x = -a.x ;
   c.y = -a.y ;
   c.z = -a.z ;
   return c ;
}
vector3   operator + (const vector3 &a, const vector3 &b){
    vector3 c ;
    c.x = a.x + b.x ;
    c.y = a.y + b.y ;
    c.z = a.z + b.z ;
    return c ;
}
vector3    operator - (const vector3 &a, const vector3 &b){
    vector3 c ;
    c.x = a.x - b.x ;
    c.y = a.y - b.y ;
    c.z = a.z - b.z ;
    return c ;
}
vector3     operator * (const vector3 &v, float f){
   vector3 c ;
   c.x = v.x * f ;
   c.y = v.y * f ;
   c.z = v.z * f ;
   return c ;
}
vector3     operator * (float f, const vector3 &v){
    vector3 c ;
   c.x = v.x * f ;
   c.y = v.y * f ;
   c.z = v.z * f ;
   return c ;
}
vector3        operator / (const vector3 &v, float f){
    vector3  c  ;
    c.x = v.x / f ;
    c.y = v.y / f ;
    c.z = v.z / f ;
    return c ;
}
void vector3 ::set(float xIn, float yIn, float zIn){
    x = xIn ;
    y = yIn ;
    z = zIn ;
}
float vector3 ::length() const{
   return sqrt(x*x + y*y + z*z) ;
}
void vector3 ::printVector3() const{
   std::cout <<"(" <<x <<", "<< y<<", " << z << ")"<< "\n";
}



