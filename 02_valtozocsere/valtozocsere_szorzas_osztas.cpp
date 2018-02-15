#include <iostream>

using namespace std;

int main(){
    int x=10;
    int y=20;

    cout << x << " " << y << endl;

    x=y/x;
    y=y/x;
    x=y*x;

    cout << x << " " << y;

    return 0;
}
