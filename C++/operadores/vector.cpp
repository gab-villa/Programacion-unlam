#include "vector.h"
Vector::Vector(const Vector& vec){
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

Vector::Vector(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}
Vector Vector::operator+(const Vector &v)
{
    return Vector(x + v.x , y + v.y , z + v.z);
}
Vector Vector::operator*(const Vector &v)
{
    return Vector(x*v.x , y*v.y , z*v.z);
}
void mostrarVector(const Vector &v){
    cout <<"("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
}
Vector operator++(){
    return Vec(Vec.x++, Vec.y++, Vec.z++);
}
