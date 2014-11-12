#ifndef MATRIX4X4_H
#define MATRIX4X4_H

struct matint
{
    float data[4][4];
};

class matrix4x4 final
{
public:
    matrix4x4();
    matrix4x4(matint const& data);
    matrix4x4 operator*(matrix4x4 const& m) const;
    void randInit();
    void identInit();
    void print() const;
    static void mult(matrix4x4 *a, const matrix4x4 *b, const matrix4x4 *c);
private:
    matint values;

};


class amatrix4x4 final
{
public:
    float values[4][4];
    amatrix4x4();
    amatrix4x4(
    float const m00, float const m01, float const m02, float const m03,
    float const m10, float const m11, float const m12, float const m13,
    float const m20, float const m21, float const m22, float const m23,
    float const m30, float const m31, float const m32, float const m33);
    amatrix4x4 operator*(amatrix4x4 const& m) const;
    void randInit();
    void print();
    void identInit();
};

#endif // MATRIX4X4_H
