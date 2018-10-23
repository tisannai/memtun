#ifndef MEMTUN_H
#define MEMTUN_H

/**
 * @file   memtun.h
 * @author Tero Isannainen <tero.isannainen@gmail.com>
 * @date   Sun Oct 21 20:14:50 2018
 *
 * @brief  Memory Tunneling.
 *
 */


#include <sixten.h>

typedef void* ( *mt_alloc_f )( void* mm, size_t size );
typedef void* ( *mt_realloc_f )( void* mm, void* ptr, size_t size );
typedef void* ( *mt_free_f )( void* mm, void* ptr );


/**
 * Memory Tunneling interface.
 */
st_struct( mt )
{
    void*        cmm;     /**< Custom Memory Manager, CMM, handle. */
    mt_alloc_f   alloc;   /**< CMM Allocation function. */
    mt_realloc_f realloc; /**< CMM Re-Allocation function. */
    mt_free_f    free;    /**< CMM Free function. */
};


/**
 * Initialize Memtun.
 *
 * @param mt       Memtun.
 * @param cmm      Custom Memory Manager handle.
 * @param alloc    CMM alloc function.
 * @param realloc  CMM realloc function.
 * @param free     CMM free function.
 *
 * @return Initialized Memtun.
 */
mt_t mt_init( mt_t mt, void* cmm, mt_alloc_f alloc, mt_realloc_f realloc, mt_free_f free );


/**
 * Allocate Memtun.
 *
 * Note: Allocation is performed with Sixten default.
 *
 * @return Memtun.
 */
mt_t mt_new( void );


/**
 * Delete Memtun.
 *
 * @param mt Memtun.
 *
 * @return NULL
 */
mt_t mt_del( mt_t mt );


/**
 * Create Memtun for standard allocation functions.
 *
 * This interface to Sixten (or libc) allocators.
 *
 * @return Memtun.
 */
mt_t mt_new_std( void );


/**
 * Allocate with CMM.
 *
 * @param mt   Memtun.
 * @param size Allocation size in bytes.
 *
 * @return Allocated memory (or user defined).
 */
void* mt_alloc( mt_t mt, size_t size );


/**
 * Re-allocate with CMM.
 *
 * @param mt   Memtun.
 * @param ptr  Pointer to previous allocation.
 * @param size New allocation size in bytes.
 *
 * @return Re-allocated memory (or user defined).
 */
void* mt_realloc( mt_t mt, void* ptr, size_t size );


/**
 * Free memory with CMM.
 *
 * @param mt  Memtun.
 * @param ptr Pointer to allocation.
 *
 * @return NULL (or user defined).
 */
void* mt_free( mt_t mt, void* ptr );


#endif
