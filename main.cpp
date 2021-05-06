#include <iostream>
#include "TMember.h"
#include "TPoly.cpp"

using namespace Polynomial;
using namespace std;

int main()
{
    TPoly r1(1, 5);
    TPoly r2(2, 3);
    TPoly r3(3, 3);
    TPoly r4(4, 0);
    TPoly r5 = r3.add(r4);
    TPoly r6(0, 0);

    cout << "1: " << r1.to_string() << endl;
    cout << "2: " << r2.to_string() << endl;
    cout << "3: " << r3.to_string() << endl;
    cout << "4: " << r4.to_string() << endl;
    cout << "5: " << r5.to_string() << endl;

    //сложение
    cout << "==================Add==================" << endl;
    cout << r3.add(r4).to_string() << endl;
    cout << r2.add(r3).to_string() << endl;
    cout << r1.add(r5).to_string() << endl;
    cout << r4.add(r5).add(r2).to_string() << endl;
    cout << r6.add(r5).to_string() << endl;
    cout << r6.add(r6).to_string() << endl;

    //вычитание
    cout << "==================Substract==================" << endl;
    cout << r3.substract(r4).to_string() << endl;
    cout << r2.substract(r3).to_string() << endl;
    cout << r2.substract(r5).to_string() << endl;
    cout << r4.substract(r3).substract(r2).to_string() << endl;
    cout << r1.substract(r5).to_string() << endl;
    cout << r6.substract(r6).to_string() << endl;

    //умножение
    cout << "==================Multiply==================" << endl;
    cout << r3.add(r1).multiply(r5).to_string() << endl;
    cout << r2.multiply(r3).to_string() << endl;
    cout << r2.multiply(r5).to_string() << endl;
    cout << r6.multiply(r3).to_string() << endl;
    cout << r5.multiply(r5).to_string() << endl;
    cout << r6.multiply(r6).to_string() << endl;

    //минус
    cout << "==================Sign==================" << endl;
    cout << r2.ChangeSign().to_string() << endl;
    cout << r4.substract(r2).ChangeSign().to_string() << endl;
    cout << r6.ChangeSign().to_string() << endl;

    //дифференцирование
    cout << "==================df/dx==================" << endl;
    cout << r2.diff().to_string() << endl;
    cout << r5.diff().to_string() << endl;
    cout << r4.diff().to_string() << endl;

    //вычисление
    cout << "==================Calculate==================" << endl;
    cout << r2.calc(10) << endl;
    cout << r5.calc(0)  << endl;
    cout << r5.calc(2)  << endl;
    cout << r6.calc(2) << endl;
}
