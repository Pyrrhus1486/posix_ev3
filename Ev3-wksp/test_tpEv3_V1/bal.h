/*
 * bal.h
 *
 *  Created on: 24 janv. 2020
 *      Author: francois
 */


#ifndef BAL_H_
#define BAL_H_


typedef struct s_BAL_int {
	int val;
	int dirty;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} * BAL_int;


BAL_int BAL_int_init(const int val);

void BAL_int_write(BAL_int bal, const int val);

/**
 * Reads in a shared int
 *\param bal[in] the shared data
 *\return value of the shared data
 * Side effect: shared int is now considered clean
 */
int BAL_int_read(BAL_int bal);

/**
 * Reads in a shared int, while returning if it was dirty
 *\param bal[in] the shared data
 *\param val[out] value of the shared data
 *\return  1 if the shared data was modified since last reading (i.e., dirty), 0 else
 * Side effect: shared int is now considered clean
 */
int BAL_int_read2(BAL_int bal,int *val);


#endif /* BAL_H_ */


