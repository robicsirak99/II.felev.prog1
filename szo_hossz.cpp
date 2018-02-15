#include <iostream>

using namespace std;

int main(){
    int x=10, k=0;
    while(x){
        x=x<<1;
        k++;
    }
    cout<<k;
    return 0;
}
