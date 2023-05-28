#include <iostream>
#include "rlutil.h"
#include <vector>

using namespace std;

void dibujarcuadrado(int posx, int posy);
void dibujardado(int posx, int posy, int num);

void dibujarcuadrado(int posx, int posy){
     for(int x = 0; x < 7; x++){
        for(int y = 0; y < 3; y++){
            rlutil::locate(x + posx, y + posy);
            rlutil::setBackgroundColor(15);
            cout << " ";
        }
    }

}

void dibujardado(int posx, int posy, int num){
    dibujarcuadrado(posx,  posy);

    switch(num){
    case 1:
        rlutil::locate(posx + 3, posy + 1);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)254;
    break;
    case 2:
        rlutil::locate(posx + 5, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 1, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;
    break;
    case 3:
        rlutil::locate(posx + 5, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 1, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;

        rlutil::locate(posx + 3, posy + 1);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)254;
    break;
    case 4:
        rlutil::locate(posx + 5, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 1, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 1, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;

        rlutil::locate(posx + 5, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;
    break;
    case 5:
        rlutil::locate(posx + 5, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 1, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 3, posy + 1);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)254;

        rlutil::locate(posx + 1, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;

        rlutil::locate(posx + 5, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;
    break;
    case 6:
        rlutil::locate(posx + 5, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 1, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 3, posy);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)220;

        rlutil::locate(posx + 3, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;

        rlutil::locate(posx + 1, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;

        rlutil::locate(posx + 5, posy + 2);
        rlutil::setBackgroundColor(15);
        rlutil::setColor(0);
        cout << (char)223;
    break;
    }
}

// Función para verificar las combinaciones ganadoras y calcular los puntajes
int calcularPuntaje(const vector<int>& valores) {
    int puntaje = 0;

    if (puntaje == 0) {
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::locate(1, 15);
        cout << "No hay combinacion ganadora en esta ronda." << endl;
    } else {
        cout << "Puntaje obtenido: " << puntaje << endl;
    }

    return 0;

    // Verificar combinaciones ganadoras

   // 1. Combinación: Menos de 3 dados con valores iguales (cualquier combinación)
    bool tieneMenosDe3Iguales = true;

   for (int i = 1; i <= 6; i++) {
        int contador = 0;
        for (int j = 0; j < 6; j++) {
            if (valores[j] == i)
                contador++;
        }
        if (contador >= 3 && contador <= 5) {
            tieneMenosDe3Iguales = false;
            break;
        }
    }

    if (tieneMenosDe3Iguales) {
        for (int i = 0; i < 6; i++) {
            puntaje += valores[i];
        }
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::locate(1, 15);
        cout << "Jugada: Suma de dados" << endl;
        cout << "Puntaje obtenido: " << puntaje << endl;
        return puntaje;
    } else {
        puntaje = 0;
        return puntaje;
    }
}

   /* // 4. Combinación: Escalera (1, 2, 3, 4, 5, 6)
    bool tieneEscalera = true;

    // Corroboramos si hay escalera
    for (int i = 0; i <= 5; i++) {
        if (valores[i] != i + 1) {
            tieneEscalera = false;
            break;
        }
    }

    if (tieneMenosDe3Iguales && tieneEscalera) {
        // fijamos puntaje en 500
        puntaje = 500;
        // Mostrar nombre de jugada y mensaje de ganar la partida
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::locate(1,15);
        cout << "Jugada: Escalera" << endl;
        rlutil::locate(1,16);
        cout << "Felicidades, ganaste la partida en esta ronda!" << endl;
        return 500;
    }
     else if (tieneMenosDe3Iguales && !tieneEscalera) {
        // Calcular puntaje sumando los valores de los dados
        for (int i = 0; i < 6; i++) {
            puntaje += valores[i];
        }
        // Mostrar nombre de jugada y puntaje obtenido
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::locate(1,15);
        cout << "Jugada: Suma de dados" << endl;
        rlutil::locate(1,16);
        cout << "Puntaje obtenido: " << puntaje << endl;
        return puntaje;
    }
    else{
        puntaje = 0;
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::locate(1, 15);
        cout << "Jugada: Sin combinacion ganadora" << endl;
        rlutil::locate(1, 16);
        cout << "No hay combinacion ganadora en esta ronda." << endl;
        return puntaje;
    }

    // 2. Combinación: 3 dados o más con el mismo valor (hasta 5 iguales)
    int valorMaximo = 0;
    int puntajeMaximo = 0;

    for (int i = 1; i <= 6; i++) {
    int contador = 0;
    for (int j = 0; j < 6; j++) {
        if (valores[j] == i)
            contador++;
    }

    if (contador >= 3 && contador <=5) {
        int puntaje = i * 10;

        if (puntaje > puntajeMaximo) {
            puntajeMaximo = puntaje;
            valorMaximo = i;
            }
        }
    }

    if (puntajeMaximo > 0) {
    // Mostrar nombre de jugada y puntaje obtenido
    rlutil::setBackgroundColor(0);
    rlutil::setColor(15);
    rlutil::locate(1, 15);
    cout << "Jugada: Trio " << valorMaximo << "++" << endl;
    rlutil::locate(1, 16);
    cout << "Puntaje obtenido: " << puntajeMaximo << endl;
    return puntajeMaximo;
    }

    // 3. Combinación: 6 dados iguales (menos para el número 6)
    bool tieneSexteto = true;
    int primerDado = valores[0];
    for (int i = 1; i < 6; i++) {
        if (valores[i] != primerDado || primerDado == 6) {
            tieneSexteto = false;
            break;
        }
    }
    if (tieneSexteto) {
        // Calcular puntaje multiplicando el valor del dado por 50
        puntaje = primerDado * 50;
        // Mostrar nombre de jugada y puntaje obtenido
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::locate(1,15);
        cout << "Jugada: Sexteto " << primerDado << endl;
        rlutil::locate(1,16);
        cout << "Puntaje obtenido: " << puntaje << endl;
        return puntaje;
    }

    // 5. Combinación: Seis 6
    bool tieneSeis6 = true;
    for (int i = 0; i < 6; i++) {
        if (valores[i] != 6) {
            tieneSeis6 = false;
            break;
        }
    }
    if (tieneSeis6) {
        // Mostrar nombre de jugada y mensaje de perder todos los puntos
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::locate(1,15);
        cout << "Jugada: Sexteto6--" << endl;
        rlutil::locate(1,16);
        cout << "Perdiste todos los puntos de la ronda" << endl;
        return 0;
    }

    // Si no se encontró ninguna combinación ganadora, se retorna el puntaje calculado hasta el momento
    return puntaje;*/

