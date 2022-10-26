#include <iostream>
#include <string>
#include "main.h"

using namespace std;
//Programa principal
int main() {
	//Inicializamos los objetos de nuestras clases.
	Tienda tiendaGenerica("Walmart");
	Articulo productos[] = { Articulo(60, 2, "Queso"), Articulo(10, 5, "Gansito"), Articulo(20, 8, "Jugo"), Articulo(1, 20, "Pan"), Articulo(15, 3, "Leche"), Articulo(5, 10, "Frijoles"), Articulo(10, 10, "Agua"), Articulo(40, 2, "Jamon") };
	Cliente clienteDistinguido;
	//Variables requeridas para el funcionamiento del programa.
	int respuesta = 0, cantidad = 0, formaPago = 0, billete = 0;
	float total = 0.0;
	string nombre, compra;
	char respuesta2 = ' ', respuesta3 = ' ', pagado = 'f';
	//Nombre.
	cout << "Me permites tu nombre?\n";
	while (!(cin >> nombre)) {
		cout << "Eso no es un nombre valido!\n";
		cout << "Me permites tu nombre?\n";
	}
	//Guardamos el nombre.
	clienteDistinguido.setNombre(nombre);
	//Menu.
	cout << "Bienvenido a la tienda " << tiendaGenerica.getNombre() << ", " << clienteDistinguido.getNombre() << ". Como podemos ayudarle el dia de hoy?\n";
	cout << "1) Comprar\n2) Salir\n";
	//No funciona amenos de que se lea una opcion valida.
	while (!(cin >> respuesta)) {
		cout << "Respuesta no valida, intente de nuevo\n";
		cout << "Que deseas hacer?\n";
		cout << "1) Comprar\n2) Salir\n";
		cin.clear();
		cin.ignore(123, '\n');
	}
	do {
		//Switch case para comprar o salir.
		switch (respuesta) {
		case 0:
		case 1:
			//Si se decide comprar entonces llenamos nuestro inventario con los articulos declarados anteriormente.
			for (int i = 0; i < M; i++) {
				tiendaGenerica.agregarInventario(productos[i], i);
			}
			//Mostramos el inventario.
			cout << "Nuestro inventario es el siguiente:\n\n";
			tiendaGenerica.displayInventario();
			cout << "Deseas comprar algo? (Y/N)\n";
			cin >> respuesta2;
			//No funciona amenos de que se lea una opcion valida.
			while (respuesta2 != 'Y' && respuesta2 != 'y' && respuesta2 != 'N' && respuesta2 != 'n') {
				cout << "Respuesta invalida, intentelo de nuevo\n";
				cout << "Deseas comprar algo? (Y/N)\n";
				cin.clear();
				cin.ignore(123, '\n');
				cin >> respuesta2;
			}
			//Se sale del programa en caso de que no se quiera comprar nada.
			if (respuesta2 == 'N' || respuesta2 == 'n') {
				cout << "Gracias por comprar con nosotros, vuelva pronto!\n";
				exit(2);
			}
			//Borramos el buffer.
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Perfecto! ";
			cout << "Que deseas comprar?\n";
			//No funciona amenos de que se lea una opcion valida.
			while (!(cin >> compra)) {
				cout << "Error, input invalido.\n";
				cout << "Que deseas comprar?\n";
				cin.clear();
				cin.ignore(123, '\n');
			}
			do {
				//Ciclo para encontrar el objeto buscado.
				for (int i = 0; i < M; i++) {
					//Si se encuentra se entra a otro ciclo.
					if (compra == productos[i].getNombre()) {
						//Si ya no hay se le da a saber.
						if (tiendaGenerica.getCantidad(i) == 0) {
							cout << "Lo sentimos, ya no tenemos disponibilidad de este producto.\n";
							cout << "Deseas buscar otro producto? (Y/N)\n";
							cin >> respuesta3;
							while (respuesta3 != 'Y' && respuesta3 != 'y' && respuesta3 != 'N' && respuesta3 != 'n') {
								cout << "Respuesta invalida, intentelo de nuevo\n";
								cout << "Deseas buscar otro producto? (Y/N)\n";
								cin.clear();
								cin.ignore(123, '\n');
								cin >> respuesta3;
							}
							if (respuesta3 == 'Y' || respuesta3 == 'y') {
								cout << "Perfecto! ";
								while (!(cin >> compra)) {
									cout << "Error, input invalido.\n";
									cout << "Que deseas comprar?\n";
									cin.clear();
									cin.ignore(123, '\n');
								}
							}
							else {
								respuesta3 = 'N';
							}
						}
						//Si hay se le da la opcion de cuantos. 
						else {
							cout << "Aqui esta tu producto!\n";
							cout << "Que cantidad deseas comprar?\n";
							while (!(cin >> cantidad)) {
								cout << "Respuesta no valida, intente de nuevo\n";
								cout << "Que cantidad deseas comprar?\n";
								cin.clear();
								cin.ignore(123, '\n');
							}
							//Si es mas de lo que hay se le da a saber al usuario.
							if (cantidad > tiendaGenerica.getCantidad(i)) {
								do {
									cout << "Lo sentimos, no tenemos suficiente producto para satisfacer tu orden\n";
									cout << "Intenta una cantidad menor o igual a " << tiendaGenerica.getCantidad(i);
									while (!(cin >> cantidad)) {
										cout << "Respuesta no valida, intente de nuevo\n";
										cout << "Que cantidad deseas comprar?\n";
										cin.clear();
										cin.ignore(123, '\n');
									}
								} while (cantidad <= 0 && cantidad > productos[i].getCantidad());
							}
							//Actualiza el inventario de la tienda y al cliente.
							clienteDistinguido.setArticulo(productos[i], cantidad, productos[i].getPrecio());
							tiendaGenerica.setInventario((tiendaGenerica.getCantidad(i)) - cantidad, i);
							total += productos[i].getPrecio() * cantidad;
							cout << "Claro, deseas agregar algo mas? (Y/N)\n";
							cin >> respuesta3;
							cin.clear();
							cin.ignore(123, '\n');
							//No funciona amenos de que se lea una opcion valida.
							while (respuesta3 != 'Y' && respuesta3 != 'y' && respuesta3 != 'N' && respuesta3 != 'n') {
								cout << "Respuesta no valida, intente de nuevo\n";
								cout << "Deseas agregar algo mas? (Y/N)\n";
								cin >> respuesta3;
								cin.clear();
								cin.ignore(123, '\n');
							}
						}
						if (respuesta3 == 'Y' || respuesta3 == 'y') {
							cout << "Perfecto! ";
							//Despliega un inventario actualizado dependiendo de que se compro la primera vez.
							cout << "Nuestro nuevo inventario es el siguiente:\n\n";
							tiendaGenerica.displayInventario();
							cout << "Que deseas comprar?\n";
							while (!(cin >> compra)) {
								cout << "Error, input invalido.\n";
								cout << "Que deseas comprar?\n";
								cin.clear();
								cin.ignore(123, '\n');
							}	
							respuesta2 = respuesta3;
							i -= 1;
						} else {
							i = 8;
							respuesta2 = respuesta3;
						}
					//Si no se cuenta con el producto le hacemos saber y damos la opcion de buscar por otro.
					} else {
						if (i == M  - 1) {
							cout << "Lo sentimos no tenemos ese producto.\n";
							cout << "Deseas buscar otro producto? (Y/N)\n";
							cin >> respuesta2;
							cin.clear();
							cin.ignore(123, '\n');
							//No funciona amenos de que se lea una opcion valida.
							while (respuesta2 != 'Y' && respuesta2 != 'y' && respuesta2 != 'N' && respuesta2 != 'n') {
								cout << "Respuesta invalida, intentelo de nuevo\n";
								cout << "Deseas buscar otro producto? (Y/N)\n";
								cin >> respuesta2;
								cin.clear();
								cin.ignore(123, '\n');
							}
							if (respuesta2 == 'Y' || respuesta2 == 'y') {
								cout << "Perfecto! ";
								cout << "Que deseas comprar?\n";
								while (!(cin >> compra)) {
									cout << "Error, input invalido.\n";
									cout << "Que deseas comprar?\n";
									cin.clear();
									cin.ignore(123, '\n');
								}
							}
							else {
								respuesta2 = 'N';
							}
						}
					}
				}
			//Terminando las compras se sale del ciclo.
			} while (respuesta2 != 'N' && respuesta2 != 'n');
			cout << "Su total es el siguiente: " << total << "\n";
			cout << "Como desea pagar?\n";
			//Menu de pago.
			cout << "1) Debito\n2) Credito\n3) Efectivo\n";
			//No funciona amenos de que se lea una opcion valida.
			while (!(cin >> formaPago)) {
				cout << "Error, input invalido.\n";
				cout << "Que deseas comprar?\n";
				cin.clear();
				cin.ignore(123, '\n');
			}
			do {
				if (formaPago == 1 || formaPago == 2) {
					cout << "Perfecto, aqui tiene sus compras\n";
					pagado = 't';
				}
				else if (formaPago == 3) {
					cout << "Con que billete desea pagar?\n(100, 200, 500, 1000)\n";
					while (!(cin >> billete)) {
						cout << "Error, input invalido.\n";
						cout << "Con que billete desea pagar?\n 100, 200, 500, 1000)\n";
						cin.clear();
						cin.ignore(123, '\n');
					}
					while (billete != 100 && billete != 200 && billete != 500 && billete != 1000) {
						cout << "Lo sentimos, no aceptamos ese billete\n";
						cout << "Con que billete desea pagar?\n(100, 200, 500, 1000)\n";
						while (!(cin >> billete)) {
							cout << "Error, input invalido.\n";
							cout << "Con que billete desea pagar?\n(100, 200, 500, 1000)\n";
							cin.clear();
							cin.ignore(123, '\n');
						}
					}
					//Comprueba que el billete seleccionado sea suficiente para pagar.
					while (billete < total) {
						cout << "No es suficiente! Intente un billete mas grande.\n";
						cout << "Con que billete desea pagar?\n(100, 200, 500, 1000)\n";
						while (!(cin >> billete)) {
							cout << "Error, input invalido.\n";
							cout << "Con que billete desea pagar?\n(100, 200, 500, 1000)\n";
							cin.clear();
							cin.ignore(123, '\n');
						}
						while (billete != 100 && billete != 200 && billete != 500 && billete != 1000) {
							cout << "Lo sentimos, no aceptamos ese billete\n";
							cout << "Con que billete desea pagar?\n(100, 200, 500, 1000)\n";
							while (!(cin >> billete)) {
								cout << "Error, input invalido.\n";
								cout << "Con que billete desea pagar?\n(100, 200, 500, 1000)\n";
								cin.clear();
								cin.ignore(123, '\n');
							}
						}
					}
					//Se devuelve cambio y sale del ciclo.
					cout << "Perfecto!\n";
					cout << "Aqui tiene su cambio: " << billete - total << ".\n";
					pagado = 't';
				}
				//No funciona amenos de que se lea una opcion valida.
				else {
					cout << "Lo sentimos, no aceptamos esa forma de pago\n";
					cout << "Como desea pagar?\n";
					cout << "1) Debito\n2) Credito\n3) Efectivo\n";
					while (!(cin >> formaPago)) {
						cout << "Error, input invalido.\n";
						cout << "Como desea pagar?\n";
						cout << "1) Debito\n2) Credito\n3) Efectivo\n";
						cin.clear();
						cin.ignore(123, '\n');
					}
				}
			} while (pagado != 't');
			//Se actualiza la base de datos del cliente.
			clienteDistinguido.setFormaPago(formaPago);
			clienteDistinguido.setTotal(total);
			cout << "Gracias por comprar con nosotros, vuelva pronto!\n\n";
			//Se pregunta si se quiere desplegar la informacion del cliente.
			cout << "Desea mostrar la informacion de su cliente? (Y/N)\n";
			cin >> respuesta3;
			cin.clear();
			cin.ignore(123, '\n');
			//No funciona amenos de que se lea una opcion valida.
			while (respuesta3 != 'Y' && respuesta3 != 'y' && respuesta3 != 'N' && respuesta3 != 'n') {
				cout << "Respuesta no valida, intente de nuevo\n";
				cout << "Desea mostrar la informacion de su cliente? (Y/N)\n";
				cin >> respuesta3;
				cin.clear();
				cin.ignore(123, '\n');
			}
			//Despliega la informacion del cliente.
			if (respuesta3 == 'Y' || respuesta3 == 'y') {
				cout << "Su cliente: " << clienteDistinguido.getNombre() << "\n";
				cout << "Compras:\n";
				clienteDistinguido.getArticulosComprar();
				cout << "Total gastado: " << clienteDistinguido.getTotal() << "\n";
				cout << "Forma de pago: ";
				if (clienteDistinguido.getFormaPago() == 1) {
					cout << "Debito.\n";
				}
				else if (clienteDistinguido.getFormaPago() == 2) {
					cout << "Credito.\n";
				}
				else if (clienteDistinguido.getFormaPago() == 3) {
					cout << "Efectivo.\n";
				}
				exit(1);
			}
			//Se sale del programa.
			else {
				exit(1);
			}
			exit(1);
			break;
		//Se sale del programa.
		case 2:
			exit(0);
			break;

		default:
			cout << "Respuesta no valida, intente de nuevo\n";
			cout << "Que deseas hacer?\n";
			cout << "1) Comprar\n2) Salir\n";
			while (!(cin >> respuesta)) {
				cout << "Respuesta no valida, intente de nuevo\n";
				cout << "Que deseas hacer?\n";
				cout << "1) Comprar\n2) Salir\n";
				cin.clear();
				cin.ignore(123, '\n');
			}
			break;
		}
	//Mientras no se salga el programa sigue.
	} while (respuesta != 2);
}

