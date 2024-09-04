#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int valor1 = 100;
    int valor2 = 50;
    int resultado;

    resultado = add(valor1, valor2);

    if (resultado > 100) {
        printf("Resultado é maior que 100\n");
    } else {
        printf("Resultado é menor que 100\n");
    }
    return 0;
}


