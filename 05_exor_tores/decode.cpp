#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//elvegzi az exor torest az adott kulcsra
string exorTores(string stext,  int text_size, string &key, int key_size){
    int key_index = 0;
    for (int i = 0; i < text_size; ++i){
        stext[i] = stext[i] ^ key[key_index];
        key_index = (key_index + 1) % key_size;
    }
    return stext;
}

//visszakuldi a szovegben szereplo tipikus magyar szavak szamat
int benneVan(string stext, int text_size){
    int i=0;
    int k=0;
    string word;
    while(i<=text_size){
        if(stext[i]!=' '){
            word=word+stext[i];
        }
        else{
            if ((word=="ha") || (word=="hogy") || (word=="az") || (word=="nem")) k++;
            word.clear();
        }
        i++;
    }
    return k;
}

//visszakuldi a szovegben szereplo szavak atlaghosszat
double atlagHossz(string stext, int text_size){
    int w=1;
    for(int i=0; i<text_size; i++){
        if(stext[i]==' '){
            w++;
        }
    }
    return text_size/w-1;
}

//igazat kuld vissza, ha a szavak atlaghossza es a szovegben szereplo tipikus magyar szavak szama megfelelo
bool tisztaLehet(string stext, int text_size){
    int benne=benneVan(stext,text_size);
    int atlagho=atlagHossz(stext,text_size);
    if ((atlagho>6) and (atlagho <9) and (benne>0)){
            return true;
    }
    else return false;
}

int main(){
    string key = "0000";
    string text,stext;
    char x;

//beolvassa a titkos szoveget a text valtozoba
    while(cin.get(x)){
	text+=x;
    }

    double atlagho;
    int benne;

    int text_size = text.size();
    int key_size = 4; 
    int key_index = 0;

//az osszes lehetseges kulcs legeneralasa
    for (int ii = 'a'; ii <= 'z'; ++ii)
        for (int ij = 'a'; ij <= 'z'; ++ij)
            for (int ik = 'a'; ik <= 'z'; ++ik)
                for (int il = 'a'; il <= 'z'; ++il){
                        key[0] = ii;
                        key[1] = ij;
                        key[2] = ik;
                        key[3] = il;
			
			//a plusz valtozo az eredeti szoveg megtartasa miatt kell
                        stext=text;
                        stext=exorTores(stext, text_size, key, key_size);

                        if (tisztaLehet(stext,text_size)){
                            cout << endl << "KULCS: " << key << endl;
                            cout << "TISZTA SZOVEG: " << endl << stext;
                        }
                    }
return 0;
}
