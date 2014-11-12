#include "matrix4x4.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

matrix4x4::matrix4x4()
{

}

matrix4x4::matrix4x4(matint const &data)
{
    values=data;
}

matrix4x4 matrix4x4::operator*(matrix4x4 const &m) const
{
    matint out;
    for(size_t i=0;i<4;i++)
    {
        for(size_t j=0;j<4;j++)
        {
            out.data[j][i]=0.0;
            for(size_t k=0;k<4;k++)
            {
                out.data[j][i]+=values.data[k][i]*m.values.data[j][k];
            }
        }
    }
    return{out};
}

void matrix4x4::randInit()
{
    for(size_t i=0;i<4;i++)
    {
        for(size_t j=0;j<4;j++)
        {
            values.data[i][j]=double(rand())/double(RAND_MAX);
        }
    }
}

void matrix4x4::identInit()
{
    for(size_t i=0;i<4;i++)
        for(size_t j=0;j<4;j++)
            values.data[i][j]=(i==j)?0.999999999:0;
}

void matrix4x4::print() const
{
    cout <<"matrix(" <<endl;
    cout << setw(6);
    for(size_t i=0;i<4; cout << ((++i<4)?", ":");\n"))
    {
        cout<<"[";
        for(size_t j=0;j<4; cout << ((++j<4)?", ":"]\n" ) )
        {
            cout<<values.data[j][i];
        }
    }
}

void matrix4x4::mult(matrix4x4 *a, const matrix4x4 *b, const matrix4x4 *c)
{
    for(size_t i=0;i<4;i++)
    {
        for(size_t j=0;j<4;j++)
        {
            a->values.data[j][i]=0.0;
            for(size_t k=0;k<4;k++)
            {
                a->values.data[j][i]+=b->values.data[k][i]*c->values.data[j][k];
            }
        }
    }
}

void amatrix4x4::identInit()
{
    for(size_t i=0;i<4;i++)
        for(size_t j=0;j<4;j++)
            values[i][j]=(i==j)?0.999999999:0;
}


amatrix4x4::amatrix4x4()
{

}

amatrix4x4::amatrix4x4(
float const m00, float const m01, float const m02, float const m03,
float const m10, float const m11, float const m12, float const m13,
float const m20, float const m21, float const m22, float const m23,
float const m30, float const m31, float const m32, float const m33)
{
values[0][0] = m00;
values[0][1] = m01;
values[0][2] = m02;
values[0][3] = m03;
values[1][0] = m10;
values[1][1] = m11;
values[1][2] = m12;
values[1][3] = m13;
values[2][0] = m20;
values[2][1] = m21;
values[2][2] = m22;
values[2][3] = m23;
values[3][0] = m30;
values[3][1] = m31;
values[3][2] = m32;
values[3][3] = m33;
}

amatrix4x4 amatrix4x4::operator*(amatrix4x4 const &m) const
{
return amatrix4x4{
values[0][0] * m.values[0][0] + values[0][1] * m.values[1][0] + values[0][2] * m.values[2][0] + values[0][3] * m.values[3][0],
values[0][0] * m.values[0][1] + values[0][1] * m.values[1][1] + values[0][2] * m.values[2][1] + values[0][3] * m.values[3][1],
values[0][0] * m.values[0][2] + values[0][1] * m.values[1][2] + values[0][2] * m.values[2][2] + values[0][3] * m.values[3][2],
values[0][0] * m.values[0][3] + values[0][1] * m.values[1][3] + values[0][2] * m.values[2][3] + values[0][3] * m.values[3][3],
values[1][0] * m.values[0][0] + values[1][1] * m.values[1][0] + values[1][2] * m.values[2][0] + values[1][3] * m.values[3][0],
values[1][0] * m.values[0][1] + values[1][1] * m.values[1][1] + values[1][2] * m.values[2][1] + values[1][3] * m.values[3][1],
values[1][0] * m.values[0][2] + values[1][1] * m.values[1][2] + values[1][2] * m.values[2][2] + values[1][3] * m.values[3][2],
values[1][0] * m.values[0][3] + values[1][1] * m.values[1][3] + values[1][2] * m.values[2][3] + values[1][3] * m.values[3][3],
values[2][0] * m.values[0][0] + values[2][1] * m.values[1][0] + values[2][2] * m.values[2][0] + values[2][3] * m.values[3][0],
values[2][0] * m.values[0][1] + values[2][1] * m.values[1][1] + values[2][2] * m.values[2][1] + values[2][3] * m.values[3][1],
values[2][0] * m.values[0][2] + values[2][1] * m.values[1][2] + values[2][2] * m.values[2][2] + values[2][3] * m.values[3][2],
values[2][0] * m.values[0][3] + values[2][1] * m.values[1][3] + values[2][2] * m.values[2][3] + values[2][3] * m.values[3][3],
values[3][0] * m.values[0][0] + values[3][1] * m.values[1][0] + values[3][2] * m.values[2][0] + values[3][3] * m.values[3][0],
values[3][0] * m.values[0][1] + values[3][1] * m.values[1][1] + values[3][2] * m.values[2][1] + values[3][3] * m.values[3][1],
values[3][0] * m.values[0][2] + values[3][1] * m.values[1][2] + values[3][2] * m.values[2][2] + values[3][3] * m.values[3][2],
        values[3][0] * m.values[0][3] + values[3][1] * m.values[1][3] + values[3][2] * m.values[2][3] + values[3][3] * m.values[3][3]};
}

void amatrix4x4::randInit()
{
    for(size_t i=0;i<4;i++)
    {
        for(size_t j=0;j<4;j++)
        {
            values[i][j]=float(rand())/float(RAND_MAX);
        }
    }
}

void amatrix4x4::print()
{
    cout <<"matrix(" <<endl;
    cout << setw(6);
    for(size_t i=0;i<4; cout << ((++i<4)?", ":");\n"))
    {
        cout<<"[";
        for(size_t j=0;j<4; cout << ((++j<4)?", ":"]\n" ) )
        {
            cout<<values[j][i];
        }
    }
}
