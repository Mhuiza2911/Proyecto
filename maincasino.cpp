#include <iostream>
#include "fcasino.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;
string resp,res;
string op,usuar,contrasena;
      
        int leerCreditos,creditos=fReadCreditos (),opc,recargar=1000;
        char opcion;
struct user{
    
    string usuario;
    string contra;
};
int main (){
   SetConsoleOutputCP (CP_UTF8);
    srand(time(NULL));
    bool acceso = false;
    user u;
    do{
    cout<<"\nBienvenido usuario\n"
    <<"\nYa tiene cuenta?\n";
    cin>>op;
    if (op=="no"||op=="No"||op=="NO"||op=="nO"){
        cout<<"\nCreala\n";
        cout<<"Introduce un usuario: ";
        cin>> u.usuario;
        cout<<"Introduce una contraseña: ";
        cin>> u.contra;
      ofstream archivo;
      
      archivo.open("usuario.txt");

        if (archivo.is_open ()){
            archivo << u.usuario <<endl;
            archivo << u.contra <<endl;

            archivo.close();
            cout<<" Cuenta guardada";

        }
        else{
            cout<<"Error al abrir el archivo";
        }
    }
    else if (op=="si"||op=="Si"||op=="SI"||op=="sI"){
        ifstream archivo;
        archivo.open("usuario.txt");
        if(archivo.is_open()){
        archivo>>u.usuario;
        archivo>>u.contra;
        archivo.close();}
        else{
            cout<<"no se abrio\n";
        }
        for (int i=3; i>0; i--){
        cout<<"Introduce el usuario: ";
        cin>>usuar;
        cout<<"Introduce la contraseña: ";
        cin>>contrasena;
        if (usuar==u.usuario&&contrasena==u.contra){
            cout<<"Contraseña correcta";
            acceso=true;
            break;
        }
        else if (usuar!=u.usuario&&contrasena!=u.contra){
            cout<<"Contraseña incorrecta "<<"tienes "<<i<<" intentos"<<endl;
        }}
        if(!acceso){
        cout<<"Intentos acabado, sesion bloqueada";
        return 0;}
    }}while(!acceso);
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
        avisoCreditos ();
        }
        else if (creditos<apuesta){
                    cout<< "====================================" << endl
                        << "|     ERROR: Saldo insuficiente    |" << endl
                        << "====================================" << endl;
                }
        }while(apuesta<5);
        cout<<"¿Como quieres apostar?\n"<<"1- Si toca 7 en el primer tiro\n"<<"o\n"<<"2- Si te toca los mismos dados del primer tiro en el segundo antes que el 7  \n";
        cin>>op;
     switch (op){
        case 1:
        suma=fdado(dado1,dado2);
         if(suma==7){
            fganaste ();
            cout<<"tus dados dieron: "<<suma<<endl;
            creditos=apuesta+creditos;
            fTypeCreditos (creditos);
            
         }
         else {
            fperdiste();
            cout<<"tus dados dieron: "<<suma<<endl;
            creditos=creditos-apuesta;
            fTypeCreditos (creditos);
            

         }
        break;
        case 2:
         int punto;
         suma=fdado(dado1,dado2);
         cout<<"Tu primer tiro es de: "<<suma<<endl; 
         if (suma==2||suma==3||suma==12){
            cout<<"=================================" <<endl
                <<"|                               |" <<endl
                <<"|            Craps              |" <<endl
                <<"|        !! PERDISTE !!         |" <<endl
                <<"|                               |" <<endl
                <<"=================================" <<endl<<"Tus dados son: "<<fdado(dado1,dado2)<<endl;
            creditos=creditos-apuesta;
            fTypeCreditos (creditos);
            
            break;
         }
         else if(suma==7){
            fperdiste ();
            cout<<"tu apuesta era que no tocara el 7";
            creditos-=apuesta;
            fTypeCreditos (creditos);
            break;
         }
         punto=suma;
         cout<<"Tu punto es  "<<punto<<endl;
         while(true){
            suma=fdado(dado1,dado2);
            cout<<"Nuevo tiro: "<<suma<<endl;
         if(suma==punto){
            fganaste ();
            creditos=creditos+apuesta;
            fTypeCreditos (creditos);
            
            break;
         }
         else if(suma==7) {
            fperdiste ();
            creditos=creditos-apuesta;
            fTypeCreditos (creditos);
            
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
         tragamenu ();
         char s1,s2,s3;
         int moneda;
        do{
        cout<<"Introduce una moneda\n"<<"Solo puedes meter monedas de 15 creditos \n";
        cin>>moneda;
        if (moneda<15){
        cout<<"==============================================" <<endl
            <<"|                 IMPORTANTE                 |"   <<endl
            <<"|                                            |" <<endl
            <<"|      Recuerde que la cantidad son          |"  <<endl
            <<"|          monedade 15 creditos              |"  <<endl 
            <<"|                     !!!                    |" <<endl
            <<"==============================================" <<endl <<endl;
        }
        else if (creditos<moneda){
        cout<< "====================================" << endl
            << "|     ERROR: Saldo insuficiente    |" << endl
            << "====================================" << endl;
        moneda=1;
        }
        }while(moneda!=15);
        s1=ftragap();
        s2=ftragap();
        s3=ftragap();
        cout<<"\n_____________\n"<<"| "<<s1<<" | "<<s2<<" | "<<s3<<" | \n"<<"-------------"<<endl<<endl;
        if (s1=='a'&&s2=='a'&&s3=='a'){
        fganaste ();
        creditos+=900;
        fTypeCreditos (creditos);
       }
        else if (s1=='b'&&s2=='b'&&s3=='b'){
        fganaste ();
        creditos+=450;
        fTypeCreditos (creditos);
       }
        else if (s1=='c'&&s2=='c'&&s3=='c'){
       fganaste ();
       creditos+=150;
       fTypeCreditos (creditos);
       }
       else if (s1=='a'&&s2=='a'&&s3=='b'||s1=='a'&&s2=='b'&&s3=='a'||s1=='b'&&s2=='a'&&s3=='a'){
       fganaste ();
       creditos+=750;
       fTypeCreditos (creditos);
       }
       else if (s1=='a'&&s2=='a'&&s3=='c'||s1=='a'&&s2=='c'&&s3=='a'||s1=='c'&&s2=='a'&&s3=='a'){
       fganaste ();
       creditos+=650;
       fTypeCreditos (creditos);
       }
       else if (s1=='b'&&s2=='b'&&s3=='a'||s1=='b'&&s2=='a'&&s3=='b'||s1=='a'&&s2=='b'&&s3=='b'){
       fganaste ();
       creditos+=600;
       fTypeCreditos (creditos);
       }
       else if (s1=='b'&&s2=='b'&&s3=='c'||s1=='b'&&s2=='c'&&s3=='b'||s1=='c'&&s2=='b'&&s3=='b'){
       fganaste ();
       creditos+=350;
       fTypeCreditos (creditos);
       }
       else if (s1=='c'&&s2=='c'&&s3=='a'||s1=='c'&&s2=='a'&&s3=='c'||s1=='a'&&s2=='c'&&s3=='c'){
       fganaste ();
       creditos+=400;
       fTypeCreditos (creditos);
       }
       else if (s1=='c'&&s2=='c'&&s3=='b'||s1=='c'&&s2=='b'&&s3=='c'||s1=='b'&&s2=='c'&&s3=='c'){
       fganaste ();
       creditos+=250;
       fTypeCreditos (creditos);
       }
       else {
       fperdiste ();
       creditos-=15;
       fTypeCreditos (creditos);
       }
       cout<<"Tienes: "<<creditos<<" Creditos"<<endl;
       cout<<"Quieres volver a jugar?";
       cin>>resp;
       }while(resp=="si"||resp=="Si");
        break;
      case 3:{
            //Variables
       int numerosRojos [18] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35};
       int apuesta, color, numeroGanador;
       string colorGanador;
       menuRuleta ();
       


               
                  if (opcion == 's' || opcion == 'S' ){
                        avisoCreditos ();
                        cout<<"Ingrese la cantidad que desea apostar: ";
                        cin>>apuesta;

                           if (creditos<apuesta){
                              cout<< "====================================" << endl
                                    << "|     ERROR: Saldo insuficiente    |" << endl
                                    << "====================================" << endl;
                           }

                           else if (apuesta >= 5){
                              cout<<"Por que color apostaras?" <<endl
                                    <<"  0) Negro " <<endl
                                    <<"  1) Rojo " <<endl
                                    <<"Ingrese su eleccion: ";
                              cin>>color;

                              numeroGanador = rand() % 36;     //se utilizo IA en esta linea

                                          cout<<"====================================" <<endl
                                              <<"    El numero ganador es el "<<numeroGanador <<endl
                                              <<"====================================" <<endl; 

                                       if (numeroGanador==0){
                                          colorGanador = "Verde";
                                          cout<<"====================================" <<endl
                                                <<"|   El color ganador es el VERDE   |" <<endl
                                                <<"|         Hoy gano la casa         |" <<endl
                                                <<"|           PERDISTE :(            |" <<endl
                                                <<"====================================" <<endl;
                                          
                                          creditos = creditos - apuesta;
                                          fTypeCreditos (creditos);
                                          cout<<"Sus creditos totales son: " <<creditos <<endl;
                                       }
                                          //Este else fue generado por IA y sirve para recorrer todo el for hasta encontrar un rojo y terminarlo cuando lo encuentre
                                       else {
                                          colorGanador = "Negro";
                                          for (int i = 0; i < 18 ; i++){
                                                   if (numeroGanador == numerosRojos[i]){
                                                      colorGanador = "Rojo";
                                                      break;
                                                   }
                                          }
                                          cout<<"====================================" <<endl
                                              <<"    El color ganador es el "<<colorGanador <<endl
                                              <<"====================================" <<endl;   
                                       }

                                       if ((color == 0 && colorGanador == "Negro") || (color == 1 && colorGanador == "Rojo")){
                                          cout<<"=================================" <<endl
                                              <<"|                               |" <<endl
                                              <<"|         !! GANASTE !!         |" <<endl
                                              <<"|                               |" <<endl
                                              <<"=================================" <<endl;
                                          creditos = creditos + (apuesta*5);
                                          fTypeCreditos (creditos);
                                          cout<<"Sus creditos totales son: " <<creditos <<endl;
                                          
                                       }

                                       else{ 
                                          fperdiste ();
                                          creditos = creditos - apuesta;
                                          fTypeCreditos (creditos);
                                          cout<<"Sus creditos totales son: " <<creditos <<endl;
                                       
                                       }
                                       
                           }

                           
                  }
                  
                  fContinuar ();
                  cin>>opcion;

        break;}
        case 4:
        creditos=creditos+100;
        cout<<"Se te recargaron: "<<creditos<<" creditos"<<endl;
        break;
        default:
        cout<<"No te quieres hacer rico eh ._.";
        return 0;
        break;
    }
    cout<<"Quieres jugar otro juego?\n";
    cin>>res;
    }while(res=="si"||res=="Si"||res=="SI"||res=="sI");
    return 0;
}