#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

//variables del tablero
#define rows 15
#define columns 20

char matrix[rows][columns];

//booleanos de impresion
int printed1;
int printed2;
int printed3;
int printed4;
int printed5;
int printed6;

//variables de preguntas
int question;
int questionselect;

int answered1;
int answered2;
int answered3;
int answered4;
int answered5;
int answered6;

//variables de respuesta
char answer1[9];
char answer2[9];
char answer3[9];
char answer4[9];
char answer5[9];
char answer6[9];

int answeredQ;

//variables de respuesta final para rellenar la matriz
char finalans1[9];
char finalans2[9];
char finalans3[9];
char finalans4[9];
char finalans5[9];
char finalans6[9];

//booleanos para rellenar matriz
int stagewordanswered1=0;
int stagewordanswered2=0;
int stagewordanswered3=0;
int stagewordanswered4=0;
int stagewordanswered5=0;
int stagewordanswered6=0;

//variables del juego
int stage=1;
int tries = 3;


void fillMatrix(char matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = '.';
        }
    }

    if (printed1==0){
        if (stage == 1 ){
            if(answered1==1){
                char messi[] = "messi";
                for (int i = 0; i < strlen(messi); i++) {
                    matrix[4 + i][2] = messi[i];
                }
                strcpy(finalans1, messi);
                stagewordanswered1=1;
                printed1=1;
            } else {
                char messih[] = "*****";
                for (int i = 0; i < strlen(messih); i++) {
                    matrix[4 + i][2] = messih[i];
                }
            }
        } else {
            if(answered1==1){
                char mexico[] = "mexico";
                for (int i = 0; i < strlen(mexico); i++) {
                    matrix[4 + i][2] = mexico[i];
                }
                strcpy(finalans1, mexico);
                stagewordanswered1=2;
                printed1=1;
            } else {
                char mexicoh[] = "******";
                for (int i = 0; i < strlen(mexicoh); i++) {
                    matrix[4 + i][2] = mexicoh[i];
                }
            }
        }
    } else {
        switch (stagewordanswered1) {
            case 1:
                for (int i = 0; i < strlen(finalans1); i++) {
                    matrix[4 + i][2] = finalans1[i];
                }
                break;
            case 2:
                for (int i = 0; i < strlen(finalans1); i++) {
                    matrix[4 + i][2] = finalans1[i];
                }
                break;
        }
    }

    if (printed3==0){
        if(stage ==1){
            if (answered3==1){
                char senna[] = "senna";
                for (int i = 0; i < strlen(senna); i++) {
                    matrix[0 + i][7] = senna[i];
                }
                strcpy(finalans3, senna);
                stagewordanswered3=1;
                printed3=1;
            } else {
                char sennah[] = "*****";
                for (int i = 0; i < strlen(sennah); i++) {
                    matrix[0 + i][7] = sennah[i];
                }
            }
        } else {
            if (answered3==1){
                char neymar[] = "neymar";
                for (int i = 0; i < strlen(neymar); i++) {
                    matrix[0 + i][6] = neymar[i];
                }
                strcpy(finalans3, neymar);
                stagewordanswered3=2;
                printed3=1;
            } else {
                char neymarh[] = "******";
                for (int i = 0; i < strlen(neymarh); i++) {
                    matrix[0 + i][6] = neymarh[i];
                }
            }
        }
    } else {
        switch (stagewordanswered3) {
            case 1:
                if(stagewordanswered2==1){
                    for (int i = 0; i < strlen(finalans3); i++) {
                        matrix[0 + i][7] = finalans3[i];
                    }
                } else if (stagewordanswered2==2){
                    for (int i = 0; i < strlen(finalans3); i++) {
                        matrix[0 + i][6] = finalans3[i];
                    }
                } else {
                    if (stage==1){
                        for (int i = 0; i < strlen(finalans3); i++) {
                            matrix[0 + i][7] = finalans3[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans3); i++) {
                            matrix[0 + i][6] = finalans3[i];
                        }
                    }
                }
                break;
            case 2:
                if(stagewordanswered2==1){
                    for (int i = 0; i < strlen(finalans3); i++) {
                        matrix[0 + i][7] = finalans3[i];
                    }
                } else if (stagewordanswered2==2){
                    for (int i = 0; i < strlen(finalans3); i++) {
                        matrix[0 + i][6] = finalans3[i];
                    }
                } else {
                    if (stage==1){
                        for (int i = 0; i < strlen(finalans3); i++) {
                            matrix[0 + i][7] = finalans3[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans3); i++) {
                            matrix[0 + i][6] = finalans3[i];
                        }
                    }
                }
                break;
        }
    }

    if (printed5==0){
        if (stage == 1){
            if(answered5==1){
                char rodman[] = "rodman";
                for (int i = 0; i < strlen(rodman); i++) {
                    matrix[1 + i][12] = rodman[i];
                }
                strcpy(finalans5, rodman);
                stagewordanswered5=1;
                printed5=1;
            } else {
                char rodmanh[] = "******";
                for (int i = 0; i < strlen(rodmanh); i++) {
                    matrix[1 + i][12] = rodmanh[i];
                }
            }
        } else {
            if(answered5==1){
                char radamel[] = "radamel";
                for (int i = 0; i < strlen(radamel); i++) {
                    matrix[1 + i][10] = radamel[i];
                }
                strcpy(finalans5, radamel);
                stagewordanswered5=2;
                printed5=1;
            } else {
                char radamelh[] = "******";
                for (int i = 0; i < strlen(radamelh); i++) {
                    matrix[1 + i][10] = radamelh[i];
                }
            }
        }
    } else {
        switch(stagewordanswered5) {
            case 1:
                //gano rodman
                //depende de solo ans 4
                //depende de solo ans 2
                //depende de ans 2 y 4
                // depende de nadie

                if(stagewordanswered4==1 && stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if (stagewordanswered4==2 && stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if(stagewordanswered4==1 && stage==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered4==2 && stage ==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }
                } else if (stagewordanswered2==1 && stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if(stagewordanswered2==2 && stage == 1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if(stagewordanswered2 == 1 && stage ==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered2 == 2 && stage ==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }
                } else if (stagewordanswered2==1 && stagewordanswered4==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if (stagewordanswered2==2 && stagewordanswered4==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered2==1 && stagewordanswered4==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered2==2 && stagewordanswered4==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }
                } else if (stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if (stage == 2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }
                }
                break;
            case 2:
                if(stagewordanswered4==1 && stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if (stagewordanswered4==2 && stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if(stagewordanswered4==1 && stage==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered4==2 && stage ==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }
                    //depende de solo ans 2
                } else if (stagewordanswered2==1 && stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if(stagewordanswered2==2 && stage == 1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if(stagewordanswered2 == 1 && stage ==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered2 == 2 && stage ==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }

                } else if (stagewordanswered2==1 && stagewordanswered4==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if (stagewordanswered2==2 && stagewordanswered4==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered2==1 && stagewordanswered4==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][11] = finalans5[i];
                    }
                } else if (stagewordanswered2==2 && stagewordanswered4==2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }
                } else if (stage==1){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][12] = finalans5[i];
                    }
                } else if (stage == 2){
                    for (int i = 0; i < strlen(finalans5); i++) {
                        matrix[1 + i][10] = finalans5[i];
                    }
                }
                break;
        }
    }

    if (printed2==0){
        if (stage==1){
            if(answered2==1){
                char america[] = "america";
                for (int i = 0; i < strlen(america); i++) {
                    matrix[4][1 + i] = america[i];
                }
                strcpy(finalans2, america);
                stagewordanswered2=1;
                printed2=1;
            } else {
                char americah[] = "*******";
                for (int i = 0; i < strlen(americah); i++) {
                    matrix[4][1 + i] = americah[i];
                }
            }
        } else {
            if(answered2==1){
                char murray[] = "murray";
                for (int i = 0; i < strlen(murray); i++) {
                    matrix[4][2 + i] = murray[i];
                }
                strcpy(finalans2, murray);
                stagewordanswered2=2;
                printed2=1;
            } else {
                char murrayh[] = "******";
                for (int i = 0; i < strlen(murrayh); i++) {
                    matrix[4][2 + i] = murrayh[i];
                }
            }
        }
    } else {
        switch (stagewordanswered2) {
            case 1:
                for (int i = 0; i < strlen(finalans2); i++) {
                    matrix[4][1 + i] = finalans2[i];
                }
                break;
            case 2:
                for (int i = 0; i < strlen(finalans2); i++) {
                    matrix[4][2 + i] = finalans2[i];
                }
                break;
        }
    }

    if(printed4==0){
        if(stage==1){
            if(answered4==1){
                char federer[] = "federer";
                for (int i = 0; i < strlen(federer); i++) {
                    matrix[1][6 + i] = federer[i];
                }
                strcpy(finalans4, federer);
                stagewordanswered4=1;
                printed4=1;
            } else {
                char federer[] = "*******";
                for (int i = 0; i < strlen(federer); i++) {
                    matrix[1][6 + i] = federer[i];
                }
            }
        } else{
            if(answered4==1){
                char ferrari[] = "ferrari";
                for (int i = 0; i < strlen(ferrari); i++) {
                    matrix[1][5 + i] = ferrari[i];
                }
                strcpy(finalans4, ferrari);
                stagewordanswered4=2;
                printed4=1;
            } else {
                char ferrarih[] = "*******";
                for (int i = 0; i < strlen(ferrarih); i++) {
                    matrix[1][5 + i] = ferrarih[i];
                }
            }
        }
    } else {
        switch (stagewordanswered4) {
            case 1:
                if(stagewordanswered2==1){
                    for (int i = 0; i < strlen(finalans4); i++) {
                        matrix[1][6 + i] = finalans4[i];
                    }
                } else if (stagewordanswered2==2){
                    for (int i = 0; i < strlen(finalans4); i++) {
                        matrix[1][5 + i] = finalans4[i];
                    }
                } else {
                    if (stage==1){
                        for (int i = 0; i < strlen(finalans4); i++) {
                            matrix[1][6 + i] = finalans4[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans4); i++) {
                            matrix[1][5 + i] = finalans4[i];
                        }
                    }
                }
                break;
            case 2:
                if(stagewordanswered2==1){
                    for (int i = 0; i < strlen(finalans4); i++) {
                        matrix[1][6 + i] = finalans4[i];
                    }
                } else if (stagewordanswered2==2){
                    for (int i = 0; i < strlen(finalans4); i++) {
                        matrix[1][5 + i] = finalans4[i];
                    }
                } else {
                    if (stage==1){
                        for (int i = 0; i < strlen(finalans4); i++) {
                            matrix[1][6 + i] = finalans4[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans4); i++) {
                            matrix[1][5 + i] = finalans4[i];
                        }
                    }
                }
                break;
        }
    }

    if(printed6==0){
        if (stage==1){
            if(answered6==1){
                char mclaren[] = "mclaren";
                for (int i = 0; i < strlen(mclaren); i++) {
                    matrix[4][12 + i] = mclaren[i];
                }
                stagewordanswered6=1;
                strcpy(finalans6, mclaren);
                printed6=1;
            } else {
                char mclarenh[] = "*******";
                for (int i = 0; i < strlen(mclarenh); i++) {
                    matrix[4][12 + i] = mclarenh[i];
                }
            }
        } else {
            if(answered6==1){
                char mercedes[] = "mercedes";
                for (int i = 0; i < strlen(mercedes); i++) {
                    matrix[5][10 + i] = mercedes[i];
                }
                strcpy(finalans6, mercedes);
                stagewordanswered6=2;
                printed6=1;
            } else {
                char mercedesh[] = "********";
                for (int i = 0; i < strlen(mercedesh); i++) {
                    matrix[5][10 + i] = mercedesh[i];
                }
            }
        }
    } else {
        switch(stagewordanswered6){
            case 1:
                if (stagewordanswered2==1 && stagewordanswered4==1){
                    if(stagewordanswered5==2){
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][12 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][12 + i] = finalans6[i];
                        }
                    }

                } else if (stagewordanswered2==1 && stagewordanswered4==2){
                    if(stagewordanswered5==2){
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][11 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][11 + i] = finalans6[i];
                        }
                    }


                } else if(stagewordanswered2==2 && stagewordanswered4==1) {
                    if (stagewordanswered5 == 2) {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][10 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][10 + i] = finalans6[i];
                        }
                    }


                } else if (stagewordanswered2==2 && stagewordanswered4==2) {
                    if (stagewordanswered5 == 2) {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][10 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][10 + i] = finalans6[i];
                        }
                    }
                } else if(stage ==1 ){
                    for (int i = 0; i < strlen(finalans6); i++) {
                        matrix[4][12 + i] = finalans6[i];
                    }
                } else {
                    for (int i = 0; i < strlen(finalans6); i++) {
                        matrix[5][10 + i] = finalans6[i];
                    }
                }
                break;
            case 2:
                if (stagewordanswered2==1 && stagewordanswered4==1){
                    if(stagewordanswered5==2){
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][12 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][12 + i] = finalans6[i];
                        }
                    }

                } else if (stagewordanswered2==1 && stagewordanswered4==2){
                    if(stagewordanswered5==2){
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][11 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][11 + i] = finalans6[i];
                        }
                    }


                } else if(stagewordanswered2==2 && stagewordanswered4==1) {
                    if (stagewordanswered5 == 2) {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][10 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][10 + i] = finalans6[i];
                        }
                    }


                } else if (stagewordanswered2==2 && stagewordanswered4==2) {
                    if (stagewordanswered5 == 2) {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[5][10 + i] = finalans6[i];
                        }
                    } else {
                        for (int i = 0; i < strlen(finalans6); i++) {
                            matrix[4][10 + i] = finalans6[i];
                        }
                    }
                } else if(stage ==1 ){
                    for (int i = 0; i < strlen(finalans6); i++) {
                        matrix[4][12 + i] = finalans6[i];
                    }
                } else {
                    for (int i = 0; i < strlen(finalans6); i++) {
                        matrix[5][10 + i] = finalans6[i];
                    }
                }
                break;
        }
    }
}

void printMatrix(char matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void Questions()
{
    if (tries==0){
        pause();
    } else {
        if (stage == 1) {
            printf("\n \nTu profe te hace las siguientes preguntas:\n1. Apellido del mejor jugador de futbol de la historia\n2. Nombre del equipo de futbol mas grande de Mexico\n3. Apellido del piloto brasileno que fallecio en Imola, Italia\n4. Jugador de tenis apodado 'El reloj suizo'\n5. Alero de los Chicago Bulls ganadores del 'Three-peat'\n6. Escuderia color papaya de la formula 1\n");
            printf("Que pregunta quieres contestar?\n");
            scanf("%d", &questionselect);
            switch (questionselect) {
                case 1:
                    if (answered1 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Apellido del mejor jugador de futbol de la historia\nRespuesta: ");
                        scanf(" %8s", answer1);
                    }
                    break;
                case 2:
                    if (answered2 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Nombre del equipo de futbol mas grande de Mexico\nRespuesta: ");
                        scanf(" %8s", answer2);
                    }
                    break;
                case 3:
                    if (answered3 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Apellido del piloto brasileno que fallecio en Imola, Italia\nRespuesta: ");
                        scanf(" %8s", answer3);
                    }
                    break;
                case 4:
                    if (answered4 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Jugador de tenis apodado 'El reloj suizo'\nRespuesta: ");
                        scanf(" %8s", answer4);
                    }
                    break;
                case 5:
                    if (answered5 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Alero de los Chicago Bulls ganadores del 'Three-peat'\nRespuesta: ");
                        scanf(" %8s", answer5);
                    }
                    break;
                case 6:
                    if (answered6 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Escuderia color papaya de la formula 1\nRespuesta: ");
                        scanf(" %8s", answer6);
                    }
                    break;
            }
        } else {
            printf("\nTu profe te hace las siguientes preguntas:\n1. Pais del que es originario el boxeador Saul Alvarez\n2. Andy _____ gano la medalla de oro en tenis en Londres 2012\n3. Nombre del maximo goleador de Brasil\n4. Escuderia con mas campeonatos de constructores de la formula 1\n5. Delantero colombiano conocido como 'El Tigre'\n6. Lewis Hamilton gano 6 campeonatos de pilotos en ...\n");
            printf("Que pregunta quieres contestar?\n");
            scanf("%d", &questionselect);
            switch (questionselect) {
                case 1:
                    if (answered1 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Pais del que es originario el boxeador Saul Alvarez\nRespuesta: ");
                        scanf(" %8s", answer1);
                    }
                    break;
                case 2:
                    if (answered2 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Andy _____ gano la medalla de oro en tenis en Londres 2012\nRespuesta: ");
                        scanf(" %8s", answer2);
                    }
                    break;
                case 3:
                    if (answered3 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Nombre del maximo goleador de Brasil\nRespuesta: ");
                        scanf(" %8s", answer3);
                    }
                    break;
                case 4:
                    if (answered4 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Escuderia con mas campeonatos de constructores de la formula 1\nRespuesta: ");
                        scanf(" %8s", answer4);
                    }
                    break;
                case 5:
                    if (answered5 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Delantero colombiano conocido como 'El Tigre'\nRespuesta: ");
                        scanf(" %8s", answer5);
                    }
                    break;
                case 6:
                    if (answered6 == 1) {
                        printf("Esta pregunta ya la contestaste, tu profe se enoja porque piensa que lo quieres trakalear\n");
                    } else {
                        printf("Lewis Hamilton gano 6 campeonatos de pilotos en ...\nRespuesta: ");
                        scanf(" %8s", answer6);
                    }
                    break;
            }
        }
    }
}

//uao una alarma como sleep,
void sleepalarm(int signum){
}

void CheckAnswers(){
    if(tries==0){
        pause();
    } else {
        if (stage == 1) {
            switch (questionselect) {
                case 1:
                    if (strcmp(answer1, "messi") == 0) {
                        if (answered1 == 1) {
                            break;
                        }
                        printf("\nFelicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ += 1;
                        answered1 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("\nPff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 2:
                    if (strcmp(answer2, "america") == 0) {
                        if (answered2 == 1) {
                            break;
                        }
                        printf("\nFelicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered2 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("\nPff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 3:
                    if (strcmp(answer3, "senna") == 0) {
                        if (answered3 == 1) {
                            break;
                        }
                        printf("\nFelicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered3 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("\nPff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 4:
                    if (strcmp(answer4, "federer") == 0) {
                        if (answered4 == 1) {
                            break;
                        }
                        printf("\nFelicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered4 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("\nPff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 5:
                    if (strcmp(answer5, "rodman") == 0) {
                        if (answered5 == 1) {
                            break;
                        }
                        printf("\nFelicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered5 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("\nPff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 6:
                    if (strcmp(answer6, "mclaren") == 0) {
                        if (answered6 == 1) {
                            break;
                        }
                        printf("\nFelicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered6 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("\nPff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
            }
        } else {
            switch (questionselect) {
                case 1:
                    if (strcmp(answer1, "mexico") == 0) {
                        if (answered1 == 1) {
                            break;
                        }
                        printf("Felicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered1 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("Pff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 2:
                    if (strcmp(answer2, "murray") == 0) {
                        if (answered2 == 1) {
                            break;
                        }
                        printf("Felicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered2 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("Pff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 3:
                    if (strcmp(answer3, "neymar") == 0) {
                        if (answered3 == 1) {
                            break;
                        }
                        printf("Felicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered3 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("Pff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                case 4:
                    if (strcmp(answer4, "ferrari") == 0) {
                        if (answered4 == 1) {
                            break;
                        }
                        printf("Felicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered4 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("Pff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 5:
                    if (strcmp(answer5, "radamel") == 0) {
                        if (answered5 == 1) {
                            break;
                        }
                        printf("Felicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered5 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("Pff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;
                case 6:
                    if (strcmp(answer6, "mercedes") == 0) {
                        if (answered6 == 1) {
                            break;
                        }
                        printf("Felicidades! Respuesta correcta\n");
                        tries = tries - 1;
                        answeredQ++;
                        answered6 = 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    } else {
                        printf("Pff\n Respuesta incorrecta\n");
                        tries = tries - 1;
                        printf("Intentos restantes antes de que cambien las preguntas: %d\n", tries);
                        signal(SIGALRM, sleepalarm);
                        alarm(3);
                        pause();
                    }
                    break;

            }
        }
    }
}
void Update(int signum){
    fillMatrix(matrix);
    sleep(1);
}
void* TryChecker(void* args) {
    while (1) {
        if (tries == 0){
            printf("------------------------------------------------------------ATENCION TU PROFRE ESTA SACANDO OTRA HOJA VA A CAMBIAR LA PROXIMA PREGUNTA------------------------------------------------\n");
            if (stage == 1){
                stage++;
                kill(getpid(), SIGUSR2);
                fillMatrix(matrix);
            } else {
                stage = 1;
                kill(getpid(), SIGUSR2);
                fillMatrix(matrix);
            }
            tries = 3;
        }
    }
}

void* AnsweredQChecker(void* args) {
    while (1) {
        if (answeredQ==6){
            printf("\nEl profe se rie y te dice que ya no van a tener que correr, te da el balon de fut para que se vayan a echar la reta\n");
            kill(getpid(), SIGKILL);
        }
    }
}

void *welcome(){
    printf("El profe de educacion fisica los quiere poner a correr toda la clase!\nTe dice que si logras contestarle unas preguntas no los pondra a correr y podran echar retas de fut\nReglas\n1. El profe esta loko por lo que despues de 3 intentos sean correctos o incorrectos las preguntas las cambiara por completo pero no te apures, si tienes palabras que ya estan bien se van a quedar\n2. No te puedes salir del juego, todo tu grupo depende de ti y no quieres defraudarlos\n3. Solo se aceptan minusculas\n4. No se usan signos de puntuacion ni acentos, es clase de deportes no de espanol\n5. El profe es manoso y hay palabras que apesar de que ya las hayas adivinado tapara algunas letras para hacerlo mas dificil");
}

void FirstCicle_handler(int signum){
    printf("Te presento el tablero:\n");
    fillMatrix(matrix);
    printMatrix(matrix);
}

int main(void) {
    pthread_t threadTry, threadComplete;
    pid_t pidWelcome;
    int statusWelcome, state;

    pidWelcome=fork();

    if (pidWelcome==0){
        welcome();
        sleep (5);
        exit(0);
    }
    waitpid(pidWelcome, &statusWelcome, 0);
    signal(SIGUSR1, FirstCicle_handler);
    signal(SIGUSR2,Update);
    state= pthread_create(&threadTry, NULL, TryChecker, NULL);
    state= pthread_create(&threadComplete, NULL, AnsweredQChecker, NULL);
    for (int i=0; ;i++){
        if (i==0){
            kill(getpid(), SIGUSR1);
            signal(SIGALRM, sleepalarm);
            alarm(5);
            pause();
        }
        Questions();
        CheckAnswers();
        fillMatrix(matrix);
        if (tries==0){
            fillMatrix(matrix);
            signal(SIGALRM, sleepalarm);
            alarm(1);
            pause();
        }
        printMatrix(matrix);
    }
}