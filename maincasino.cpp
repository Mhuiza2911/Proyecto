#include <iostream>
#include "fcasino.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int opc,creditos=100;
string resp,res;

int main (){
    srand(time(NULL));
    do{
    mainmenu();
    cout<<"Para jugar se necesitan créditos, como eres nuevo ten 100 créditos\n"
    <<endl<<"Ahora tienes: "<<creditos<<" creditos"<<endl;
    cin>>opc;
    switch (opc){
        case 1:
        int dado1,dado2;
        do{
        int suma,apuesta,op;

        crapsmenu();
        
        do{
        cout<<"¿Cuanto quieres apostar?\n"<<"Solo puedes apostar de 5 creditos en adelante\n";
        cin>>apuesta;
        if (apuesta<5){
        cout<<"No puedes apostar menos de 5 creditos apuesta mas\n";
        }
        else if (creditos<apuesta){
        cout<<"No puedes apostar mas de los creditos de los que tienes\n";
        apuesta=1;
        }
        }while(apuesta<5);
        cout<<"¿Como quieres apostar?\n"<<"1- Si toca 7 en el primer tiro\n"<<"o\n"<<"2- Si te toca los mismos dados del primer tiro en el segundo antes que el 7  \n";
        cin>>op;
     switch (op){
        case 1:
         if(suma==7){
            cout<<"Ganaste, tus dados dieron: "<<fdado(dado1,dado2)<<endl;
            creditos=apuesta+creditos;
         }
         else {
            cout<<"Perdiste, tus dados dieron: "<<fdado(dado1,dado2)<<endl;
            creditos=creditos-apuesta;

         }
        break;
        case 2:
         int punto;
         suma=fdado(dado1,dado2);
         cout<<"Tu primer tiro es de: "<<suma<<endl; 
         if (suma==2||suma==3||suma==12){
            cout<<"Craps, perdiste tus dados fueron: "<<fdado(dado1,dado2)<<endl;
            creditos=creditos-apuesta;
            break;
         }
         else if(suma==7){
            cout<<"Perdiste, tu apuesta era que no tocara el 7";
            creditos-=apuesta;
            break;
         }
         punto=suma;
         cout<<"Tu punto es  "<<punto<<endl;
         while(true){
            suma=fdado(dado1,dado2);
            cout<<"Nuevo tiro: "<<suma<<endl;
         if(suma==punto){
            cout<<"Ganaste"<<endl;
            creditos=creditos+apuesta;
            break;
         }
         else if(suma==7) {
            cout<<"Perdiste"<<endl;
            creditos=creditos-apuesta;
            break;
         }
         break;
         default:
         cout<<"Introdujiste un numero incorrecto\n";
         break;
         }
         }
         cout<<"Tienes: "<<creditos<<" Creditos"<<endl;
         cout<<"Quieres volver a jugar?";
         cin>>resp;
         }while(resp=="si"||resp=="Si");
        break;
        case 2:
        do{
         char s1,s2,s3;
         int moneda;
        do{
        cout<<"Introduce una moneda\n"<<"Solo puedes meter monedas de 15 creditos \n";
        cin>>moneda;
        if (moneda<15){
        cout<<"No se admite esa cantidad\n";
        }
        else if (creditos<moneda){
        cout<<"No puedes apostar mas de los creditos de los que tienes\n";
        moneda=1;
        }
        }while(moneda!=15);
        s1=ftragap();
        s2=ftragap();
        s3=ftragap();
        cout<<"\n_____________\n"<<"| "<<s1<<" | "<<s2<<" | "<<s3<<" | \n"<<"-------------"<<endl<<endl;
        if (s1=='a'&&s2=='a'&&s3=='a'){
        cout<<" Ganaste\n";
        creditos+=900;
       }
        else if (s1=='b'&&s2=='b'&&s3=='b'){
        cout<<" Ganaste\n";
        creditos+=450;
       }
        else if (s1=='c'&&s2=='c'&&s3=='c'){
       cout<<" Ganaste\n";
       creditos+=150;
       }
       else if (s1=='a'&&s2=='a'&&s3=='b'||s1=='a'&&s2=='b'&&s3=='a'||s1=='b'&&s2=='a'&&s3=='a'){
       cout<<" Ganaste\n";
       creditos+=750;
       }
       else if (s1=='a'&&s2=='a'&&s3=='c'||s1=='a'&&s2=='c'&&s3=='a'||s1=='c'&&s2=='a'&&s3=='a'){
       cout<<" Ganaste\n";
       creditos+=650;
       }
       else if (s1=='b'&&s2=='b'&&s3=='a'||s1=='b'&&s2=='a'&&s3=='b'||s1=='a'&&s2=='b'&&s3=='b'){
       cout<<" Ganaste\n";
       creditos+=600;
       }
       else if (s1=='b'&&s2=='b'&&s3=='c'||s1=='b'&&s2=='c'&&s3=='b'||s1=='c'&&s2=='b'&&s3=='b'){
       cout<<" Ganaste\n";
       creditos+=350;
       }
       else if (s1=='c'&&s2=='c'&&s3=='a'||s1=='c'&&s2=='a'&&s3=='c'||s1=='a'&&s2=='c'&&s3=='c'){
       cout<<" Ganaste\n";
       creditos+=400;
       }
       else if (s1=='c'&&s2=='c'&&s3=='b'||s1=='c'&&s2=='b'&&s3=='c'||s1=='b'&&s2=='c'&&s3=='c'){
       cout<<" Ganaste\n";
       creditos+=250;
       }
       else {
       cout<<" perdiste\n";
       creditos-=15;
       }
       cout<<"Tienes: "<<creditos<<" Creditos"<<endl;
       cout<<"Quieres volver a jugar?";
       cin>>resp;
       }while(resp=="si"||resp=="Si");
        break;
        case 3:

        break;
        case 4:

        break;
        default:

        break;
    }
    cout<<"Quieres jugar otro juego?\n";
    cin>>res;
    }while(res=="si"||res=="Si"||res=="SI"||res=="sI");
    return 0;
}