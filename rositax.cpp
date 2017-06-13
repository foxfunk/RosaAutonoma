#include<stdio.h>
#include<cmath>


/*
M-->matriz ampliada
n-->numero de ecuaciones
 */
void gauss_jordan(double M[20][20], int n) {
    double may; //variable para almacenar el mayor de la columna k
    int ind; //	indice del mayor-->indice de may
    double aux;
    double pivote;

    for (int k = 0; k < n; k++) {//recorrer columnas de la matriz reducida
        may = abs(M[k][k]);
        ind = k;
        //recorrer filas de la columna k para buscar el indice del mayor
        for (int l = k + 1; l < n; l++) {
            if (may < abs(M[l][k])) {
                may = abs(M[l][k]);
                ind = l;
            }

        }

        //cambiar filas
        if (k != ind) {
            for (int i = 0; i < n + 1; i++) {
                aux = M[k][i];
                M[k][i] = M[ind][i];
                M[ind][i] = aux;
            }

        }
        if (M[k][k] == 0) {
            printf("no tiene solucion");
            printf("\n");

            break;


        } else {

            for (int i = 0; i < n; i++) {//recorrer fila
                if (i != k) {
                    pivote = -M[i][k];
                    for (int j = k; j < n + 1; j++) {//recorrer elementos de una fila

                        M[i][j] = M[i][j] + pivote * M[k][j] / M[k][k];
                    }
                } else {
                    pivote = M[k][k];
                    for (int j = k; j < n + 1; j++) {
                        M[i][j] = M[i][j] / pivote;
                    }
                }
            }
        }


    }
}

void ingresar_coeficientes(double M[20][20], int n) {

    printf("ingrese ecuaciones:");
    printf("\n");
    for (int i = 0; i < n; i++) {
      
          printf("Fila %d : \n",i+1);
        for (int j = 0; j < n + 1; j++) {
       
            scanf("%lf", &M[i][j]);
           
        }
    }
}

int main() {
    int n;
    double M[20][20];
    printf("ingrese numero de ecuaciones:");
    scanf("%d", &n);
    ingresar_coeficientes(M, n);

    printf("matriz ampliada:");
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
          
            printf("[%g]", M[i][j]);
        }
        printf("\n");
    }
    printf("escalonada");
    printf("\n");
    gauss_jordan(M, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("[%g]", M[i][j]);
        }
        printf("\n");
    }
    printf("Solucion");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("X%d = %g ", i + 1, M[i][n]);

    }
    printf("\n");
    return 0;
}
