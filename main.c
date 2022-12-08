#include <stdio.h>
#include <stdlib.h>

/*Sieb des Eratosthenes*/
int primzahlsieb(int array[], int ende) {
    int i = 1, j = 0;

    for (i = 1; i <= ende; i++) {
        array[i] = i;
    }

    for (i = 2; i <= ende / 2; i++) {
        if (array[i]) {
            for (j = 2 * i; j <= ende; j += i) {
                array[j] = 0;
            }
        }
    }
}

int main() {
    int max_size = 100, z = 0, ende = 0, clear = 0, *array;

    /*Initiale Speichergröße von 100 zuweisen*/
    if ((array = (int *) malloc(max_size + 1 * sizeof(int))) == NULL) {
        printf("Programmabbruch aufgrund Speicherplatzmangel abgebrochen...");
        return 404;
    }


    /*Speicher bei Bedarf um die Größe vom Array neu allokieren*/
    while (clear == 0) {
        printf("Bis wohin sollen die Primzahlen berechnet werden (Ende=0) ? ");
        scanf("%ld", &ende);

        if (ende == 0) {
            printf("\nSie haben die Eingabe mit 0 beendet.");
            break;
        }


        if (ende > max_size) {
            max_size = ende;
            if ((array = (int *) realloc(array, (max_size + 1) * sizeof(long int))) == NULL) {
                printf("Programmabbruch aufgrund Speicherplatzmangel abgebrochen...");
                return 404;
            }
        }


        /*Sieb des Eratosthenes anwenden und anschließend rinten*/
        primzahlsieb(array, ende);
        for (int i = 2; i <= ende; i++)
            if (array[i])
                printf("%-10d", i);
        printf("\n");
    }

    return 0;
}
