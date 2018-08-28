#include "0413354_matrix33.h"
#include <iostream>
#include <iomanip>
matrix33:: matrix33(vector3 inX, vector3 inY, vector3 inZ){
    vx = inX ;
    vy = inY ;
    vz = inZ ;
}
matrix33 ::matrix33(const matrix33 &m){
    vx = m.vx ;
    vy = m.vy ;
    vz = m.vz ;
}
vector3 &matrix33::operator [] (unsigned int index){
    if(index == 0){
        return vx ;
    }
    if(index == 1){
        return vy ;
    }
    if(index == 2){
        return vz ;
    }
}
const vector3  &matrix33::operator [] (unsigned int index) const {
    if(index == 0){
        return vx ;
    }
    if(index == 1){
        return vy ;
    }
    if(index == 2){
        return vz ;
    }
}
matrix33& matrix33::operator =  (const matrix33 &m){
   vx = m.vx ;
   vy = m.vy ;
   vz = m.vz ;
   return *this ;
}
matrix33  &matrix33::operator += (const matrix33 &m){
   vx += m.vx ;
   vy += m.vy ;
   vz += m.vz ;
   return *this ;
}
matrix33  &matrix33::operator -= (const matrix33 &m){
    vx -= m.vx ;
    vy -= m.vy ;
    vz -= m.vz ;
    return *this ;
}
matrix33   &matrix33::operator *= (float f){
    vx *= f ;
    vy *= f ;
    vz *= f ;
    return *this ;
}
matrix33  &matrix33::operator /= (float f){
    vx /= f ;
    vy /= f ;
    vz /= f ;
    return *this ;
}
bool      operator == (const matrix33 &a, const matrix33 &b){
    if(a.vx != b.vx){
        return false ;
    }
    if(a.vy != b.vy){
        return false ;
    }
    if(a.vz != b.vz){
        return false ;
    }
    return true ;
}
bool  operator != (const matrix33 &a, const matrix33 &b){
   return !(a == b ) ;
}
matrix33     operator - (const matrix33 &a){
    matrix33 c ;
    c.vx = -a.vx ;
    c.vy = -a.vy ;
    c.vz = -a.vz ;
    return c ;
}
matrix33      operator + (const matrix33 &a, const matrix33 &b){
    matrix33 c ;
    c.vx = a.vx + b.vx ;
    c.vy = a.vy + b.vy ;
    c.vz = a.vz + b.vz ;
    return c ;
}
matrix33       operator - (const matrix33 &a, const matrix33 &b){
    matrix33 c ;
    c.vx = a.vx - b.vx ;
    c.vy = a.vy - b.vy ;
    c.vz = a.vz - b.vz ;
    return c ;
}
matrix33       operator * (const matrix33 &m, float f){
    matrix33 c ;
    c.vx = m.vx * f ;
    c.vy = m.vy * f ;
    c.vz = m.vz * f ;
    return c ;
}
matrix33        operator * (float f, const matrix33 &m){
      matrix33 c ;
    c.vx = m.vz * f ;
    c.vy = m.vy * f ;
    c.vz = m.vz * f ;
    return c ;
}
matrix33        operator * (const matrix33 &a, const matrix33 &b){
    matrix33  c ;
    for(int i = 0 ; i < 3 ; i++)
        c.vx[i] = a.vx[i] * b.vx[0] + a.vy[i] * b.vx[1] + a.vz[i] * b.vx[2] ;
    for(int i = 0 ; i < 3 ; i ++)
        c.vy[i] = a.vx[i] * b.vy[0] + a.vy[i] * b.vy[1] + a.vz[i] * b.vy[2] ;
    for(int i = 0 ; i < 3 ; i++)
        c.vz[i] = a.vx[i] * b.vz[0] + a.vy[i] * b.vz[1] + a.vz[i] * b.vz[2] ;
    return c ;
}
matrix33        operator / (const matrix33 &m, float f){
    matrix33 c ;
    c.vx = m.vx / f ;
    c.vy = m.vy / f ;
    c.vz = m.vz / f ;
    return c ;
}
void matrix33::set(vector3 xIn, vector3 yIn, vector3 zIn){
    vx = xIn ;
    vy = yIn ;
    vz = zIn ;
}
 float matrix33::determinant() const{
    return vx[0]*vy[1]*vz[2] + vx[1]*vy[2]*vz[0] + vx[2]*vy[0]*vz[1] - vz[0]*vy[1]*vx[2] - vz[1]*vy[2]*vx[0] - vz[2]*vy[0]*vx[1] ;
 }
 void matrix33 ::printMatrix() const{
    for(int i = 0 ; i < 3 ;i++){
       std::cout << std::setw(4) << vx[i] << std::setw(4) << vy[i] << std::setw(4) << vz[i] << std::endl;
    }
 }
 matrix33 matrix33::identity(){
   for(int i = 0 ; i < 3 ; i++){
     vx[i] = 0 ,vy[i] = 0 ,vz[i] = 0 ;
     if( i == 0)
        vx[i] = 1 ;
     if( i == 1)
        vy[i] = 1 ;
     if(i == 2)
        vz[i] = 1 ;
   }
   return *this ;
}
matrix33 matrix33::invert(){
    matrix33 c;
    c[0][0] = vy[1]*vz[2] - vy[2]*vz[1] ;
    c[1][0] = -( vy[0]*vz[2] - vz[0]*vy[2] ) ;
    c[2][0] = vy[0]*vz[1] - vz[0]*vy[1] ;
    c[0][1] = -(vx[1]*vz[2]-vz[1]*vx[2]) ;
    c[1][1] = vx[0]*vz[2] - vz[0]*vx[2] ;
    c[2][1] = -(vx[0]*vz[1]-vz[0]*vx[1]) ;
    c[0][2] = vx[1]*vy[2] - vy[1]*vx[2] ;
    c[1][2] = -(vx[0]*vy[2] - vy[0]*vx[2]) ;
    c[2][2] = vx[0]*vy[1] - vy[0] * vx[1] ;
    return c / (*this).determinant() ;
}
