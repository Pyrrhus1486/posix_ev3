#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "bal.h"
//#include "bal_gen.h"




#include <sys/types.h>


//BAL_GEN ma_bal_gen;
BAL_int ma_bal_int;



void ecrire_bal_int(BAL_int arg_bal){

	for (int i=0; i<10; i++){
		BAL_int_write(arg_bal, i);
		usleep(100000);
	}
}

void lire_bal_int(BAL_int arg_bal){
	int buffer;
	for (int i=0; i<10; i++){
		buffer = BAL_int_read(arg_bal);
		printf("%d", buffer);
		printf("\n");
		//usleep(100000);
	}
}

int main(){

	pthread_t tacheLecteur, tacheEcrivain;
	ma_bal_int = BAL_int_init(0);

	pthread_create(&tacheEcrivain, NULL, ecrire_bal_int, ma_bal_int);

	pthread_create(&tacheLecteur, NULL, lire_bal_int, ma_bal_int);

	pthread_join(tacheLecteur, NULL);
	pthread_join(tacheEcrivain,NULL);


	return 0;

}
