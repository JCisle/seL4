/*
 * Copyright 2019, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */


#ifndef __ARCH_OBJECT_SMMU_H
#define __ARCH_OBJECT_SMMU_H



#define SMMU_SID_CNODE_SLOT_BITS    8 

#define SMMU_CB_CNODE_SLOT_BITS     6

#define SID_INVALID      SMMU_MAX_SID

#define CB_INVALID       SMMU_MAX_CB 


exception_t decodeARMSIDControlInvocation(word_t label, unsigned int length, cptr_t cptr,
											cte_t *srcSlot, cap_t cap, extra_caps_t extraCaps,
											bool_t call, word_t *buffer);

exception_t decodeARMSIDInvocation(word_t label, unsigned int length, cptr_t cptr,
											cte_t *srcSlot, cap_t cap, extra_caps_t extraCaps,
											bool_t call, word_t *buffer);

exception_t decodeARMCBControlInvocation(word_t label, unsigned int length, cptr_t cptr,
											cte_t *srcSlot, cap_t cap, extra_caps_t extraCaps,
											bool_t call, word_t *buffer);

exception_t decodeARMCBInvocation(word_t label, unsigned int length, cptr_t cptr,
											cte_t *srcSlot, cap_t cap, extra_caps_t extraCaps,
											bool_t call, word_t *buffer);
exception_t smmu_delete_cb(cap_t cap);

#endif  /*__ARCH_OBJECT_SMMU_H*/