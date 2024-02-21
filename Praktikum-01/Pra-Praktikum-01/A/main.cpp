#include "A.hpp"

int main()
{
    A a('1');
    A b('2');
    A c(a);
    c = b;
    b.show();
    return 0;
}