#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

//Definimos el nodo
struct datos{
int num;
struct datos *sig;
};

struct datos *p, *pila=NULL, *esp, *pilaTwo=NULL;

//Definimos los prototipos de funciones
//struct esp *nodo_nuevo();
struct datos *nuevo_nodo();
void error();
void push();
void push2();
int pilaVacia();
void mostrarPila();
void mostrarNewPila();

int main()
{
    char op;

    do{
        system("cls");
        cout << "\n\n\t\tTrabajando con pilas!" << endl;
        cout << "\n\n\t\t_____________________" << endl;
        cout << "\n\n\t 1. Insertar nodo (push)" << endl;
        cout << "\n\n\t 2. Trasladar ultimo nodo a nueva pila (push)" << endl;
        cout << "\n\n\t 3. Salir" << endl;
        do{
            cout<<"\n\t\tIngrese una opcion [1-3]: ";
            op=getche();//recibe inforamción directo del teclado
        }while(op<'1'||op>'3');
        switch(op){
            case '1':
                push();
                break;
            case '2':
                push2();
                break;
        }
    }while(op!='3');
    //-> sirve para acceder a los miembros de la estructura mediante punteros.
    cout<<"\n\n\t\tSaliendo.."<<endl;
    getch();
    return 0;
}

//Implementar funciones

void error(){
    perror ("\n\n\t\t Memorira no reservada");
    getch();
    exit(1);
}
struct datos *nuevo_nodo(){
    struct datos *pl;
    pl = new struct datos;
    if(!pl)
        error();
    return pl;
};

void push(){
   int n;
   char fin;
   do{
       system ("cls");
       cout<<"\n\t Ingresar datos a la pila..";
       mostrarPila();
       cout<<"\n\t Ingrese un numero: ";
       cin>>n;
       p = new struct datos;
       p->num = n;
       p->sig = pila;
       pila = p;
       cout<<"\n\t\t Desea seguir ingresando mas datos? (S/N]: ";
       fin = toupper (getche());
   }while (fin == 'S');
}

int pilaVacia()
{
    return (pila == NULL);
}
int pilaTwoVoid(){
    return (pilaTwo==NULL);
}
void mostrarNewPila(){
    esp = pilaTwo;
    if(pilaTwoVoid())
       cout<<"\n\n\t Pila Vacia.."<<endl;
    else
    {
       cout<<endl;
       while(esp)
       {
         cout<<"\t\t\t "<<esp->num<<endl;
         esp = esp->sig;
       }
       cout<<endl;
   }
}
void mostrarPila(){
   p = pila;
   if(pilaVacia())
       cout<<"\n\n\t Pila Vacia.."<<endl;
   else
   {
      cout<<endl;
      while(p)
      {
         cout<<"\t\t\t "<<p->num<<endl;
         p = p->sig;
      }
      cout<<endl;
   }
}

void push2(){

    struct datos *aux;
    aux=pila;
    system ("cls");
    cout<<"\n\n\t Desapilando y apilando nuevamente..";
    mostrarPila ();
    pila = aux->sig;
    datos *esp = new datos();
    esp->num = aux->num;
    esp->sig = pilaTwo;
    pilaTwo=esp;

    cout<<"\n\n\t Elemento desapilado: "<<esp->num<<endl;
    cout<<"\n\n\t Nueva pila: "<<endl;
    mostrarNewPila();
    getch ();
}
