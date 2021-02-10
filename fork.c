#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int a = 0;

void implementacao_neto1(int **a){
    *a = *a + 3;
    struct tm *data_hora_neto1_ini;
    time_t neto1_ini;
    neto1_ini = time(NULL);
    data_hora_neto1_ini = localtime(&neto1_ini);
    
    printf ("Nasceu neto 1 = %d -> Dia: %d/%d/%d, hora: %d:%d:%d\n", getpid(), data_hora_neto1_ini->tm_mday, data_hora_neto1_ini->tm_mon+1, data_hora_neto1_ini->tm_year+1900, data_hora_neto1_ini->tm_hour, data_hora_neto1_ini->tm_min, data_hora_neto1_ini->tm_sec);
    
    sleep(12);
    
    struct tm *data_hora_neto1_fim;
    time_t neto1_fim;
    neto1_fim = time(NULL);
    data_hora_neto1_fim = localtime(&neto1_fim);
    
    int tempo_vida_neto1 = difftime(neto1_fim,neto1_ini);

    printf("O neto 1 nasceu às %d:%d:%d, morreu às %d:%d:%d, morreu com %d anos de vida\n",localtime(&neto1_ini)->tm_hour, localtime(&neto1_ini)->tm_min, localtime(&neto1_ini)->tm_sec, data_hora_neto1_fim->tm_hour, data_hora_neto1_fim->tm_min, data_hora_neto1_fim->tm_sec, tempo_vida_neto1);

    exit(0);
}

void implementacao_neto2(int **a){
    *a = *a + 4;    
    struct tm *data_hora_neto2_ini;
    time_t neto2_ini;
    neto2_ini = time(NULL);
    data_hora_neto2_ini = localtime(&neto2_ini);

    printf ("Nasceu neto 2 = %d -> Dia: %d/%d/%d, hora: %d:%d:%d\n", getpid(), data_hora_neto2_ini->tm_mday, data_hora_neto2_ini->tm_mon+1, data_hora_neto2_ini->tm_year+1900, data_hora_neto2_ini->tm_hour, data_hora_neto2_ini->tm_min, data_hora_neto2_ini->tm_sec);
    
    sleep(18);
    
    struct tm *data_hora_neto2_fim;
    time_t neto2_fim;
    neto2_fim = time(NULL);
    data_hora_neto2_fim = localtime(&neto2_fim);
    
    int tempo_vida_neto2 = difftime(neto2_fim,neto2_ini);

    printf("O neto 2 nasceu às %d:%d:%d, morreu às %d:%d:%d, morreu com %d anos de vida\n",localtime(&neto2_ini)->tm_hour, localtime(&neto2_ini)->tm_min, localtime(&neto2_ini)->tm_sec, data_hora_neto2_fim->tm_hour, data_hora_neto2_fim->tm_min, data_hora_neto2_fim->tm_sec, tempo_vida_neto2);

    exit(0);

}

void implementacao_filho1(int *a){
    *a = *a + 1;
    struct tm *data_hora_filho1_ini;
    time_t filho1_ini;
    filho1_ini = time(NULL);
    data_hora_filho1_ini = localtime(&filho1_ini);
    pid_t neto1;
    printf ("Nasceu filho 1 = %d -> Dia: %d/%d/%d, hora: %d:%d:%d\n", getpid(), data_hora_filho1_ini->tm_mday, data_hora_filho1_ini->tm_mon+1, data_hora_filho1_ini->tm_year+1900, data_hora_filho1_ini->tm_hour, data_hora_filho1_ini->tm_min, data_hora_filho1_ini->tm_sec);
    
    sleep(12);
    neto1 = fork();
    
    if (! neto1){
        implementacao_neto1(&a);
    }
    
    wait(NULL);
    sleep(6);

    struct tm *data_hora_filho1_fim;
    time_t filho1_fim;
    filho1_fim = time(NULL);
    data_hora_filho1_fim = localtime(&filho1_fim);
    
    int tempo_vida_filho1 = difftime(filho1_fim,filho1_ini);

    printf("O filho 1 nasceu às %d:%d:%d, morreu às %d:%d:%d, morreu com %d anos de vida\n",localtime(&filho1_ini)->tm_hour, localtime(&filho1_ini)->tm_min, localtime(&filho1_ini)->tm_sec, data_hora_filho1_fim->tm_hour, data_hora_filho1_fim->tm_min, data_hora_filho1_fim->tm_sec, tempo_vida_filho1);

    exit(0);
}

void implementacao_filho2(int *a){
    *a = *a + 2;
    struct tm *data_hora_filho2_ini;
    time_t filho2_ini;
    filho2_ini = time(NULL);
    data_hora_filho2_ini = localtime(&filho2_ini);
    pid_t neto2;
    printf ("Nasceu filho 2 = %d -> Dia: %d/%d/%d, hora: %d:%d:%d\n", getpid(), data_hora_filho2_ini->tm_mday, data_hora_filho2_ini->tm_mon+1, data_hora_filho2_ini->tm_year+1900, data_hora_filho2_ini->tm_hour, data_hora_filho2_ini->tm_min, data_hora_filho2_ini->tm_sec);
    
    sleep(16);
    neto2 = fork();
    
    if (! neto2){
        implementacao_neto2(&a);
    }
    
    sleep(14);

    struct tm *data_hora_filho2_fim;
    time_t filho2_fim;
    filho2_fim = time(NULL);
    data_hora_filho2_fim = localtime(&filho2_fim);
    
    int tempo_vida_filho2 = difftime(filho2_fim,filho2_ini);

    printf("O filho 2 nasceu às %d:%d:%d, morreu às %d:%d:%d, morreu com %d anos de vida\n",localtime(&filho2_ini)->tm_hour, localtime(&filho2_ini)->tm_min, localtime(&filho2_ini)->tm_sec, data_hora_filho2_fim->tm_hour, data_hora_filho2_fim->tm_min, data_hora_filho2_fim->tm_sec, tempo_vida_filho2);

    exit(0);
}


int main(){
    pid_t filho1, filho2; 
    
    struct tm *data_hora_pai_ini;	
    time_t pai_ini;
	pai_ini = time(NULL);
    data_hora_pai_ini = localtime(&pai_ini);
    
    printf("Pai Nasceu, PID = %d -> Dia: %d/%d/%d, hora: %d:%d:%d\n", getpid(), data_hora_pai_ini->tm_mday, data_hora_pai_ini->tm_mon+1, data_hora_pai_ini->tm_year+1900, data_hora_pai_ini->tm_hour, data_hora_pai_ini->tm_min, data_hora_pai_ini->tm_sec);
   
    sleep(14);
    filho1 = fork();
    
    if(! filho1){
        implementacao_filho1(&a);
    }

    sleep(2);
    filho2 = fork();
    
    if(! filho2){
        implementacao_filho2(&a);
    }

    wait(NULL);
    sleep(16);
    
    struct tm *data_hora_pai_fim;
    time_t pai_fim;
    pai_fim = time(NULL);
    data_hora_pai_fim = localtime(&pai_fim);
    
    int tempo_vida_pai = difftime(pai_fim,pai_ini);

    printf("O pai nasceu às %d:%d:%d, morreu às %d:%d:%d, morreu com %d anos de vida\n",localtime(&pai_ini)->tm_hour, localtime(&pai_ini)->tm_min, localtime(&pai_ini)->tm_sec, data_hora_pai_fim->tm_hour, data_hora_pai_fim->tm_min, data_hora_pai_fim->tm_sec, tempo_vida_pai);
    exit(0);

    return 0;
}