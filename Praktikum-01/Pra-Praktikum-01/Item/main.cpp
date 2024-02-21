// Soal 2 Pra-Praktikum

// #include "A.hpp"

// int main()
// {
//     A a('1');
//     A b('2');
//     A c(a);
//     c = b;
//     b.show();
//     return 0;
// }

// Soal 3

#include "Item.hpp"

#include <iostream>
using namespace std;

int main()
{
    Item A(4, 8);
    int num = A.getSerialNum();
    cout << num << endl;
    A.addStock(1);
    A.sell(4);
    int sold = A.getSold();
    cout << sold << endl;

    return 0;
}
