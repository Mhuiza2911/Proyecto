#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
// definir que varibles vamos a ocupar
char opc;


int main (){
    SetConsoleOutputCP (CP_UTF8);    
    cout<<"Bienvenido al Casino " ""<<"¿Que quieres hacer?\n"<<"Pulse D para jugar a los dados\n"<<"Pulse C para jugar a las cartas\n"<<"Pulse R para jugar a la ruleta\n"<<"Pulse T para jugar a la tragamonedas\n";
    cin>>opc;  
}