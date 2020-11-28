#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
			
using namespace std;

int tamhash = 10;

struct Registro{
	string DNI; //clave
	long long int numero_de_cuenta;
	string nombre;
	string direccion;
	long long int telefono;
	double saldo;
};

typedef struct Registro cliente;
cliente tabla_Hash[ 10 ];
	
void Crear_Tabla_Hash(  ){
	for( int i = 0; i < 10; i++ ){
		tabla_Hash[ i ].DNI = " vacio ";
		tabla_Hash[ i ].nombre = " vacio ";
		tabla_Hash[ i ].numero_de_cuenta = 0;
		tabla_Hash[ i ].direccion = " vacio ";
		tabla_Hash[ i ].telefono = 0;
		tabla_Hash[ i ].saldo = 0; 
	}
}

long Suma_Caracteres( string clave ){
	long suma = 0;
	
	for( int j = 0; j < clave.length(); j++ ){
		suma = suma*27 + clave[ j ];
	}
	return suma;
}

int Funcion_Hash( string clave ){
	long suma;
	
	suma = Suma_Caracteres( clave );
	
	int indice_Hash;
	
	indice_Hash = suma%10;
	return indice_Hash;
}

int Resuelve_Colisiones( string clave, int indice_Hash ){
	int i = 0;
	
	string DNI = tabla_Hash[ indice_Hash ].DNI;
	while ( DNI != " vacio " ){
		i++;
		indice_Hash = indice_Hash + i * i;
		indice_Hash = indice_Hash%10;
		DNI = tabla_Hash[ indice_Hash ].DNI;
	}
	return indice_Hash;
}

void Insertar_Datos( string clave, string nombre, long long int numero_de_cuenta, string direccion, long long int telefono, double saldo ){
	int indice_Hash;
	
	indice_Hash = Funcion_Hash( clave );
	indice_Hash = Resuelve_Colisiones( clave, indice_Hash );
	tabla_Hash[ indice_Hash ].DNI = clave;
	tabla_Hash[ indice_Hash ].nombre = nombre;
	tabla_Hash[ indice_Hash ].numero_de_cuenta = numero_de_cuenta;
	tabla_Hash[ indice_Hash ].direccion = direccion;
	tabla_Hash[ indice_Hash ].telefono = telefono;
	tabla_Hash[ indice_Hash ].saldo = saldo; 
}

void Imprimir_Datos(){
	for( int i = 0; i < tamhash; i++ ){
		cout << i << " | " << tabla_Hash[ i ].DNI << " / " << tabla_Hash[ i ].nombre << " / " << tabla_Hash[ i ].numero_de_cuenta << " / " << tabla_Hash[ i ].direccion << " / " << tabla_Hash[ i ].telefono << " / " << tabla_Hash[ i ].saldo << endl;
		for( int i = 0; i < 40; i++ ){
			cout << " - ";
		}
	cout << "\n";
	}
}

int Menu(  ){
	int opcion;
	
	cout << " \t-------" << endl;
	cout << " \tMenu"    << endl;
	cout << " \t-------" << endl;
	cout << " \n\t1. Ingresar ";
	cout << " \n\t2. Buscar ";
	cout << " \n\t3. Actualizar ";
	cout << " \n\t4. Eliminar ";
	cout << " \n\t5. Mostrar ";
	cout << " \n\t6. Finalizar";
	cout << " \n\tIngrese un numero --> ";
	cin  >> opcion; 
	return opcion;
}

int Buscar( string clave ){
	int encontrado = -1;
	int indice_Hash = Funcion_Hash( clave );
	string DNI = tabla_Hash[ indice_Hash ].DNI;
	
	if( DNI != " vacio " ){
		encontrado = indice_Hash;
	} 
	return encontrado;
}

int Eliminar( string clave ){
	int indice_Hash;
	int eliminado = 0;
	
	indice_Hash = Funcion_Hash( clave );
	string DNI = tabla_Hash[ indice_Hash ].DNI;
	string Nombre = tabla_Hash[ indice_Hash ].nombre;
	
	if( DNI != " vacio " ){
		tabla_Hash[ indice_Hash ].DNI = " vacio ";
		tabla_Hash[ indice_Hash ].nombre = " vacio ";
		tabla_Hash[ indice_Hash ].numero_de_cuenta = 0;
		tabla_Hash[ indice_Hash ].direccion = " vacio";
		tabla_Hash[ indice_Hash ].telefono = 0;
		tabla_Hash[ indice_Hash ].saldo = 0;
		eliminado = 1;
	} 
	return eliminado;
}

void Actualizar( string clave ){
	int encontrado; char actualizar; string nombre; double saldo; string direccion; long long int telefono; long long int numero_de_cuenta;
	
	encontrado = Buscar( clave );
	if( encontrado != -1 ){
		cout << " Dato Encontrado: " << endl;
		cout << " Nombre: " << tabla_Hash[ encontrado ].nombre << endl;
		cout << " Desea actualizar ? ---->  ( s/n ) ";
		cin  >> actualizar;
		if( actualizar == 's' ){
			fflush(stdin);
			cout << "Ingrese el nuevo nombre = ";
			cin  >> nombre;
			tabla_Hash[ encontrado ].nombre = nombre;
			cout << " Desea actualizar el numero de cuenta ?  ( s/n ) "; 
			cin >> actualizar;
		}else if( actualizar == 'n' ){
			cout << " El Dato nombre no fue actualizado " << endl;
			cout << " Desea actualizar el numero de cuenta ? ( s/n ) ";
			cin  >> actualizar;
		}if( actualizar == 's' ){
			fflush(stdin);
			cout << "Ingrese el nuevo numero de cuenta = ";
			cin  >> numero_de_cuenta;
			tabla_Hash[ encontrado ].numero_de_cuenta = numero_de_cuenta;
			cout << " Desea actualizar la direccion ?  ( s/n ) ";
			cin  >> actualizar;
		}else if( actualizar == 'n' ){
			cout << " El Dato numero de cuenta no fue actualizado " << endl;
			cout << " Desea actualziar la direccion ? ( s/n )";
			cin  >> actualizar;
		}if( actualizar == 's' ){
			fflush(stdin);
			cout << "Ingrese la nueva direccion = ";
			cin  >> direccion;
			tabla_Hash[ encontrado ].direccion = direccion;
			cout << " Desea actualizar el telefono ?  ( s/n ) ";
			cin  >> actualizar;
		}else if( actualizar == 'n' ){
			cout << " El Dato direccion no fue actualizado " << endl;
			cout << " Desea actualizar el telefono ? ( s/n ) ";
			cin  >> actualizar;
		}if( actualizar == 's' ){
			fflush(stdin);
			cout << "Ingrese el nuevo telefono = ";
			cin  >> telefono;
			tabla_Hash[ encontrado ].telefono = telefono;
			cout << " Desea actualizar el saldo ?  ( s/n ) ";
			cin  >> actualizar;
		}else if( actualizar == 'n' ){
			cout << " El Dato telefono no fue actualizado " << endl;
			cout << " Desea actualizar el saldo ? ( s/n ) ";
			cin  >> actualizar;
		}if( actualizar == 's' ){
			fflush(stdin);
			cout << "Ingrese el nuevo saldo = ";
			cin  >> saldo;
			tabla_Hash[ encontrado ].saldo = saldo;
			cout << " \nDato Actualizado ";
		}else if( actualizar == 'n' ){
			cout << " El Dato Saldo no fue actualizado " << endl;
			cout << " \nDato Actulizado ";
		}
	}else{
		cout << "------------------" << endl;
		cout << " No existen datos " << endl;
		cout << "------------------" << endl;
	}
}

main( void ){
	int opcion; int encontrado; int eliminado; // string actualizar
	string clave; int indice_Hash; string nombre; long long int numero_de_cuenta; long long int telefono; double saldo; string direccion;
	
	Crear_Tabla_Hash(  );
	while( 1 ){
		opcion = Menu(  );
		switch( opcion ){
			case 1: //insertar
				cout << "\n";
				cout << " DNI: ";
				cin  >> clave;
				cout << " Nombre: ";
				cin  >> nombre;
				cout << " Numero de Cuenta: ";
				cin  >> numero_de_cuenta;
				cout << " Direccion: ";
				cin  >> direccion;
				cout << " Telefono: ";
				cin  >> telefono;
				do{
					cout << " Saldo: ";
					cin  >> saldo;
					if( saldo < 0 ){
						cout << " \nEl saldo no puede ser negativo " << endl;
					}
				}while( saldo < 0 );
				cout << "\n"; 
				Insertar_Datos( clave, nombre, numero_de_cuenta, direccion, telefono, saldo );
				break;
			case 2: //buscar
				cout << " DNI: ";
				cin  >> clave;
				encontrado = Buscar( clave );
				if( encontrado != -1 ){
					cout << " \nDatos encontrados: " << endl;
					cout << "--------------------------" << endl;
					cout << " DNI: " << tabla_Hash[ encontrado ].DNI << endl;
					cout << " Nombre: " << tabla_Hash[ encontrado ].nombre << endl;
					cout << " Numero de cuenta: " << tabla_Hash[ encontrado ].numero_de_cuenta << endl;
					cout << " Direccion: " << tabla_Hash[ encontrado ].direccion << endl;
					cout << " Telefono: " << tabla_Hash[ encontrado ].telefono << endl;
					cout << " Saldo: " << tabla_Hash[ encontrado ].saldo << endl;
					cout << "--------------------------" << endl;	
				}if( encontrado == -1 ){
					cout << "\n";
					cout << " No existen los datos " << endl;
				}
				break;
			case 3: //actualizar
				cout << " DNI: ";
				cin  >> clave;
				Actualizar( clave );
				break;
			case 4: //Eliminar
				cout << " DNI: ";
				cin  >> clave;
				eliminado = Eliminar( clave );
				if( eliminado == 1 ){
					cout << "Datos Eliminados " << endl;
				}else{
					cout << "Error! ... Datos no existen " << endl;
				}	
				break;
			case 5: // Mostrar
				Imprimir_Datos(  );
				break;
			case 6: //finalizar
				exit( 0 );
				break;	
		} 
	}
}