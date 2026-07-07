#include <iostream>
#include "fcasino.h"
using namespace std;

void mainmenu (){
    cout<<"\n-------------------------------------------\n"<<"|           Bienvenido al UCAsino         |\n"<<"-------------------------------------------";
    cout<<endl<<" ___________________________\n"<<"/ Pulsa 1 Para jugar Craps /\n"<<"---------------------------\n"
    <<" ______________________________________________\n"<<"/ Pulsa 2 Para juagar a la maquinatragaperras /\n"<<"----------------------------------------------\n"
    <<" _________________________________\n"<<"/ Pulsa 3 Para jugar a la ruleta /\n"<<"---------------------------------\n"
    <<" _________________________________\n"<<"/ Pulsa 4 Para recargar creditos /\n"<<"---------------------------------\n" 
    <<" _____________________________\n"<<"/ Pulsa 5 Cerrar el programa /\n"<<"-----------------------------\n"
    << "\nDisclaimer: Si no quieres ganar dinero, por favor cierra este programa YAAAAA!\n";
}
void crapsmenu (){
    cout<<"______________________\n"<<"| Bienvenido a Craps |\n"<<"----------------------\n"
    <<"Antes de empezar, te resumire las reglas\n"<<"1- Vas de decidir como apostaras\n"<<"2- Decidiras cuanto apostaras\n"
    <<"3- Dependiendo de que decidiste o ganas apostando que tus dados dan 7 o 11, o ganas apostando que tus siguientes tiradas,\n"<<"luego de la primera den la misma cantidad de la primera antes que toque 7,\n"<<"pero si en la primera tira da 7, 11, 2, 3 o 12 pierdes\n"
    <<"\nEMPECEMOS!!!!!!!!\n"; 
}
void tragamenu (){
    cout<<"________________________________________\n"<<"| Bienvenido a la maquina tragamonedas |\n"<<"----------------------------------------\n"
    <<"";
}
int fdado (int a, int b){
    a=rand() %6+1;
    b=rand() %6+1;
    return a+b;
}
//ia 
char ftragap (){
    return 'a'+ rand()%3;
}

