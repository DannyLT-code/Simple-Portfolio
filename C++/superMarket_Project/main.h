#include <iostream>
#include <string>

using namespace std;

#pragma once

const int M = 8;

class Articulo {
private:
    float precio;
    int cantidad;
    string nombre;
public:
    //Constructors
    Articulo();
    Articulo(float precio, int cantidad, string nombre);
    ~Articulo();
    //Getters
    float getPrecio();
    int getCantidad();
    string getNombre();
    //Setters
    void setCantidad(int cantidad);
};

class Cliente : Articulo {
private:
    string nombre;
    int formaPago;
    int indice;
    int gastos;
    Articulo articulosComprar[M];
public:
    //Constructors
    Cliente();
    Cliente(string nombre, int formaPago, Articulo articulosComprar);
    ~Cliente();
    //Getters
    string getNombre();
    int getFormaPago();
    void getArticulosComprar();
    //setters
    void setNombre(string nombre);
    void setFormaPago(int formaPago);
    void setArticulo(Articulo articulo, int cantidad, float precio);
    //total
    void setTotal(float total);
    float getTotal();
};

class Tienda : Articulo {
private:
    string nombre;
    Articulo inventario[M];
public:
    //Constructors
    Tienda();
    Tienda(string nombre);
    ~Tienda();
    //Setter
    void agregarInventario(Articulo articulo, int indice);
    void setInventario(int cantidad, int indice);
    //Getter
    string getNombre();
    int getCantidad(int indice);
    //Display inventario de tienda
    void displayInventario(void);
};