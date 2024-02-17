#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "gym.h"
using namespace std;


gym gymC[200];
int tam_obj;
int buscar_username(string unom)
{
	int i;
	for(i=0;i<tam_obj;i++)
		{
			if(gymC[i].get_nombre().compare(unom)==0)
			{
				return i;
			}
		}
		
	return -1;
}

bool comparar_password(string pass1, string pass2)
{
	if(pass1.compare(pass2)==0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void alta_cliente(){
	int i,posicion, j;
	char opc;
	string nombreu,nom,unom,pass,texto,password;
	ofstream cuenta,archivo,entren;
	string nombre,apellido,nombre_e,apellido_e;
	float membre;
	int id, c,edad;
	system("color 30");
	system("cls");
	cout<<" _____________________"<<endl;
	cout<<"| Agregar   Cliente   |"<<endl;
	cout<<"|_____________________|"<<endl;
	cout<<"Nombre: "; 		cin>>nombre;
	cout<<"Apellido: "; 		cin>>apellido;
	cout<<"Nombre Entrenador: "; 		cin>>nombre_e;
	cout<<"Apellido Entrenador: "; 		cin>>apellido_e;
	cout<<"Membresia(si no debe poner 0): "; 		cin>>membre;
	cout<<"Edad: "; 		cin>>edad;
	cout<<"Password: "; 		cin>>password;
	cout<<"Bienvenido "<< nombre << " a GYM BRO"<<endl;

	archivo.open("ClienteGym.txt",ios::out|ios::app);
	if(archivo.fail())
	{
		cout<<"No se pudo abrir el archivo"<<endl;
	}
	
    cuenta.open("iniciosesion.txt",ios::out|ios::app);
	if(cuenta.fail())
	{
		cout<<"No se pudo abrir el archivo"<<endl;
	}
    srand(time(NULL));
    cout<<"Tu numero de cliente es: ";
    for(c = 1; c <= 5; c++)
    {
        id = 1 + rand() % (10-1);
        cout<<id;
        cuenta<<id;	
        archivo<<id; 
    }
    cout<<endl;
   		system("pause");
		system("cls");
	cuenta<<" "<<password<<endl;
	 cuenta.close();
	
	archivo<<" "<<nombre<<" "<<apellido<<" "<<nombre_e<<" "<<apellido_e<<" "<<membre<<" "<<edad<<" "<<password<<endl;
	archivo.close();
	tam_obj++;
 	gymC[tam_obj-1].set_id(id);
	gymC[tam_obj-1].set_nombreC(nombre);
	gymC[tam_obj-1].set_apellidoC(apellido);
	gymC[tam_obj-1].set_nombreE(nombre_e);
	gymC[tam_obj-1].set_apellidoE(apellido_e);
	gymC[tam_obj-1].set_membre(membre);
	gymC[tam_obj-1].set_edad(edad);
	gymC[tam_obj-1].set_password(password);

}

void alta_entrenador(){
	int i,posicion, j;
	char opc;
	string nombreu,nom,unom,pass,texto;
	ofstream cuenta,archivo,entren;
	string nombre,apellido,nombre_e,apellido_e,membre,edad;
	int id, c;
	system("color 5B");
	system("cls");
	cout<<" _____________________"<<endl;
	cout<<"| Agregar Instructor  |"<<endl;
	cout<<"|_____________________|"<<endl;
	cout<<"Nombre Entrenador: "; 		cin>>nombre_e;
	cout<<"Apellido Entrenador: "; 		cin>>apellido_e;
	
	cout<<"Bienvenido "<< nombre_e << " a GYM BRO"<<endl;

	entren.open("entrenadores.txt",ios::out|ios::app);
	if(archivo.fail())
	{
		cout<<"No se pudo abrir el archivo"<<endl;
	}
  
    srand(time(NULL));
    cout<<"Tu numero de entrenador es: ";
    for(c = 1; c <= 4; c++)
    {
        id = 1 + rand() % (10-1);
        cout<<id;
        entren<<id; 
    }
    cout<<endl;
		system("pause");
		system("cls");

	entren<<" "<<nombre_e<<" "<<apellido_e<<endl;
	entren.close();
	tam_obj++;
	gymC[tam_obj-1].set_id_e(id);
	gymC[tam_obj-1].set_nombreE(nombre_e);
	gymC[tam_obj-1].set_apellidoE(apellido_e);


}

void eliminar_cliente(){		
	int i,posicion, j, id,edad,auxid;
	fstream salida,salida2;
	ofstream entrada,entrada2;
	string nombre,apellido,nombre_e,apellido_e,password;
	float membre;
	
	system("color F0");
	system("cls");
	salida.open("ClienteGym.txt",ios::in);//abrir el archivo
	entrada.open("temp.txt",ios::out);
		if(salida.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		else{
		
		cout<<" ______________________"<<endl;
		cout<<"| ELIMINADOR  CLIENTE  |"<<endl;
		cout<<"|______________________|"<<endl;
		cout<<"	ID:		";
			cin>>auxid;
			salida>>id;	
		cout<<endl<<endl;
		
		while(!salida.eof())
			{
				salida>>nombre>>apellido>>nombre_e>>apellido_e>>membre>>edad>>password;
							
				if(id == auxid){				
					cout<<"El Registro Se Ha Eliminado..."<<endl;	
					cout<<"Revise su archivo con extension .txt"<<endl;
				}else{
					entrada<<id<<" "<<nombre<<" "<<apellido<<" "<<nombre_e<<" "<<apellido_e<<" "<<membre<<" "<<edad<<" "<<password<<endl;		
				}
				salida>>id;	
			}	
		entrada.close();				
	    salida.close();
	    remove("ClienteGym.txt");
		rename("temp.txt","ClienteGym.txt");
		system("pause");
		system("cls");
		
		
	}
		}

void eliminar_entrenador(){		
	int i,posicion, j, id,edad,auxid;
	fstream salida;
	ofstream entrada;
	string nombre,apellido,nombre_e,apellido_e,membre;
	
	system("color 8b");
	system("cls");
	salida.open("entrenadores.txt",ios::in);//abrir el archivo
	entrada.open("temp.txt",ios::out);
		if(salida.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		else{
		
		cout<<" ________________________"<<endl;
		cout<<"| ELIMINADOR  ENTRENADOR |"<<endl;
		cout<<"|________________________|"<<endl;
		cout<<"	ID:		";
			cin>>auxid;
			salida>>id;	
		cout<<endl<<endl;
		
		while(!salida.eof())
			{
				salida>>nombre>>apellido;
							
				if(id == auxid){				
					cout<<"El Registro Se Ha Eliminado..."<<endl;		
					cout<<"Revise su archivo con extension .txt"<<endl;			
				}else{
					entrada<<id<<" "<<nombre<<" "<<apellido<<endl;		
						
				}
				salida>>id;	
			}	
		entrada.close();				
	    salida.close();
	    remove("entrenadores.txt");
		rename("temp.txt","entrenadores.txt");
		
		system("pause");
		system("cls");
		
	}
		}

void ordena(){
	int i,posicion, j, id,edad;
	gym auxed;
	char opc;
	string nombreu,nom,unom,pass,texto;
	fstream cuenta,archivo_cl,entren;
	string nombre,apellido,nombre_e,apellido_e,password;
	float membre;
	system("color a0");
	system("cls");
	archivo_cl.open("ClienteGym.txt",ios::in);//abrir el archivo
		if(archivo_cl.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		i=0;
	
		while(!archivo_cl.eof())
			{

				archivo_cl>>id;
				archivo_cl>>nombre;
				archivo_cl>>apellido;
				archivo_cl>>nombre_e;
				archivo_cl>>apellido_e;
				archivo_cl>>membre;
				archivo_cl>>edad;
				archivo_cl>>password;
				gymC[i].set_id(id);
				gymC[i].set_nombreC(nombre);
				gymC[i].set_apellidoC(apellido);
				gymC[i].set_nombreE(nombre_e);
				gymC[i].set_apellidoE(apellido_e);
				gymC[i].set_membre(membre);
				gymC[i].set_edad(edad);
				gymC[i].set_password(password);
				i++;
			}
	archivo_cl.close();
	for(i=0;i<tam_obj-2;i++){
		for(j=i;j<tam_obj-1;j++){
			if(gymC[i].get_edad()<gymC[j].get_edad()){
			auxed = gymC[i];
			gymC[i] = gymC[j];
			gymC[j]=auxed;
		}	

		}
						}
	
	cout<<"                      _____________________"<<endl;
	cout<<"                     |                     |"<<endl;
	cout<<"---------------------    C L I E N T E S    ----------------------------"<<endl;
	cout<<"                     |_____________________|"<<endl;
for(i=0;i<tam_obj-1;i++){
cout<<" ID "<<"  Cliente "<<" Apellido_C "<<"  Entrenador "<<" Apellido_E "<<" Membresia "<<" Edad "<<" Contrasena "<<endl;
cout<<gymC[i].get_id()<<"  "<<gymC[i].get_nombreC()<<"   "<<gymC[i].get_apellidoC()<<"      "<<gymC[i].get_nombreE()<<"      "<<gymC[i].get_apellidoE()<<"        "<<gymC[i].get_membre()<<"     "<<gymC[i].get_edad()<<"   "<<gymC[i].get_password()<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}
	system("pause");
		system("cls");
}

void buscar(){
	int i,posicion, j, id,edad,auxid;
	gym auxed;
	char opc;
	string nombreu,nom,unom,pass,texto;
	fstream cuenta,archivo_cl,entren;
	string nombre,apellido,nombre_e,apellido_e,password;
	float membre;
	bool encontrado;
	
	system("cls");
	system("color 8f");
	archivo_cl.open("ClienteGym.txt",ios::in);//abrir el archivo
		if(archivo_cl.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		i=0;
		cout<<" _____________________"<<endl;
		cout<<"| BUSCARDOR  CLIENTE  |"<<endl;
		cout<<"|_____________________|"<<endl;
		cout<<"	ID:		";cin>>auxid;cout<<endl<<endl;
		
		while(!archivo_cl.eof() && !encontrado)
			{
				archivo_cl>>id;
				archivo_cl>>nombre;
				archivo_cl>>apellido;
				archivo_cl>>nombre_e;
				archivo_cl>>apellido_e;
				archivo_cl>>membre;
				archivo_cl>>edad;
				archivo_cl>>password;
						i++;
				if(id == auxid){
					cout<<"_________________________________________________________________"<<endl;
					cout<<" ID "<<"  Cliente "<<" Apellido_C "<<"  Entrenador "<<" Apellido_E "<<" Membresia "<<" Edad "<<" Contrasena "<<endl;
					cout<<id<<"  "<<nombre<<"   "<<apellido<<"      "<<nombre_e<<"      "<<apellido_e<<"        "<<membre<<"     "<<edad<<"   "<<password<<endl;
					cout<<"-----------------------------------------------------------------"<<endl;
					encontrado = true;
				}
			}
	archivo_cl.close();
	if(!encontrado){
		cout<<"Dato no encontrado"<<endl;
}

		system("pause");
		system("cls");
}

void consulta(){
	fstream archivo_cl,archivo_e;
	ifstream cliente,entrena;
	string nombre,apellido,nombre_e,apellido_e,password;
	float membre;
	int id,i,edad;
	system("cls");
archivo_cl.open("ClienteGym.txt",ios::in);//abrir el archivo
		if(archivo_cl.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		i=0;
		while(!archivo_cl.eof())
			{

				archivo_cl>>id;
				archivo_cl>>nombre;
				archivo_cl>>apellido;
				archivo_cl>>nombre_e;
				archivo_cl>>apellido_e;
				archivo_cl>>membre;
				archivo_cl>>edad;
				archivo_cl>>password;
				
				gymC[i].set_id(id);
				gymC[i].set_nombreC(nombre);
				gymC[i].set_apellidoC(apellido);
				gymC[i].set_nombreE(nombre_e);
				gymC[i].set_apellidoE(apellido_e);
				gymC[i].set_membre(membre);
				gymC[i].set_edad(edad);
				gymC[i].set_password(password);
				i++;
			}
			
		archivo_cl.close();
    cout<<"                      _____________________"<<endl;
	cout<<"                     |                     |"<<endl;
	cout<<"---------------------    C L I E N T E S    ----------------------------"<<endl;
	cout<<"                     |_____________________|"<<endl;
	for(i=0;i<tam_obj-1;i++){
	
	cout<<" ID "<<"  Cliente "<<" Apellido_C "<<"  Entrenador "<<" Apellido_E "<<" Membresia "<<" Edad "<<" Contrasena "<<endl;
cout<<gymC[i].get_id()<<"  "<<gymC[i].get_nombreC()<<"   "<<gymC[i].get_apellidoC()<<"      "<<gymC[i].get_nombreE()<<"      "<<gymC[i].get_apellidoE()<<"        "<<gymC[i].get_membre()<<"     "<<gymC[i].get_edad()<<"   "<<gymC[i].get_password()<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	
		}
		archivo_e.open("entrenadores.txt",ios::in);//abrir el archivo
		if(archivo_e.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		i=0;
		while(!archivo_e.eof())
			{

				archivo_e>>id;
				archivo_e>>nombre_e;
				archivo_e>>apellido_e;
		
				gymC[i].set_id_e(id);
				gymC[i].set_nombreE(nombre_e);
				gymC[i].set_apellidoE(apellido_e);
					i++;
			}
			
		archivo_e.close();
    cout<<"                      ______________________"<<endl;
	cout<<"                     |                      |"<<endl;
	cout<<"---------------------   E N T R E N A D O R  --------------------------"<<endl;
	cout<<"                     |______________________|"<<endl;
	for(i=0;i<tam_obj-1;i++){
	
	cout<<" ID "<<" Entrenador "<<" Apellido_E "<<endl;
cout<<gymC[i].get_id_e()<<"      "<<gymC[i].get_nombreE()<<"      "<<gymC[i].get_apellidoE()<<"        "<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}
		system("pause");
		system("cls");
}

void deudores(){
	int i,posicion, j, id,edad,auxid;
	gym auxed;
	char opc;
	string nombreu,nom,unom,pass,texto;
	fstream cuenta,archivo_cl,entren;
	string nombre,apellido,nombre_e,apellido_e,password;
	float membre;
	bool encontrado;
	system("color 1F");
	system("cls");
	archivo_cl.open("ClienteGym.txt",ios::in);//abrir el archivo
		if(archivo_cl.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		i=0;
		cout<<" _____________________"<<endl;
		cout<<"|   CLIENTE  DEUDORES |"<<endl;
		cout<<"|_____________________|"<<endl;
				
		while(!archivo_cl.eof())
			{
				archivo_cl>>id;
				archivo_cl>>nombre;
				archivo_cl>>apellido;
				archivo_cl>>nombre_e;
				archivo_cl>>apellido_e;
				archivo_cl>>membre;
				archivo_cl>>edad;
				archivo_cl>>password;
				
				gymC[i].set_id(id);
				gymC[i].set_nombreC(nombre);
				gymC[i].set_apellidoC(apellido);
				gymC[i].set_nombreE(nombre_e);
				gymC[i].set_apellidoE(apellido_e);
				gymC[i].set_membre(membre);
				gymC[i].set_edad(edad);
				gymC[i].set_password(password);
						i++;
			
			}
	archivo_cl.close();
	for(i=0;i<tam_obj-1;i++){
			if(gymC[i].get_membre() > 0){
				cout<<"_________________________________________________________________"<<endl;
				cout<<" ID "<<"  Cliente "<<" Apellido_C "<<"  Entrenador "<<" Apellido_E "<<" Membresia "<<" Edad "<<" Contrasena "<<endl;
				cout<<gymC[i].get_id()<<"  "<<gymC[i].get_nombreC()<<"   "<<gymC[i].get_apellidoC()<<"      "<<gymC[i].get_nombreE()<<"      "<<gymC[i].get_apellidoE()<<"        "<<gymC[i].get_membre()<<"     "<<gymC[i].get_edad()<<"   "<<gymC[i].get_password()<<endl;
				cout<<"-----------------------------------------------------------------"<<endl;
					
				}
	}


		system("pause");
		system("cls");
}

void pagar(){
	int i,posicion, j, id,edad,auxid;
	fstream salida;
	ofstream entrada;
	string nombre,apellido,nombre_e,apellido_e,password;
	float membre,auxmem,pago=0;
	
	system("color d0");
	system("cls");
	salida.open("ClienteGym.txt",ios::in);//abrir el archivo
	entrada.open("temp.txt",ios::out);
		if(salida.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		else{
		
		cout<<" ______________________"<<endl;
		cout<<"| DEUDOR      CLIENTE  |"<<endl;
		cout<<"|______________________|"<<endl;
		cout<<"	ID:		";
			cin>>auxid;
			salida>>id;	
		cout<<endl<<endl;
		
		while(!salida.eof())
			{
				salida>>nombre>>apellido>>nombre_e>>apellido_e>>membre>>edad>>password;
							
				if(id == auxid){
					if(membre>0){
						cout<<"Tiene saldo pendiete"<<endl;	
						cout<<"Ingrese cifra a pagar: "; cin>>pago; cout<<endl;
						auxmem = membre - pago;
					entrada<<id<<" "<<nombre<<" "<<apellido<<" "<<nombre_e<<" "<<apellido_e<<" "<<auxmem<<" "<<edad<<" "<<password<<endl;	
						cout<<"El Registro Se Ha Actualizado..."<<endl;	
						cout<<"Revise su archivo con extension .txt"<<endl;
					}else{
						entrada<<id<<" "<<nombre<<" "<<apellido<<" "<<nombre_e<<" "<<apellido_e<<" "<<membre<<" "<<edad<<" "<<password<<endl;	
						cout<<"Usted no tiene adeudo, Gracias por consultar."<<endl;
					}
		
				}else{
					entrada<<id<<" "<<nombre<<" "<<apellido<<" "<<nombre_e<<" "<<apellido_e<<" "<<membre<<" "<<edad<<" "<<password<<endl;		
						
				}
				salida>>id;	
			}	
		entrada.close();				
	    salida.close();
	    remove("ClienteGym.txt");
		rename("temp.txt","ClienteGym.txt");
		system("pause");
		system("cls");
	}
}

void editar(){

	int i,posicion, j, id,edad,auxid;
	fstream salida,salida1;
	ofstream entrada,entrada1;
	string nombre,apellido,nombre_e,apellido_e,password,contra;
	float membre;
	
	system("color d0");
	system("cls");
	salida.open("iniciosesion.txt",ios::in);//abrir el archivo
	entrada.open("temp.txt",ios::out);
	salida1.open("ClienteGym.txt",ios::in);//abrir el archivo
	entrada1.open("temp1.txt",ios::out);
		if(salida.fail() || salida1.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		else{
		
		cout<<" ______________________"<<endl;
		cout<<"| CAMBIAR CONTRASENA   |"<<endl;
		cout<<"|______________________|"<<endl;
		cout<<"	ID:		";
			cin>>auxid;
			salida>>id;
			salida1>>id;
		
		cout<<endl<<endl;
		
		while(!salida.eof() || !salida1.eof())
			{
				salida>>nombre;
				salida1>>nombre>>apellido>>nombre_e>>apellido_e>>membre>>edad>>contra;
							
				if(id == auxid){
					
					cout<<"Ingrese nuevo password: "; cin>>password; cout<<endl;
					entrada<<id<<" "<<password<<endl;	
						cout<<"El Registro Se Ha Actualizado..."<<endl;	
						cout<<"Revise su archivo iniciosesion.txt"<<endl;
						system("pause");
					cout<<"Confirme password: "; cin>>password; cout<<endl;
					entrada1<<id<<" "<<nombre<<" "<<apellido<<" "<<nombre_e<<" "<<apellido_e<<" "<<membre<<" "<<edad<<" "<<password<<endl;	
						cout<<"El Registro Se Ha Actualizado..."<<endl;	
						cout<<"Revise su archivo ClienteGym.txt"<<endl;
					
		
				}else{
					entrada<<id<<" "<<nombre<<endl;	
					entrada1<<id<<" "<<nombre<<" "<<apellido<<" "<<nombre_e<<" "<<apellido_e<<" "<<membre<<" "<<edad<<" "<<contra<<endl;	
						
				}
				salida>>id;	
				salida1>>id;	
			}	
		entrada.close();				
	    salida.close();
	    remove("iniciosesion.txt");
		rename("temp.txt","iniciosesion.txt");
			
		entrada1.close();				
	    salida1.close();
        remove("ClienteGym.txt");
		rename("temp1.txt","ClienteGym.txt");	
		
		system("pause");
		system("cls");
	}
		
	
	}


void menu(){
	system("color 9f");
	system("cls");
	int opc;
	ifstream archivo;
	string texto;
	do{
			
	cout<<endl;
	cout<<"       ___                    ";cout<<"1. Agregar Cliente"<<endl;			//listo
	cout<<"      /___`                   ";cout<<"2. Eliminar Cliente"<<endl;		//listo
	cout<<"     (|0 0|)                  ";cout<<"3. Agregar Instructor"<<endl;		//listo
	cout<<"   __/{|U|}`_ ___-vvv         ";cout<<"4. Eliminar Instructor"<<endl;		//listo
	cout<<"  / `  {~}   / _|_P|          ";cout<<"5. Mostrar Clientes e Instructores"<<endl;	//listo
	cout<<"  | /`  ~   /_/   ||          ";cout<<"6. Buscar clientes"<<endl;				//listo
	cout<<"  |_| (____)      ||          ";cout<<"7. Mostrar en orden la edad de los clientes"<<endl; 	//listo       
	cout<<"  |_]/______   /|_||_/|       ";cout<<"8. Mostrar los Clientes con adeudo"<<endl;
	cout<<"     _|_||_|_ |] _||_ [|      ";cout<<"9. Pagar Deuda"<<endl;	//listo
	cout<<"    (_,_||_,_) |/ [] |/       ";cout<<"10. Cambiar contrasena "<<endl;		//listo
	cout<<"                              ";cout<<"11. Salir"<<endl;		//listo
		cin>>opc;
	switch(opc){
		case 1: alta_cliente();
			break;
		case 2: cout<<"Eliminar Cliente"<<endl;
				eliminar_cliente();
			break;
		case 3: alta_entrenador();
			break;
		case 4: cout<<"Eliminar Intructor"<<endl; eliminar_entrenador();
			break;
		case 5:		consulta();
			break;
		case 6: cout<<"Buscar cliente"<<endl;
					buscar();
			break;
		case 7: cout<<"Orden Por edad"<<endl;
				ordena();
			break;
		case 8: cout<<"Mostrar clientes con adeudo"<<endl;
				deudores();
			break;
		case 9: cout<<"Pagar deuda"<<endl; pagar();
			break;
		case 10:	editar();
			break;
		case 11: cout<<"Hasta pronto!!"<<endl;
			break;
		
		default: cout<<"El numero correcto por favor....."<<endl;
			
	}
	}while(opc!=11);
}
void login(){
	int i,posicion, j;
	char opc;
	string nombreu,nom,unom,pass,texto;
	fstream archivo_us;
	ifstream archivo; 
		  // Iniciar sesion
	archivo_us.open("iniciosesion.txt",ios::in);//abrir el archivo
		if(archivo_us.fail())
		{
			cout<<"No se pudo abrir el archivo"<<endl;
		}
		i=0;
		while(!archivo_us.eof())
			{
				archivo_us>>unom;
				archivo_us>>pass;
				gymC[i].set_nombre(unom);
				gymC[i].set_password(pass);
				
				i++;
			}
			
		archivo_us.close();
			
		tam_obj=i;
	
		cout<<"\tNumero de Cuenta:\t";
			cin>>nombreu;
			
			posicion=buscar_username(nombreu);
			
			if(posicion!=-1)
			{
				cout<<"\tPassword:\t";
					cin>>pass;
				if (comparar_password(pass,gymC[posicion].get_password()))
				{		
						menu();		
			}
			else
				{
					cout<<"Tu password es incorrecto ."<<endl;
				}
			}
			
else{
	cout<<"Al parecer no tienes una cuenta con nosotros"<<endl;
	cout<<"Deseas crear una cuenta? selecciona s para Si o n para salir"<<endl;
		cin>>opc;
		switch(opc){
			case 's': alta_cliente();
				break;
			case 'S': alta_cliente();
				break;
			case 'n': exit(1);
				break;
			case 'N': exit(1);
			default: cout<<"Por favor seleccione la opcion correcta..."<<endl;
		}
}
	posicion=buscar_username(nombreu);
}

int main(){
system("color 5F");
cout<<" __          ______      _______     __    .__   __. "<<endl;
cout<<"|  |       |   __   |   |  _____|   |  |   |  | |  | "<<endl;
cout<<"|  |       |  |  |  |   |  |  __    |  |   |  ` |  | "<<endl;
cout<<"|  |       |  |  |  |   |  | |_ |   |  |   |  .`   | "<<endl;
cout<<"|  `----.  |  `--'  |   |  |__| |   |  |   |  | `  | "<<endl;
cout<<"|_______|  | ______ |   |______ |   |__|   |__| |__| "<<endl;
	cout<<endl<<endl;
	login();
}