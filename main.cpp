#include <chrono>
#include <iostream>
#include <matrix4x4.h>


#define itemCount (20000000)

using namespace std;
using namespace std::chrono;

void testMy()
{
    srand(0);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    matrix4x4* out=new matrix4x4[itemCount];
    matrix4x4 a;
    out[0].randInit();
    a.identInit();
    for(size_t i=1;i<itemCount;i++)
    {
        out[i]=a*out[i-1];
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout<< duration <<std::endl;
    out[itemCount-1].print();
    delete[] out;
}


void testAuthor()
{
    srand(0);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    amatrix4x4 a;
    amatrix4x4* out=new amatrix4x4[itemCount];
    out[0].randInit();
    a.identInit();
    for(size_t i=1;i<itemCount;i++)
    {
        out[i]=a*out[i-1];
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout<< duration <<std::endl;
    out[itemCount-1].print();
    delete[] out;
}

int main()
{    
    testMy();
    testAuthor();
    return 0;
}

