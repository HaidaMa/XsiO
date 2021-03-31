#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int n;
void Mutari()
{
    printf("\t\t\t X si O\n\n");
    printf("Alegeti o pozitie de la 1 la 9" "\n\n");
    printf("\t\t\t  1 | 2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");
    return;
}
void Tabla(char tabla[][3])
{
    system("cls");
    Mutari();
    printf("\n\n");
    printf("\t\t\t  %c | %c  | %c  \n", tabla[0][0],
           tabla[0][1], tabla[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", tabla[1][0],
           tabla[1][1], tabla[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", tabla[2][0],
           tabla[2][1], tabla[2][2]);
    return;
}

void Generare(char tabla[3][3])
{
    int i, j, n;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            tabla[i][j]=' ';
    return;
}

void Castigator(int tura)
{
    if(tura==1)
        printf("Calculatorul a castigat\n");
    else
        printf("Ai castigat!\n");
    return;
}

int linie(char tabla[3][3])
{
    int i;
    for(i=0;i<3;i++)
    {
        if (tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2] && tabla[i][0] != ' ')
            return 1;
    }
    return 0;
}

int coloana(char tabla[3][3])
{
    int i;
    for(i=0;i<3;i++)
    {
        if(tabla[0][i] == tabla[1][i] && tabla[1][i] == tabla[2][i] && tabla[0][i] != ' ')
            return 1;
    }
    return 0;
}

int diagonala(char tabla[3][3])
{
    if(tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2] && tabla[0][0] != ' ')
        return 1;
    if(tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0] && tabla[0][2] != ' ')
        return 1;
    return 0;
}

int TerminareJoc(char tabla[3][3])
{
    return (linie(tabla) || coloana(tabla) || diagonala(tabla));
}

void XsiO(int tura)
{
    char tabla[3][3];
    int mutari_ramase = 9;

    Generare(tabla);
    srand(time(NULL));

    while(mutari_ramase > 0 && !TerminareJoc(tabla)){
        if(tura == 1){
            printf("Introduceti o pozitie: ");
            int poz;
            scanf("%d", &poz);
            int x = (poz - 1) / 3;
            int y = (poz - 1) % 3;
            if(tabla[x][y] != ' '){
                printf("Pozitia este deja luata!\n");
                continue;
            }
            tabla[x][y] = 'X';
            Tabla(tabla);
        }
        else{
            int x,y;
            do{
                x = rand() % 3;
                y = rand() % 3;
            }while(tabla[x][y] != ' ');
            tabla[x][y] = 'O';
            printf("Calculatorul a pus pe pozitia: %d\n", x * 3 + y + 1);
            Tabla(tabla);
        }
        --mutari_ramase;
        tura = !tura;
    }

    if(TerminareJoc(tabla)){
        Castigator(tura);
    }
    else{
        printf("Jocul s-a terminat la egalitate!\n");
    }
}

int main()
{
    Mutari();
    XsiO(1);
    return 0;
}
