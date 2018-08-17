/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 *
 *
 * uData main
 */

#include "abs_data_model.h"
#include "service_mgr.h"
#ifndef UDATA_YLOOP
#include "uData_queue.h"
#endif
int uData_main(void)
{
    int ret = 0;

    /* NOTE:
     * please run the abs data init firstly, then run udata service init */
#ifndef UDATA_YLOOP
    ret = uData_start();
    if (unlikely(ret)) {
        return -1;
    }
#endif

    ret = abs_data_model_init();
    if (unlikely(ret)) {
        return -1;
    }

    ret = uData_service_mgr_init();
    if (unlikely(ret)) {
        return -1;
    }

    ret = uData_service_init();
    if (unlikely(ret)) {
        return -1;
    }

    ret = abs_data_cali_init();
    if (unlikely(ret)) {
        return -1;
    }
    LOG("%s %s successfully\n", uDATA_STR, __func__);
    return 0;
}
