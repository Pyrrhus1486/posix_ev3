/*
 * mdd.h
 *
 *  Created on: 25 janv. 2017
 *      Author: grolleau
 */

#ifndef MDD_H_
#define MDD_H_

typedef struct s_MDD_int {
	int val;
	int dirty;
	pthread_mutex_t mutex;
} * MDD_int;

/**
 * Initializes a shared int
 *\param val[in] initial value of the shared data
 *\return the new shared int, memory allocation is done inside the function
 */
MDD_int MDD_int_init(const int val);

/**
 * Writes in a shared int
 *\param mdd[in,out] the shared data
 *\param val[in] value to write in the shared data
 * Side effect: shared int is considered dirty until next reading
 */
void MDD_int_write(MDD_int mdd, const int val);

/**
 * Reads in a shared int
 *\param mdd[in] the shared data
 *\return value of the shared data
 * Side effect: shared int is now considered clean
 */
int MDD_int_read(MDD_int mdd);

/**
 * Reads in a shared int, while returning if it was dirty
 *\param mdd[in] the shared data
 *\param val[out] value of the shared data
 *\return  1 if the shared data was modified since last reading (i.e., dirty), 0 else
 * Side effect: shared int is now considered clean
 */
int MDD_int_read2(MDD_int mdd,int *val);
#endif /* MDD_H_ */
