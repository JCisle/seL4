/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <types.h>
#include <machine/registerset.h>
#include <arch/machine.h>
#include <plat/machine/hardware.h>

word_t PURE getRestartPC(tcb_t *thread)
{
    return getRegister(thread, FaultIP);
}

void setNextPC(tcb_t *thread, word_t v)
{
    setRegister(thread, NEXT_PC_REG, v);
}

BOOT_CODE void map_kernel_devices(void)
{
    for (int i = 0; i < ARRAY_SIZE(kernel_devices); i++) {
        /* all frames are supposed to describe device memory, so they should
         * never be marked as executable.
         */
        assert(kernel_devices[i]->armExecuteNever);
        map_kernel_frame(kernel_devices[i].paddr,
                         kernel_devices[i].pptr,
                         VMKernelOnly,
                         vm_attributes_new(kernel_devices[i].armExecuteNever,
                                           false, false));
        if (!kernel_devices[i].userAvailable) {
            p_region_t reg = {
                .start = kernel_devices[i].paddr,
                .end = kernel_devices[i].paddr + BIT(PAGE_BITS),
            };
            reserve_region(reg);
        }
    }
}

