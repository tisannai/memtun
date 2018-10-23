/**
 * @file   memtun.c
 * @author Tero Isannainen <tero.isannainen@gmail.com>
 * @date   Sun Oct 21 20:14:50 2018
 *
 * @brief  Memory Tunneling.
 *
 */


#include "memtun.h"


/* ------------------------------------------------------------
 * Internal declarations:
 */

static void* mt_malloc_wrap( void* cmm, size_t size );
static void* mt_realloc_wrap( void* cmm, void* ptr, size_t size );
static void* mt_free_wrap( void* cmm, void* ptr );



/* ------------------------------------------------------------
 * Memory Tunnelling:
 */

mt_t mt_init( mt_t mt, void* cmm, mt_alloc_f alloc, mt_realloc_f realloc, mt_free_f free )
{
    mt->cmm = cmm;
    mt->alloc = alloc;
    mt->realloc = realloc;
    mt->free = free;

    return mt;
}


mt_t mt_new( void )
{
    return st_new( mt_s );
}


mt_t mt_del( mt_t mt )
{
    st_del( mt );
    return NULL;
}


mt_t mt_new_std( void )
{
    return mt_init( st_new( mt_s ), NULL, mt_malloc_wrap, mt_realloc_wrap, mt_free_wrap );
}


void* mt_alloc( mt_t mt, size_t size )
{
    if ( mt )
        return mt->alloc( mt, size );
    else
        return st_alloc( size );
}


void* mt_realloc( mt_t mt, void* ptr, size_t size )
{
    if ( mt )
        return mt->realloc( mt, ptr, size );
    else
        return st_realloc( ptr, size );
}


void* mt_free( mt_t mt, void* ptr )
{
    if ( mt ) {
        return mt->free( mt, ptr );
    } else {
        st_del( ptr );
        return NULL;
    }
}




/* ------------------------------------------------------------
 * Internal support:
 */

static void* mt_malloc_wrap( void* cmm, size_t size )
{
    return st_alloc( size );
}

static void* mt_realloc_wrap( void* cmm, void* ptr, size_t size )
{
    return st_realloc( ptr, size );
}

static void* mt_free_wrap( void* cmm, void* ptr )
{
    st_del( ptr );
    return NULL;
}
