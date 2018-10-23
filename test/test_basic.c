#include "unity.h"
#include "memtun.h"

void test_basic( void )
{
    mt_t mt;
    mt_t obj;

    mt = mt_new_std();
    obj = mt_alloc( mt, sizeof( mt_s ) );
    TEST_ASSERT_TRUE( obj != NULL );
    obj = (mt_t) mt_free( mt, obj );
    TEST_ASSERT_TRUE( obj == NULL );
}
