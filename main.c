#include <stdio.h>
#include <stdlib.h>

int main()
{

    int M;
    int N;
    int I;
    int J;



    FILE *Macierz;
    Macierz = fopen("Macierz.txt", "r");
    fscanf(Macierz,"%d %d",&M,&N);
    if (M<=0||N<=0)
    {
        printf("Wymiary tablicy nie moga byc niedodatnie.\n"
               "Nacisnij dowolny przycisk aby zakonczyc");
        getchar();
        return 0;
    }
    printf("Udalo sie odczytac\n");

    printf("Wymiary macierzy to:%dx%d\n",M,N);
    float Matrix[M][N];
    float TransposedMatrix[N][M];
    printf("Oto macierz wczytana z pliku:\n");
    for (I=0; I<M; I++)
    {

        for (J=0; J<N; J++)
        {
            fscanf(Macierz,"%f",&Matrix[I][J]);
            printf("%.3f ",Matrix[I][J]);
            if(J==N-1)
            {
                printf("\n");
            }
        }
    }
    fclose(Macierz);
    for (I=0; I<N; I++)
    {
        for (J=0; J<M; J++)
        {
            TransposedMatrix[I][J]=Matrix[J][I];

        }
    }

    printf("Transpozycja do nowego pliku - nacisnij 1.\n"
           "Transpozycja do konsoli - nacisnij 2.\n");


    int Wybor;

    while (Wybor!=1&&Wybor!=2)
    {
        scanf("%d",&Wybor);
FILE *Transpozycja;

        switch(Wybor)
        {
        case 1:


      Transpozycja = fopen("Transpozycja.txt", "w");
printf("W folderze z programem utworzony zostal plik o nazwie ""transpozycja"", gdzie znajduja sie: \n"
       "transponowana macierz oraz informacje o jej symetrycznosci/antysymetrycznosci.");
for(I=0; I<N; I++)
            {
                for(J=0; J<M; J++)
                {
                    fprintf(Transpozycja,"%.3f ", TransposedMatrix[I][J]);
                    if (J==M-1)
                    {
                        fprintf (Transpozycja," \n");
                    }
                }
            }
            if (M!=N)
            {
                fprintf(Transpozycja,"Podana macierz nie jest ani symetryczna ani antysymetryczna.");
                return 0;

            }
            if (M==N)
            {
                for (I=0; I<M; I++)
                {
                    for(J=0; J<M; J++)
                    {
                        if(Matrix[I][J]!=Matrix[J][I])
                        {
                            fprintf (Transpozycja,"Podana macierz nie jest symetryczna. \n");
                            goto Antysymetriaplik;

                        }
                    }
                } fprintf(Transpozycja,"Podana macierz jest symetryczna. \n"); return 0;
                Antysymetriaplik:
                for (I=0;I<M;I++){
                for(J=0;J<M;J++){
                    if(Matrix[I][J]!=-Matrix[J][I]){
                        fprintf(Transpozycja,"Podana macierz nie jest antysymetryczna. \n");
                        return 0;
           }
    }
} fprintf(Transpozycja,"Podana macierz jest antysymetryczna. \n");

            }
fclose(Transpozycja);

            break;
        case 2:
            for(I=0; I<N; I++)
            {
                for(J=0; J<M; J++)
                {
                    printf("%.3f ", TransposedMatrix[I][J]);
                    if (J==M-1)
                    {
                        printf (" \n");
                    }
                }
            }
            if (M!=N)
            {
                printf("Podana macierz nie jest ani symetryczna ani antysymetryczna. \n");
                return 0;

            }
            if (M==N)
            {
                for (I=0; I<M; I++)
                {
                    for(J=0; J<M; J++)
                    {
                        if(Matrix[I][J]!=Matrix[J][I])
                        {
                            printf ("Podana macierz nie jest symetryczna. \n");
                            goto Antysymetria;

                        }
                    }
                } printf("Podana macierz jest symetryczna. \n"); return 0;
                Antysymetria:
                for (I=0;I<M;I++){
                for(J=0;J<M;J++){
                    if(Matrix[I][J]!=-Matrix[J][I]){
                        printf("Podana macierz nie jest antysymetryczna. \n");
            return 0;
           }
           }
           }
           printf("Podana macierz jest antysymetryczna. \n");
           }

            break;
        default:
            printf("Podano niewlasciwy znak. Wpisz 1 (nowy plik) lub 2 (na ekran).");
            break;
        }
    }

    return 0;
}





