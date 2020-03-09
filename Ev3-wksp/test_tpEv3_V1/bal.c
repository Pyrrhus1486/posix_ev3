/*
 * bal.c
 *
 *  Created on: 24 janv. 2020
 *      Author: francois
 */

#include <pthread.h>
#include <string.h>
#include <malloc.h>
#include "bal.h"


BAL_int BAL_int_init(const int val){

	BAL_int m=(BAL_int)malloc(sizeof(struct s_BAL_int));
	m->val = val;
	m->dirty = 0;
	pthread_mutex_init(&(m->mutex),0);
	pthread_cond_init(&m->cond,0);

	return m;

}

void BAL_int_write(BAL_int bal, const int val){

	pthread_mutex_lock(&(bal->mutex));
	bal->val=val;
	bal->dirty=1;
	pthread_cond_broadcast(&bal->cond); // réveil tâche en attente de message.
	pthread_mutex_unlock(&bal->mutex);

}

int BAL_int_read(BAL_int bal) {
	int val;
	pthread_mutex_lock(&(bal->mutex));
	while(bal->dirty==0){pthread_cond_wait(&bal->cond, &bal->mutex);}
	val=bal->val;
	bal->dirty=0;
	pthread_mutex_unlock(&(bal->mutex));
	return val;
}
