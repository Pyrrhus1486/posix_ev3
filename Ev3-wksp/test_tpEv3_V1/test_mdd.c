#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "mdd.h"
#include "bal.h"
//#include "mdd_gen.h"




#include <sys/types.h>

MDD_int mon_mdd_int;
//MDD_GEN mon_mdd_gen;
BAL_int ma_bal;



void ecrire_mdd_int(MDD_int arg_mdd){

	for (int i=0; i<10; i++){
		MDD_int_write(arg_mdd, i);
		usleep(100000);
	}
}

void lire_mdd_int(MDD_int arg_mdd){
	int buffer;
	for (int i=0; i<10; i++){
		buffer = MDD_int_read(arg_mdd);
		printf("%d", buffer);
		printf("\n");
		//usleep(100000);
	}
}

int main(){

	pthread_t tacheLecteur, tacheEcrivain;
	mon_mdd_int = MDD_int_init(0);

	pthread_create(&tacheEcrivain, NULL, ecrire_mdd_int, mon_mdd_int);

	pthread_create(&tacheLecteur, NULL, lire_mdd_int, mon_mdd_int);

	pthread_join(tacheLecteur, NULL);
	pthread_join(tacheEcrivain,NULL);


	return 0;

}
