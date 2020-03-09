/*
 * mdd.c
 *
 *  Created on: 25 janv. 2017
 *      Author: francois
 */
#include <pthread.h>
#include <string.h>
#include <malloc.h>
#include "mdd_gen.h"

/**
 * Initializes a shared int
 *\param buff[in] initial value of the shared data
 *\return the new shared int, memory allocation is done inside the function
 */
MDD_GEN MDD_GEN_init(int arg_size, void *arg_buff) {

	MDD_GEN m=(MDD_GEN)malloc(sizeof(struct s_MDD_GEN));
	m->size=arg_size;
	m->buff = malloc(arg_size);
	if(arg_buff){
	memcpy(m->buff, arg_buff, arg_size);
	}
	else{
		memset(m->buff, 0, m->size);
	}
	m->dirty=0;
	pthread_mutex_init(&(m->mutex),0);

	return m;
}


/**
 * Writes in a shared int
 *\param mdd[in,out] the shared data
 *\param buff[in] value to write in the shared data
 */
void MDD_GEN_write(MDD_GEN mdd, const void *buff) {
	pthread_mutex_lock(&(mdd->mutex));
	memcpy(mdd->buff, buff, mdd->size);
	mdd->dirty=1;
	pthread_mutex_unlock(&(mdd->mutex));
}
/**
 * Reads in a shared int
 *\param mdd[in] the shared data
 *\return value of the shared data

}
/**
 * Reads in a shared int, while returning if it was dirty
 *\param mdd[in] the shared data
 *\param val[out] value of the shared data
 *\return  1 if the shared data was modified since last reading (i.e., dirty), 0 else
 */
int MDD_GEN_read2(MDD_GEN mdd, void *buff) {
	int dirty;
	pthread_mutex_lock(&(mdd->mutex));
	memcpy(buff, mdd->buff, mdd->size);
	dirty=mdd->dirty;
	mdd->dirty=0;
	pthread_mutex_unlock(&(mdd->mutex));
	return dirty;

}
