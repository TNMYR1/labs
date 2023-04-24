#include "Vector.h"
#include "time.h"
#include <iostream>
#include <random>
int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 23);
    std::uniform_int_distribution<> raz(0, 59);
    Vector<int> v1(5);
    Vector<double> v2(5);

    for (int i = 0; i < v1.size(); ++i) {
        v1[i] = i + 1;
        v2[i] = (i + 1) * 1.5;

    }
    Vector<Time> v5(5);
    for (int i = 0; i < v5.size(); ++i) {
        v5[i].set_min(dis(gen));
        v5[i].set_sec(raz(gen));
    }
    Vector<Time> v6(5);
    for (int i = 0; i < v6.size(); ++i) {
        v6[i].set_min(dis(gen));
        v6[i].set_sec(raz(gen));
    }
    std::cout << "v5 = " << v5 << std::endl;
    std::cout << "v6 = " << v6 << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    Vector<Time> v3 = v5 + v6;
    std::cout << "v3 = " << v3 << std::endl;
    Vector<int> v7 = v1 + v1;
    std::cout << "v7 = " << v7 << std::endl;
    Time b;
    b.set_min(dis(gen));
    b.set_sec(raz(gen));
    std::cout << b << std::endl;
    Vector<Time> v4 = v3 + b;
    std::cout << "v4 = " << v4 << std::endl;
    Vector<int> v8 = v7 + 10;
    std::cout << "v8 = " << v8 << std::endl;
    int a;
    VectorIterator<int> it = v1.begin();
    a = *it;
    std::cout << "v1 before increment: " << a << std::endl;
    ++it;
    a = *it;
    std::cout << "v1 after increment: " << a << std::endl;
    --it;
    a = *it;
    std::cout << "v1 after decrement: " << a << std::endl;
    system("pause");
    return 0;
}