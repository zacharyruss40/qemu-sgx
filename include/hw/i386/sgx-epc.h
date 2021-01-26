/*
 * SGX EPC device
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * Authors:
 *   Sean Christopherson <sean.j.christopherson@intel.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */
#ifndef QEMU_SGX_EPC_H
#define QEMU_SGX_EPC_H

#include "sysemu/hostmem.h"

#define TYPE_SGX_EPC "sgx-epc"
#define SGX_EPC(obj) \
    OBJECT_CHECK(SGXEPCDevice, (obj), TYPE_SGX_EPC)
#define SGX_EPC_CLASS(oc) \
    OBJECT_CLASS_CHECK(SGXEPCDeviceClass, (oc), TYPE_SGX_EPC)
#define SGX_EPC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(SGXEPCDeviceClass, (obj), TYPE_SGX_EPC)

#define SGX_EPC_ADDR_PROP "addr"
#define SGX_EPC_SIZE_PROP "size"
#define SGX_EPC_MEMDEV_PROP "memdev"

/**
 * SGXEPCDevice:
 * @addr: starting guest physical address, where @SGXEPCDevice is mapped.
 *         Default value: 0, means that address is auto-allocated.
 * @hostmem: host memory backend providing memory for @SGXEPCDevice
 */
typedef struct SGXEPCDevice {
    /* private */
    DeviceState parent_obj;

    /* public */
    uint64_t addr;
    HostMemoryBackend *hostmem;
} SGXEPCDevice;

#endif
