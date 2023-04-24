#include <iostream>
#include "vector.h"
int main() {
    Vector v1(5);
    Vector v2(5);
    for (int i = 0; i < v1.size(); ++i) {
        v1[i] = i;
        v2[i] = i * i;
    }

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    Vector v3 = v1 + v2;
    std::cout << "v3 = " << v3 << std::endl;

    Vector v4 = v1 + 10;
    std::cout << "v4 = " << v4 << std::endl;
    int a;
    VectorIterator it = v1.begin();
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
