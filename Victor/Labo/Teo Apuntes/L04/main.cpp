#include <iostream>

using namespace std;

int main() {

    int x = 2;
    int y = 7;

    int* p = &x;
    *p = *p + 1;

    int& r = x;
    r = r + 1;

    p = &y;
    *p = *p + 1;

    r = y;

    cout << x << endl;
    cout << y << endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
