//
//  Vector.cpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#include "Vector.hpp"

Vector::Vector() : Vector(0, 0, 0) {}

Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(Vector &other) : Vector(other.x, other.y, other.z) {}

Vector::Vector(Vector const &other) : Vector(other.x, other.y, other.z) {}

Vector &Vector::operator+=(Vector &otherVector)
{
    x += otherVector.x;
    y += otherVector.y;
    z += otherVector.z;
    return *this;
}

Vector &Vector::operator+=(Vector &&otherVector)
{
    *this += otherVector;
    return *this;
}

Vector &Vector::operator-=(Vector &otherVector)
{
    x -= otherVector.x;
    y -= otherVector.y;
    z -= otherVector.z;
    return *this;
}

Vector &Vector::operator-=(Vector &&otherVector)
{
    *this -= otherVector;
    return *this;
}

Vector &Vector::operator*=(Vector &otherVector)
{
    x *= otherVector.x;
    y *= otherVector.y;
    z *= otherVector.z;
    return *this;
}

Vector &Vector::operator*=(Vector &&otherVector)
{
    *this *= otherVector;
    return *this;
}

Vector &Vector::operator/=(Vector &otherVector)
{
    x /= otherVector.x;
    y /= otherVector.y;
    z /= otherVector.z;
    return *this;
}

Vector &Vector::operator/=(Vector &&otherVector)
{
    *this /= otherVector;
    return *this;
}

Vector &Vector::operator+=(double multiplier)
{
    x += multiplier;
    y += multiplier;
    z += multiplier;
    return *this;
}

Vector &Vector::operator-=(double multiplier)
{
    x -= multiplier;
    y -= multiplier;
    z -= multiplier;
    return *this;
}

Vector &Vector::operator*=(double multiplier)
{
    x *= multiplier;
    y *= multiplier;
    z *= multiplier;
    return *this;
}

Vector &Vector::operator/=(double multiplier)
{
    x /= multiplier;
    y /= multiplier;
    z /= multiplier;
    return *this;
}

Vector operator+(Vector mainVector, Vector &otherVector)
{
    mainVector += otherVector;
    return mainVector;
}

Vector operator-(Vector mainVector, Vector &otherVector)
{
    mainVector -= otherVector;
    return mainVector;
}

Vector operator*(Vector mainVector, Vector &otherVector)
{
    mainVector *= otherVector;
    return mainVector;
}

Vector operator/(Vector mainVector, Vector &otherVector)
{
    mainVector /= otherVector;
    return mainVector;
}

Vector operator+(Vector mainVector, double multiplier)
{
    mainVector += multiplier;
    return mainVector;
}

Vector operator-(Vector mainVector, double multiplier)
{
    mainVector -= multiplier;
    return mainVector;
}

Vector operator*(Vector mainVector, double multiplier)
{
    mainVector *= multiplier;
    return mainVector;
}

Vector operator/(Vector mainVector, double multiplier)
{
    mainVector /= multiplier;
    return mainVector;
}

Vector operator+(Vector mainVector, Vector &&otherVector)
{
    mainVector += otherVector;
    return mainVector;
}

Vector operator-(Vector mainVector, Vector &&otherVector)
{
    mainVector -= otherVector;
    return mainVector;
}

Vector operator*(Vector mainVector, Vector &&otherVector)
{
    mainVector *= otherVector;
    return mainVector;
}

Vector operator/(Vector mainVector, Vector &&otherVector)
{
    mainVector /= otherVector;
    return mainVector;
}
