#include <iostream>
#include <unistd.h>

using namespace std;

int main(int args, char *argv[]){
    string key = argv[1];				
    int key_index = 0;
    char x;

    while(cin.get(x)){				
       	x = x ^ key[key_index];			
	key_index = (key_index + 1) % key.length();
	cout << x;
	}	

    return 0;
}
