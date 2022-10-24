#include <iostream>
#include <string>
#include "main.h"

using namespace std;

//Funciones clase Articulo


//Constructor default.
Articulo::Articulo() {
	precio = 0.0;
	cantidad = 0;
	nombre = "";
}

//Constructor con argumentos.
Articulo::Articulo(float precio, int cantidad, string nombre) {
	this->precio = precio;
	this->cantidad = cantidad;
	this->nombre = nombre;
}


//Destructor.
Articulo::~Articulo() {

}

//Regresa precio del articulo.
float Articulo::getPrecio() {
	return precio;
}

//Regresa cantidad.
int Articulo::getCantidad() {
	return cantidad;
}

//Regresa tipo de articulo.
string Articulo::getNombre() {
	return nombre;
}

//Modifica cantidad en caso de que se compre.
void Articulo::setCantidad(int cantidad) {
	this->cantidad = cantidad;
}

//Funciones clase Cliente

//Constructor default.
Cliente::Cliente() {
	this->indice = 0;
	this->nombre = "";
	this->formaPago = 0;
	this->gastos = 0;
	//this->articulosComprar[M] = Articulo();
}

//Constructor con argumentos.
Cliente::Cliente(string nombre, int formaPago, Articulo articulosComprar) {
	this->indice = 0;
	this->nombre = nombre;
	this->formaPago = formaPago;
	this->gastos = 0;
	//this->articulosComprar[M] = articulosComprar;
}

//Destructor.
Cliente::~Cliente() {

}

//Regresa nombre del cliente.
string Cliente::getNombre() {
	return nombre;
}

//Regresa forma de pago del cliente.
int Cliente::getFormaPago() {
	return formaPago;
}

//Regresa lista de articulos que el cliente compro.
void Cliente::getArticulosComprar() {
	for (int i = 0; i < indice; i++) {
		cout << "- " << articulosComprar[i].getNombre() << ", cantidad: " << articulosComprar[i].getCantidad() << "\n";
	}
}

//Guarda nombre del cliente.
void Cliente::setNombre(string nombre) {
	this->nombre = nombre;
}

//Guarda forma de pago del cliente.
void Cliente::setFormaPago(int formaPago) {
	this->formaPago = formaPago;
}

//Guarda lista de articulos que compro el cliente.
void Cliente::setArticulo(Articulo articulo, int cantidad, float precio) {
	//Si no hay lista inicializa.
	if (indice == 0) {
		this->articulosComprar[indice] = articulo;
		articulosComprar[indice].setCantidad(cantidad);
		gastos = precio * cantidad;
		indice++;
	}
	//Si ya esta inicializada compara para evitar repeticiones y solo actualizar cantidad.
	else {
		for (int i = 0; i < indice; i++) {
			if (this->articulosComprar[i].getNombre() == articulo.getNombre()) {
				articulosComprar[i].setCantidad(articulosComprar[i].getCantidad() + cantidad);
			}
			else {
				this->articulosComprar[indice] = articulo;
				articulosComprar[indice].setCantidad(cantidad);
				gastos = precio * cantidad;
				indice++;
				return;
			}
		}
	}
}

//Guarda total gastado.
void Cliente::setTotal(float total) {
	this->gastos = total;
}

//Muestra total gastado.
float Cliente::getTotal() {
	return gastos;
}

//Funciones Tienda

//Constructor default.
Tienda::Tienda() {
	nombre = "";
}

//Constructor con argumentos.
Tienda::Tienda(string nombre) {
	this->nombre = nombre;
}

//Destructor.
Tienda::~Tienda() {

}


//Inicializa inventario de la tienda.
void Tienda::agregarInventario(Articulo articulo, int indice) {
	this->inventario[indice] = articulo;
}

//Modifica inventario de la tienda
void Tienda::setInventario(int cantidad, int indice) {
	inventario[indice].setCantidad(cantidad);
}

//Regresa nombre de la tienda.
string Tienda::getNombre() {
	return nombre;
}

//Regresa cantidad de articulos restantes en tienda.
int Tienda::getCantidad(int indice) {
	return inventario[indice].getCantidad();
}

//Muestra el inventario de la tienda.
void Tienda::displayInventario(void) {
	for (int i = 0; i < M; i++) {
		cout << i + 1 << ")\n";
		cout << "Producto: " << inventario[i].getNombre() << "\n";
		cout << "Cantidad en inventario: " << inventario[i].getCantidad() << "\n";
		cout << "Precio: " << inventario[i].getPrecio() << "\n\n";
	}
}

