#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "mdd_gen.h"





#include <sys/types.h>


MDD_GEN mon_mdd_gen;




void ecrire_mdd_gen(MDD_GEN arg_mdd){

	for (int i=0; i<10; i++){
		MDD_GEN_write(arg_mdd, &i);
		usleep(100000);
	}
}

void lire_mdd_gen(MDD_GEN arg_mdd){
	int buffer;
	for (int i=0; i<10; i++){
		MDD_GEN_read2(arg_mdd, (void*)&buffer);
		printf("%d", buffer);
		printf("\n");
		usleep(100000);
	}
}

int main(){
	int arg = 4;
	pthread_t tacheLecteur, tacheEcrivain;
	mon_mdd_gen = MDD_GEN_init(sizeof(int), &arg );

	pthread_create(&tacheEcrivain, NULL, ecrire_mdd_gen, mon_mdd_gen);

	pthread_create(&tacheLecteur, NULL, lire_mdd_gen, mon_mdd_gen);

	pthread_join(tacheLecteur, NULL);
	pthread_join(tacheEcrivain,NULL);


	return 0;

}
