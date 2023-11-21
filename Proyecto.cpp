/*Proyecto 3:

Se quiere crear un programa que tenga como objetivo el manejo de reservas de un avión. Este avión
cuenta con un número fijo de 50 sillas. De ellas, 8 son de case ejecutiva, mientras que el resto son de clase
económica. Cada silla puede ser asignada a un pasajero que cuenta con un nombre y una cédula. Este
último dato es la entrada principal para poder consultar una reserva o eliminarla del sistema.

Cuando se asigna una silla es necesario conocer las preferencias del usuario, Este puede elegir la posición
de la silla, ventana, pasillo o centro, y la clase, ejecutiva o económica. En e caso especial de las sillas
ejecutivas, solo es posible elegir las posiciones: ventana o pasillo, Las sillas son asignadas de forma
secuencial según su ubicación y su clase. De igual forma, el programa permite buscar la reserva de un
pasajero y visualizarlos datos de la reserva

El programa debe permitir al usuario:

Asignar una silla a un pasajero
Consultar una reserva
Eliminar reserva
Buscar pasajero
Calcular el porcentaje de ocupación del avión.
Consultar el valor total de ventas por concepto de sillas ocupadas en el avión.
Consultar el valor promedio de venta por concepto de sillas ocupadas/pasajero en el avión.
*/
#include <iostream>

using namespace std;

int cntEj=0;
int cntEc=8;
bool sillas [50];
string posicion [50];
long cedula[50];
string nombre[50];

int obtenerLugar(long c);
int proximaPos(int i, string pos);
int buscarLugar(string n);
int ocupacion();
int ocupacionEj();
int ocupacionEc();
void menu();
void iniciarAsientos();
bool comprobarValido(long c);


int main(){
    iniciarAsientos();
    menu();
}

int obtenerLugar(long c){
    for(int i=0; i<50; i++){
        if(cedula[i]==c && sillas[i]){
            return i;
        }
    }
    return 50;
}
int proximaPos(int i, string pos){
    if(i==1){
        for(int j=0; j<8; j++){
            if(pos==posicion[j] && sillas[j]==false){
                return j;
            }
        }
    }
    else if(i==2){
        for(int j=8; j<50; j++){
            if(pos==posicion[j] && sillas[j]==false){
                return j;
            }
        }
    }
    return 50;
}
int buscarLugar(string n){
    for(int i=0; i<50; i++){
        if(nombre[i]==n && sillas[i]){
            return i;
        }
    }
    return 50;
}
int ocupacion(){
    int cnt=0;
    for(int i=0; i<50; i++){
        if(sillas[i]){
            cnt++;
        }
    }
    return cnt;
}
int ocupacionEj(){
    int cnt=0;
    for(int i=0; i<8; i++){
        if(sillas[i]){
            cnt++;
        }
    }
    return cnt;
}
int ocupacionEc(){
    int cnt=0;
    for(int i=8; i<50; i++){
        if(sillas[i]){
            cnt++;
        }
    }
    return cnt;
}
void menu(){
    int opc=0;
    int opc2=0;
    long c=0;
    string n="";

    while(opc<1 || opc>8){
        cout<<endl<<"Digite una opcion: "<<endl<<
        "1. Asignar una silla a un pasajero"<<endl<<
        "2. Consultar una reserva"<<endl<<
        "3. Eliminar reserva"<<endl<<
        "4. Buscar Pasajero"<<endl<<
        "5. Calcular el porcentaje de ocupacion del avion."<<endl<<
        "6. Consultar el valor total de ventas por concepto de sillas ocupadas en el avion."<<endl<<
        "7. Consultar el valor promedio de venta por concepto de sillas ocupadas/pasajero en el avion."<<endl<<
        "8. Salir"<<endl;
        cin>>opc;
    }
    cout<<endl;
    switch(opc){
        case 1: {opc=0;
                while(opc<1 || opc>2){
                    cout<<"Que clase tiene el pasajero?: \n"<<
                    "1.Ejecutiva\n"<<
                    "2.Economica\n";
                    cin>>opc;
                }
                if(opc==1){
                    while(opc2<1 || opc2>2){
                        cout<<"Que posicion ocupa el pasajero: \n"<<
                        "1. Ventana\n"<<
                        "2. Pasillo\n";
                        cin>>opc2;
                    }
                    int s=0;
                    if(opc2==1){
                        s=proximaPos(opc, "Ventana");
                    }
                    else{
                        s=proximaPos(opc, "Pasillo");
                    }
                    if(s==50){
                        cout<<"Error, no hay posiciones disponibles con dichas caracteristicas!"<<endl;
                    }
                    else{
                        cout<<"Digite la cedula del pasajero: ";
                        cin>>c;
                        if(comprobarValido(c)){
                            sillas[s]=true;
                            cout<<"Digite el nombre del pasajero: ";
                            cin>>nombre[s];
                            cedula[s]=c;
                        }
                        else{
                            cout<<"Error, esa cedula ya esta registrada!"<<endl;
                        }

                    }
                }
                else if(opc==2){
                    while(opc2<1 || opc2>3){
                        cout<<"Que posicion ocupa el pasajero: \n"<<
                        "1. Ventana\n"<<
                        "2. Centro\n"<<
                        "3. Pasillo\n";
                        cin>>opc2;
                    }
                    int s=0;
                    if(opc2==1){
                        s=proximaPos(opc, "Ventana");
                    }
                    else if(opc2==2){
                        s=proximaPos(opc, "Centro");
                    }
                    else{
                        s=proximaPos(opc, "Pasillo");
                    }
                    if(s==50){
                        cout<<"Error, no hay posiciones disponibles con dichas caracteristicas!"<<endl;
                    }
                    else{
                        cout<<"Digite la cedula del pasajero: ";
                        cin>>c;
                        if(comprobarValido(c)){
                            sillas[s]=true;
                            cout<<"Digite el nombre del pasajero: ";
                            cin>>nombre[s];
                            cedula[s]=c;
                        }
                        else{
                            cout<<"Error, esa cedula ya esta registrada!"<<endl;
                        }

                    }
                }
                break;}
        case 2: {cout<<"Digite la cedula del pasajero para consultar la reserva: ";
                cin>>c;
                if(obtenerLugar(c)>=50){
                    cout<<"Error, esa cedula no esta registrada! ";
                }
                else{
                    int space=obtenerLugar(c);
                    if(c<8){
                        cout<<"Clase: Ejecutiva";
                    }
                    else{
                        cout<<"Clase: Economica";
                    }
                    cout<<endl<<"Silla: "<<space+1<<"\nPosicion: "<<posicion[space]<<"\nCedula: "<<cedula[space]<<"\nNombre: "<<nombre[space]<<endl;
                }
                break;}
        case 3: {cout<<"Digite la cedula del pasajero para eliminar la reserva: ";
                cin>>c;
                if(obtenerLugar(c)>=50){
                    cout<<"Error, esa cedula no esta registrada! ";
                }
                else{
                    int space=obtenerLugar(c);
                    sillas[space]=false;
                }
                break;}
        case 4: {cout<<"Digite El nombre del pasajero a buscar: ";
                cin>>n;
                int s=buscarLugar(n);
                if(s>=50){
                    cout<<"Error, esa cedula no esta registrada! ";
                }
                else{
                    if(s<8){
                        cout<<"Clase: Ejecutiva";
                    }
                    else{
                        cout<<"Clase: Economica";
                    }
                    cout<<endl<<"Silla: "<<s+1<<"\nPosicion: "<<posicion[s]<<"\nCedula: "<<cedula[s]<<"\nNombre: "<<nombre[s]<<endl;
                }
                break;}
        case 5: {double ocuped=(ocupacion()*100)/50;
                cout<<"El porcentaje de ocupacion actual del avion es: "<<ocuped<<"%\n";
                break;}
        case 6: {int ejP;
                int ecP;
                cout<<"Digite el precio de un lugar ejecutivo: ";
                cin>>ejP;
                cout<<"Digite el precio de un lugar economico: ";
                cin>>ecP;
                int total=(ejP*ocupacionEj())+(ecP*ocupacionEc());
                cout<<"El valor total de ventas por concepto de sillas ocupadas en el avion es: "<<total<<endl;
                break;}
        case 7: {int ejP;
                int ecP;
                cout<<"Digite el precio de un lugar ejecutivo: ";
                cin>>ejP;
                cout<<"Digite el precio de un lugar economico: ";
                cin>>ecP;
                int total=(ejP*ocupacionEj())+(ecP*ocupacionEc());
                cout<<"El valor promedio de venta por concepto de sillas ocupadas/pasajero en el avion es: "<<total/ocupacion()<<endl;
                break;}
        case 8: {exit(-1);
                break;}
    }
    menu();
}
void iniciarAsientos(){
    int assign=1;
    for(int i=0; i<50; i++){
        if(i<8){
            if(assign==1){
                posicion[i]="Ventana";
                assign++;
            }
            else{
                posicion[i]="Pasillo";
                assign=1;
            }
        }
        else{
            if(assign==1){
                posicion[i]="Ventana";
                assign++;
            }
            else if(assign==2){
                posicion[i]="Centro";
                assign++;
            }
            else{
                posicion[i]="Pasillo";
                assign=1;
            }
        }
    }
}
bool comprobarValido(long c){
    for(int i=0; i<50; i++){
        if(c==cedula[i] && sillas[i]){
            return false;
        }
    }
    return true;
}
