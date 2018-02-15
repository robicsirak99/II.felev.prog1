#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

using namespace std;
//kirajzolja a labda feletti falakat �s a doboz tetej�t
void labdaElott(int y){
    for(int i=0; i<60; i++) printf("L"); printf("\n");
    for(int i=1; i<y; i++){
        printf("|"); for(int j=1; j<60; j++) printf(" "); printf("|\n");
    }
}
//kirajzolja a labdatol bal oldalan talalhato falat, a labdat es a labda jobb oldalan talalhato falait
void labdaSora(int x, int y){
    printf("|"); for(int i=1; i<x-1; i++) printf(" ");
    printf("O"); for(int i=x; i<60; i++) printf(" ");
    printf("|\n");
}
//kirajzolja a labda alatti falr�szeket es a doboz alj�t
void labdaUtan(int y) {
    for(int i=y-1; i<14; i++){
        printf("|"); for(int j=1; j<60; j++) printf(" "); printf("|\n");
    }
    for(int i=0; i<60; i++) printf("T");
}

int main(){
    int xSzorzo =1, ySzorzo=1;
    int x=2, y=2;
    int xTomb[60], yTomb[15];

    for(int i=1; i<60; i++) xTomb[i]=1;
    for(int i=1; i<15; i++) yTomb[i]=1;
    xTomb[1]=-1; xTomb[60]=-1;
    yTomb[1]=-1; yTomb[15]=-1;
    //a -1es �rt�ket a labda ir�nyv�lt�s�hoz kellenek

    for(;;){
        labdaElott(y); labdaSora(x,y); labdaUtan(y);
        //az x es y mondja meg hova legyen kirajzolva a labda
        x+=xSzorzo; y+=ySzorzo;
        //az x �s y folyamatosan n� am�g az egyik v�ltoz� el nem �ri a doboz egyik sz�l�t
        xSzorzo*=xTomb[x]; ySzorzo*=yTomb[y];
        //ha a labda a doboz sz�l�hez �r az x (vagy y) Szorzo a -1es �rt�ket veszi fel,
        //ennek k�sz�nhet�en az x (vagy y) �rt�ke cs�kkenni fog teh�t a labda "visszapattan"
        usleep(40000);
        system("cls");
    }
}
