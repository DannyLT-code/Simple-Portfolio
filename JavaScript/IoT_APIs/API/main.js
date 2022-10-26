//var, globales;
// let, variables de scope {};
// const, constantes.

const express = require('express');
const mysql = require('mysql2');

const app = express();
const port = 3000;

//Conversor a json el contenido de una peticion
app.use(express.json())

app.get('/hola', (req, res) => {
    res.send('Hola mundo 2!');
})

app.post('/luz', (req, res) => { 
    //Recibe datos
    //Procesa datos
    //Devuelve respuesta
    const body = req.body;
    const pool = mysql.createPool({
        host: 'endpoint',
        user: 'admin',
        password: '123',
        database: 'dreamhome'
    })

    const conexion = pool.getConnection ((error, connection) => {
        if(error)
            throw error;
        connection.release();
    });

    res.send(`Recibi el valor ${body.valor}`);
})

app.listen(port, () => {
    console.log(`Servicior iniciado en el puerto ${port}`);
})

//Default port = 80;
//port for local testing = 3000;
//tec.mx | pagina.com:8080.

/* 
En C:
int suma(int x, int y){
    return x + y;
}

En JS: 
const suma = function(x, y){
    return x + y;
}

Funciones lambda o Arrow functions:
(parametros) => cuerpo
const suma = (x, y) => x + y; // retorno implicito (no hay return, 1 sola expresion)

//Retorno explicito, + de 1 expresion
const suma = (x, y) => {
    return x + y;
}

const function = () => {
    console.log("...")
}
app.listen(port, function);
}
*/

/*
    const cadena = "Puerto: " + port;
    Interpololacion de cadenas | String literals
    const cadena = `Puerto: ${port}`;
*/