#include <iostream>
using namespace std;

// Función para calcular los impuestos según los ingresos
float calcularImpuestos(float ingresos) {
    float impuesto = 0;

    if (ingresos > 50000) {
        impuesto += (ingresos - 50000) * 0.30;
        ingresos = 50000;
    }
    if (ingresos > 20000) {
        impuesto += (ingresos - 20000) * 0.20;
        ingresos = 20000;
    }
    if (ingresos > 10000) {
        impuesto += (ingresos - 10000) * 0.10;
    }

    return impuesto;
}

// Funcion para aplicar bonificaciones por dependientes
float aplicarBonificacion(float impuestos, int dependientes) {
    return impuestos - (dependientes * 1500);
}

int main() {
    float ingresos, deducciones, impuestos, impuestosFinales;
    int dependientes;
    char tieneDeducciones;

    // Pedir ingresos
    cout << "Ingrese sus ingresos anuales: ";
    cin >> ingresos;

    // Preguntar por deducciones
    cout << "Tiene deducciones? (s/n): ";
    cin >> tieneDeducciones;

    // Si tiene deducciones, pedir el monto
    if (tieneDeducciones == 's' || tieneDeducciones == 'S') {
        cout << "Ingrese el monto de las deducciones: ";
        cin >> deducciones;
        ingresos -= deducciones;
    }

    // Preguntar cuántos dependientes tiene
    cout << "Ingrese el numero de dependientes: ";
    cin >> dependientes;

    // Calcular impuestos
    impuestos = calcularImpuestos(ingresos);

    // Aplicar bonificacion por dependientes
    impuestosFinales = aplicarBonificacion(impuestos, dependientes);

    // Mostrar el monto final de impuestos
    cout << "El monto de impuestos a pagar despues de aplicar deducciones y bonificaciones es: $" << impuestosFinales << endl;

    return 0;
}
