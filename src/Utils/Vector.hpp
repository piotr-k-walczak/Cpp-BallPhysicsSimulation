//
//  Vector.hpp
//  SimplePhysicsEngine
//
//  Created by Piotr Walczak on 23/12/2020.
//

#ifndef Vector_hpp
#define Vector_hpp

struct Vector {

    Vector();

    Vector(Vector const &other);

    Vector(Vector &other);

    Vector(double x, double y, double z);

    friend Vector operator+(Vector mainVector, Vector &otherVector);

    friend Vector operator-(Vector mainVector, Vector &otherVector);

    friend Vector operator*(Vector mainVector, Vector &otherVector);

    friend Vector operator/(Vector mainVector, Vector &otherVector);

    friend Vector operator+(Vector mainVector, Vector &&otherVector);

    friend Vector operator-(Vector mainVector, Vector &&otherVector);

    friend Vector operator*(Vector mainVector, Vector &&otherVector);

    friend Vector operator/(Vector mainVector, Vector &&otherVector);

    friend Vector operator+(Vector mainVector, double multiplier);

    friend Vector operator-(Vector mainVector, double multiplier);

    friend Vector operator*(Vector mainVector, double multiplier);

    friend Vector operator/(Vector mainVector, double multiplier);

    Vector &operator+=(Vector &otherVector);

    Vector &operator+=(Vector &&otherVector);

    Vector &operator-=(Vector &otherVector);

    Vector &operator-=(Vector &&otherVector);

    Vector &operator*=(Vector &otherVector);

    Vector &operator*=(Vector &&otherVector);

    Vector &operator/=(Vector &otherVector);

    Vector &operator/=(Vector &&otherVector);

    Vector &operator+=(double multiplier);

    Vector &operator-=(double multiplier);

    Vector &operator*=(double multiplier);

    Vector &operator/=(double multiplier);

    double x;
    double y;
    double z;
};


#endif /* Vector_hpp */
