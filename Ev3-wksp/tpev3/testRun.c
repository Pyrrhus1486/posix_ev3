#include "mdd.h"
#include "bal.h"
#include "mdd_gen.h"


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>

MDD_int mon_mdd_int;
MDD_GEN mon_mdd_gen;
BAL_int ma_bal;


void ecrire_mdd_int(MDD_int arg_mdd){

	for (int i=0; i<10; i++){
		MDD_int_write(arg_mdd, i);
		usleep(1000000);
	}
}

void lire_mdd_int(MDD_int arg_mdd){

	for (int i=0; i<10; i++){

		printf("%d",MDD_int_read(arg_mdd));
		usleep(1000000);
	}
}

int main(){

	pthread_t tacheLecteur, tacheEcrivain;
	pthread_create(&tacheEcrivain, 0, ecrire_mdd_int,(void *)1);
	pthread_create(&tacheLecteur, 0, lire_mdd_int,(void *)2);

	pthread_join(tacheEcrivain,NULL);
	pthread_join(tacheLecteur, NULL);

}
