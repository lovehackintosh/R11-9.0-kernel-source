/* Copyright (c) 2016, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ASM_HARDWARE_DEBUGV8_H
#define __ASM_HARDWARE_DEBUGV8_H

#include <linux/types.h>

/* Accessors for CP14 registers */
#define dbg_read(reg)			RCP14_##reg()
#define dbg_write(val, reg)		WCP14_##reg(val)

/* MRC14 registers */
#define MRC14(op1, crn, crm, op2)					\
({									\
uint32_t val;								\
asm volatile("mrc p14, "#op1", %0, "#crn", "#crm", "#op2 : "=r" (val));	\
val;									\
})

/* MCR14 registers */
#define MCR14(val, op1, crn, crm, op2)					\
({									\
asm volatile("mcr p14, "#op1", %0, "#crn", "#crm", "#op2 : : "r" (val));\
})

/*
 * Debug Registers
 *
 * Read only
 * DBGDIDR, DBGDSCRint, DBGDTRRXint, DBGDRAR, DBGOSLSR, DBGOSSRR, DBGDSAR,
 * DBGAUTHSTATUS, DBGDEVID2, DBGDEVID1, DBGDEVID
 *
 * Write only
 * DBGDTRTXint, DBGOSLAR
 */
#define RCP14_DBGDIDR()			MRC14(0, c0, c0, 0)
#define RCP14_DBGDSCRint()		MRC14(0, c0, c1, 0)
#define RCP14_DBGDCCINT()		MRC14(0, c0, c2, 0)
#define RCP14_DBGDTRRXint()		MRC14(0, c0, c5, 0)
#define RCP14_DBGWFAR()			MRC14(0, c0, c6, 0)
#define RCP14_DBGVCR()			MRC14(0, c0, c7, 0)
#define RCP14_DBGDTRRXext()		MRC14(0, c0, c0, 2)
#define RCP14_DBGDSCRext()		MRC14(0, c0, c2, 2)
#define RCP14_DBGDTRTXext()		MRC14(0, c0, c3, 2)
#define RCP14_DBGOSECCR()		MRC14(0, c0, c6, 2)
#define RCP14_DBGBVR0()			MRC14(0, c0, c0, 4)
#define RCP14_DBGBVR1()			MRC14(0, c0, c1, 4)
#define RCP14_DBGBVR2()			MRC14(0, c0, c2, 4)
#define RCP14_DBGBVR3()			MRC14(0, c0, c3, 4)
#define RCP14_DBGBVR4()			MRC14(0, c0, c4, 4)
#define RCP14_DBGBVR5()			MRC14(0, c0, c5, 4)
#define RCP14_DBGBVR6()			MRC14(0, c0, c6, 4)
#define RCP14_DBGBVR7()			MRC14(0, c0, c7, 4)
#define RCP14_DBGBVR8()			MRC14(0, c0, c8, 4)
#define RCP14_DBGBVR9()			MRC14(0, c0, c9, 4)
#define RCP14_DBGBVR10()		MRC14(0, c0, c10, 4)
#define RCP14_DBGBVR11()		MRC14(0, c0, c11, 4)
#define RCP14_DBGBVR12()		MRC14(0, c0, c12, 4)
#define RCP14_DBGBVR13()		MRC14(0, c0, c13, 4)
#define RCP14_DBGBVR14()		MRC14(0, c0, c14, 4)
#define RCP14_DBGBVR15()		MRC14(0, c0, c15, 4)
#define RCP14_DBGBCR0()			MRC14(0, c0, c0, 5)
#define RCP14_DBGBCR1()			MRC14(0, c0, c1, 5)
#define RCP14_DBGBCR2()			MRC14(0, c0, c2, 5)
#define RCP14_DBGBCR3()			MRC14(0, c0, c3, 5)
#define RCP14_DBGBCR4()			MRC14(0, c0, c4, 5)
#define RCP14_DBGBCR5()			MRC14(0, c0, c5, 5)
#define RCP14_DBGBCR6()			MRC14(0, c0, c6, 5)
#define RCP14_DBGBCR7()			MRC14(0, c0, c7, 5)
#define RCP14_DBGBCR8()			MRC14(0, c0, c8, 5)
#define RCP14_DBGBCR9()			MRC14(0, c0, c9, 5)
#define RCP14_DBGBCR10()		MRC14(0, c0, c10, 5)
#define RCP14_DBGBCR11()		MRC14(0, c0, c11, 5)
#define RCP14_DBGBCR12()		MRC14(0, c0, c12, 5)
#define RCP14_DBGBCR13()		MRC14(0, c0, c13, 5)
#define RCP14_DBGBCR14()		MRC14(0, c0, c14, 5)
#define RCP14_DBGBCR15()		MRC14(0, c0, c15, 5)
#define RCP14_DBGWVR0()			MRC14(0, c0, c0, 6)
#define RCP14_DBGWVR1()			MRC14(0, c0, c1, 6)
#define RCP14_DBGWVR2()			MRC14(0, c0, c2, 6)
#define RCP14_DBGWVR3()			MRC14(0, c0, c3, 6)
#define RCP14_DBGWVR4()			MRC14(0, c0, c4, 6)
#define RCP14_DBGWVR5()			MRC14(0, c0, c5, 6)
#define RCP14_DBGWVR6()			MRC14(0, c0, c6, 6)
#define RCP14_DBGWVR7()			MRC14(0, c0, c7, 6)
#define RCP14_DBGWVR8()			MRC14(0, c0, c8, 6)
#define RCP14_DBGWVR9()			MRC14(0, c0, c9, 6)
#define RCP14_DBGWVR10()		MRC14(0, c0, c10, 6)
#define RCP14_DBGWVR11()		MRC14(0, c0, c11, 6)
#define RCP14_DBGWVR12()		MRC14(0, c0, c12, 6)
#define RCP14_DBGWVR13()		MRC14(0, c0, c13, 6)
#define RCP14_DBGWVR14()		MRC14(0, c0, c14, 6)
#define RCP14_DBGWVR15()		MRC14(0, c0, c15, 6)
#define RCP14_DBGWCR0()			MRC14(0, c0, c0, 7)
#define RCP14_DBGWCR1()			MRC14(0, c0, c1, 7)
#define RCP14_DBGWCR2()			MRC14(0, c0, c2, 7)
#define RCP14_DBGWCR3()			MRC14(0, c0, c3, 7)
#define RCP14_DBGWCR4()			MRC14(0, c0, c4, 7)
#define RCP14_DBGWCR5()			MRC14(0, c0, c5, 7)
#define RCP14_DBGWCR6()			MRC14(0, c0, c6, 7)
#define RCP14_DBGWCR7()			MRC14(0, c0, c7, 7)
#define RCP14_DBGWCR8()			MRC14(0, c0, c8, 7)
#define RCP14_DBGWCR9()			MRC14(0, c0, c9, 7)
#define RCP14_DBGWCR10()		MRC14(0, c0, c10, 7)
#define RCP14_DBGWCR11()		MRC14(0, c0, c11, 7)
#define RCP14_DBGWCR12()		MRC14(0, c0, c12, 7)
#define RCP14_DBGWCR13()		MRC14(0, c0, c13, 7)
#define RCP14_DBGWCR14()		MRC14(0, c0, c14, 7)
#define RCP14_DBGWCR15()		MRC14(0, c0, c15, 7)
#define RCP14_DBGDRAR()			MRC14(0, c1, c0, 0)
#define RCP14_DBGBXVR0()		MRC14(0, c1, c0, 1)
#define RCP14_DBGBXVR1()		MRC14(0, c1, c1, 1)
#define RCP14_DBGBXVR2()		MRC14(0, c1, c2, 1)
#define RCP14_DBGBXVR3()		MRC14(0, c1, c3, 1)
#define RCP14_DBGBXVR4()		MRC14(0, c1, c4, 1)
#define RCP14_DBGBXVR5()		MRC14(0, c1, c5, 1)
#define RCP14_DBGBXVR6()		MRC14(0, c1, c6, 1)
#define RCP14_DBGBXVR7()		MRC14(0, c1, c7, 1)
#define RCP14_DBGBXVR8()		MRC14(0, c1, c8, 1)
#define RCP14_DBGBXVR9()		MRC14(0, c1, c9, 1)
#define RCP14_DBGBXVR10()		MRC14(0, c1, c10, 1)
#define RCP14_DBGBXVR11()		MRC14(0, c1, c11, 1)
#define RCP14_DBGBXVR12()		MRC14(0, c1, c12, 1)
#define RCP14_DBGBXVR13()		MRC14(0, c1, c13, 1)
#define RCP14_DBGBXVR14()		MRC14(0, c1, c14, 1)
#define RCP14_DBGBXVR15()		MRC14(0, c1, c15, 1)
#define RCP14_DBGOSLSR()		MRC14(0, c1, c1, 4)
#define RCP14_DBGOSSRR()		MRC14(0, c1, c2, 4)
#define RCP14_DBGOSDLR()		MRC14(0, c1, c3, 4)
#define RCP14_DBGPRCR()			MRC14(0, c1, c4, 4)
#define RCP14_DBGPRSR()			MRC14(0, c1, c5, 4)
#define RCP14_DBGDSAR()			MRC14(0, c2, c0, 0)
#define RCP14_DBGITCTRL()		MRC14(0, c7, c0, 4)
#define RCP14_DBGCLAIMSET()		MRC14(0, c7, c8, 6)
#define RCP14_DBGCLAIMCLR()		MRC14(0, c7, c9, 6)
#define RCP14_DBGAUTHSTATUS()		MRC14(0, c7, c14, 6)
#define RCP14_DBGDEVID2()		MRC14(0, c7, c0, 7)
#define RCP14_DBGDEVID1()		MRC14(0, c7, c1, 7)
#define RCP14_DBGDEVID()		MRC14(0, c7, c2, 7)

#define WCP14_DBGDCCINT(val)		MCR14(val, 0, c0, c2, 0)
#define WCP14_DBGDTRTXint(val)		MCR14(val, 0, c0, c5, 0)
#define WCP14_DBGWFAR(val)		MCR14(val, 0, c0, c6, 0)
#define WCP14_DBGVCR(val)		MCR14(val, 0, c0, c7, 0)
#define WCP14_DBGDTRRXext(val)		MCR14(val, 0, c0, c0, 2)
#define WCP14_DBGDSCRext(val)		MCR14(val, 0, c0, c2, 2)
#define WCP14_DBGDTRTXext(val)		MCR14(val, 0, c0, c3, 2)
#define WCP14_DBGOSECCR(val)		MCR14(val, 0, c0, c6, 2)
#define WCP14_DBGBVR0(val)		MCR14(val, 0, c0, c0, 4)
#define WCP14_DBGBVR1(val)		MCR14(val, 0, c0, c1, 4)
#define WCP14_DBGBVR2(val)		MCR14(val, 0, c0, c2, 4)
#define WCP14_DBGBVR3(val)		MCR14(val, 0, c0, c3, 4)
#define WCP14_DBGBVR4(val)		MCR14(val, 0, c0, c4, 4)
#define WCP14_DBGBVR5(val)		MCR14(val, 0, c0, c5, 4)
#define WCP14_DBGBVR6(val)		MCR14(val, 0, c0, c6, 4)
#define WCP14_DBGBVR7(val)		MCR14(val, 0, c0, c7, 4)
#define WCP14_DBGBVR8(val)		MCR14(val, 0, c0, c8, 4)
#define WCP14_DBGBVR9(val)		MCR14(val, 0, c0, c9, 4)
#define WCP14_DBGBVR10(val)		MCR14(val, 0, c0, c10, 4)
#define WCP14_DBGBVR11(val)		MCR14(val, 0, c0, c11, 4)
#define WCP14_DBGBVR12(val)		MCR14(val, 0, c0, c12, 4)
#define WCP14_DBGBVR13(val)		MCR14(val, 0, c0, c13, 4)
#define WCP14_DBGBVR14(val)		MCR14(val, 0, c0, c14, 4)
#define WCP14_DBGBVR15(val)		MCR14(val, 0, c0, c15, 4)
#define WCP14_DBGBCR0(val)		MCR14(val, 0, c0, c0, 5)
#define WCP14_DBGBCR1(val)		MCR14(val, 0, c0, c1, 5)
#define WCP14_DBGBCR2(val)		MCR14(val, 0, c0, c2, 5)
#define WCP14_DBGBCR3(val)		MCR14(val, 0, c0, c3, 5)
#define WCP14_DBGBCR4(val)		MCR14(val, 0, c0, c4, 5)
#define WCP14_DBGBCR5(val)		MCR14(val, 0, c0, c5, 5)
#define WCP14_DBGBCR6(val)		MCR14(val, 0, c0, c6, 5)
#define WCP14_DBGBCR7(val)		MCR14(val, 0, c0, c7, 5)
#define WCP14_DBGBCR8(val)		MCR14(val, 0, c0, c8, 5)
#define WCP14_DBGBCR9(val)		MCR14(val, 0, c0, c9, 5)
#define WCP14_DBGBCR10(val)		MCR14(val, 0, c0, c10, 5)
#define WCP14_DBGBCR11(val)		MCR14(val, 0, c0, c11, 5)
#define WCP14_DBGBCR12(val)		MCR14(val, 0, c0, c12, 5)
#define WCP14_DBGBCR13(val)		MCR14(val, 0, c0, c13, 5)
#define WCP14_DBGBCR14(val)		MCR14(val, 0, c0, c14, 5)
#define WCP14_DBGBCR15(val)		MCR14(val, 0, c0, c15, 5)
#define WCP14_DBGWVR0(val)		MCR14(val, 0, c0, c0, 6)
#define WCP14_DBGWVR1(val)		MCR14(val, 0, c0, c1, 6)
#define WCP14_DBGWVR2(val)		MCR14(val, 0, c0, c2, 6)
#define WCP14_DBGWVR3(val)		MCR14(val, 0, c0, c3, 6)
#define WCP14_DBGWVR4(val)		MCR14(val, 0, c0, c4, 6)
#define WCP14_DBGWVR5(val)		MCR14(val, 0, c0, c5, 6)
#define WCP14_DBGWVR6(val)		MCR14(val, 0, c0, c6, 6)
#define WCP14_DBGWVR7(val)		MCR14(val, 0, c0, c7, 6)
#define WCP14_DBGWVR8(val)		MCR14(val, 0, c0, c8, 6)
#define WCP14_DBGWVR9(val)		MCR14(val, 0, c0, c9, 6)
#define WCP14_DBGWVR10(val)		MCR14(val, 0, c0, c10, 6)
#define WCP14_DBGWVR11(val)		MCR14(val, 0, c0, c11, 6)
#define WCP14_DBGWVR12(val)		MCR14(val, 0, c0, c12, 6)
#define WCP14_DBGWVR13(val)		MCR14(val, 0, c0, c13, 6)
#define WCP14_DBGWVR14(val)		MCR14(val, 0, c0, c14, 6)
#define WCP14_DBGWVR15(val)		MCR14(val, 0, c0, c15, 6)
#define WCP14_DBGWCR0(val)		MCR14(val, 0, c0, c0, 7)
#define WCP14_DBGWCR1(val)		MCR14(val, 0, c0, c1, 7)
#define WCP14_DBGWCR2(val)		MCR14(val, 0, c0, c2, 7)
#define WCP14_DBGWCR3(val)		MCR14(val, 0, c0, c3, 7)
#define WCP14_DBGWCR4(val)		MCR14(val, 0, c0, c4, 7)
#define WCP14_DBGWCR5(val)		MCR14(val, 0, c0, c5, 7)
#define WCP14_DBGWCR6(val)		MCR14(val, 0, c0, c6, 7)
#define WCP14_DBGWCR7(val)		MCR14(val, 0, c0, c7, 7)
#define WCP14_DBGWCR8(val)		MCR14(val, 0, c0, c8, 7)
#define WCP14_DBGWCR9(val)		MCR14(val, 0, c0, c9, 7)
#define WCP14_DBGWCR10(val)		MCR14(val, 0, c0, c10, 7)
#define WCP14_DBGWCR11(val)		MCR14(val, 0, c0, c11, 7)
#define WCP14_DBGWCR12(val)		MCR14(val, 0, c0, c12, 7)
#define WCP14_DBGWCR13(val)		MCR14(val, 0, c0, c13, 7)
#define WCP14_DBGWCR14(val)		MCR14(val, 0, c0, c14, 7)
#define WCP14_DBGWCR15(val)		MCR14(val, 0, c0, c15, 7)
#define WCP14_DBGBXVR0(val)		MCR14(val, 0, c1, c0, 1)
#define WCP14_DBGBXVR1(val)		MCR14(val, 0, c1, c1, 1)
#define WCP14_DBGBXVR2(val)		MCR14(val, 0, c1, c2, 1)
#define WCP14_DBGBXVR3(val)		MCR14(val, 0, c1, c3, 1)
#define WCP14_DBGBXVR4(val)		MCR14(val, 0, c1, c4, 1)
#define WCP14_DBGBXVR5(val)		MCR14(val, 0, c1, c5, 1)
#define WCP14_DBGBXVR6(val)		MCR14(val, 0, c1, c6, 1)
#define WCP14_DBGBXVR7(val)		MCR14(val, 0, c1, c7, 1)
#define WCP14_DBGBXVR8(val)		MCR14(val, 0, c1, c8, 1)
#define WCP14_DBGBXVR9(val)		MCR14(val, 0, c1, c9, 1)
#define WCP14_DBGBXVR10(val)		MCR14(val, 0, c1, c10, 1)
#define WCP14_DBGBXVR11(val)		MCR14(val, 0, c1, c11, 1)
#define WCP14_DBGBXVR12(val)		MCR14(val, 0, c1, c12, 1)
#define WCP14_DBGBXVR13(val)		MCR14(val, 0, c1, c13, 1)
#define WCP14_DBGBXVR14(val)		MCR14(val, 0, c1, c14, 1)
#define WCP14_DBGBXVR15(val)		MCR14(val, 0, c1, c15, 1)
#define WCP14_DBGOSLAR(val)		MCR14(val, 0, c1, c0, 4)
#define WCP14_DBGOSSRR(val)		MCR14(val, 0, c1, c2, 4)
#define WCP14_DBGOSDLR(val)		MCR14(val, 0, c1, c3, 4)
#define WCP14_DBGPRCR(val)		MCR14(val, 0, c1, c4, 4)
#define WCP14_DBGITCTRL(val)		MCR14(val, 0, c7, c0, 4)
#define WCP14_DBGCLAIMSET(val)		MCR14(val, 0, c7, c8, 6)
#define WCP14_DBGCLAIMCLR(val)		MCR14(val, 0, c7, c9, 6)

#endif