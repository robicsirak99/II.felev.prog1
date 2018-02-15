#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

using namespace std;
//kirajzolja a labda feletti falakat és a doboz tetejét
void labdaElott(int y, int szel){
    for(int i=0; i<szel; i++) printf("L"); printf("\n");
    for(int i=1; i<y; i++){
        printf("|"); for(int j=1; j<szel; j++) printf(" "); printf("|\n");
    }
}
//kirajzolja a labdatol bal oldalan talalhato falat, a labdat es a labda jobb oldalan talalhato falait
void labdaSora(int x, int y, int szel){
    printf("|"); for(int i=1; i<x-1; i++) printf(" ");
    printf("O"); for(int i=x; i<szel; i++) printf(" ");
    printf("|\n");
}
//kirajzolja a labda alatti falrészeket es a doboz alját
void labdaUtan(int y, int szel, int mag) {
    for(int i=y-1; i<mag-1; i++){
        printf("|"); for(int j=1; j<szel; j++) printf(" "); printf("|\n");
    }
    for(int i=0; i<szel; i++) printf("T");
}

int main(){
    int szel,mag;
    int xSzorzo =1, ySzorzo=1;
    int x=2, y=2;

    printf("Add meg a doboz mereteit. (alapertelmezett meret: 60x15)\n");
    printf("Doboz szelessege:");cin>>szel;
    printf("Doboz magassaga:");cin>>mag;

    int xTomb[szel], yTomb[mag];

    for(int i=1; i<szel; i++) xTomb[i]=1;
    for(int i=1; i<mag; i++) yTomb[i]=1;
    xTomb[1]=-1; xTomb[szel]=-1;
    yTomb[1]=-1; yTomb[mag]=-1;
    //a -1es értéket a labda irányváltásához kellenek

    for(;;){
        labdaElott(y,szel); labdaSora(x,y,szel); labdaUtan(y,szel,mag);
        //az x es y mondja meg hova legyen kirajzolva a labda
        x+=xSzorzo; y+=ySzorzo;
        //az x és y folyamatosan nõ amíg az egyik változó el nem éri a doboz egyik szélét
        xSzorzo*=xTomb[x]; ySzorzo*=yTomb[y];
        //ha a labda a doboz széléhez ér az x (vagy y) Szorzo a -1es értéket veszi fel,
        //ennek köszönhetõen az x (vagy y) értéke csökkenni fog tehát a labda "visszapattan"
        usleep(40000);
        system("cls");
    }
}
