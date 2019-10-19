/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/ZEYNEP/Okul/ceng232/lab4/testbenchRAM.v";
static int ng1[] = {1, 0};
static const char *ng2 = "Starting Testbench";
static unsigned int ng3[] = {8421890U, 0U};
static int ng4[] = {0, 0};
static unsigned int ng5[] = {11003878U, 0U};
static unsigned int ng6[] = {2581988U, 0U};
static int ng7[] = {2, 0};
static unsigned int ng8[] = {9491025U, 0U};
static int ng9[] = {3, 0};
static unsigned int ng10[] = {16777215U, 0U};
static int ng11[] = {4, 0};
static unsigned int ng12[] = {0U, 0U};
static int ng13[] = {5, 0};
static unsigned int ng14[] = {7517235U, 0U};
static int ng15[] = {6, 0};
static unsigned int ng16[] = {8569923U, 0U};
static int ng17[] = {7, 0};
static unsigned int ng18[] = {16777214U, 0U};
static int ng19[] = {8, 0};
static unsigned int ng20[] = {8438337U, 0U};
static int ng21[] = {9, 0};
static unsigned int ng22[] = {1U, 0U};
static int ng23[] = {10, 0};
static unsigned int ng24[] = {231300U, 0U};
static int ng25[] = {11, 0};
static int ng26[] = {15, 0};
static const char *ng27 = "wrong initial cell values";
static unsigned int ng28[] = {8504130U, 0U};
static unsigned int ng29[] = {166U, 0U};
static const char *ng30 = "RamDataOut after AND %b";
static const char *ng31 = "RamDataOut after OR %b";
static unsigned int ng32[] = {2U, 0U};
static const char *ng33 = "RamDataOut after XOR %b";
static unsigned int ng34[] = {3U, 0U};
static unsigned int ng35[] = {15U, 0U};
static const char *ng36 = "RamDataOut after ADD %b";
static unsigned int ng37[] = {230U, 0U};
static const char *ng38 = "RamDataOut after ADD_OVERFLOW %b";
static unsigned int ng39[] = {4U, 0U};
static const char *ng40 = "RamDataOut after SUB_UNDERFLOW %b";
static const char *ng41 = "RamDataOut after SUB %b";
static unsigned int ng42[] = {5U, 0U};
static const char *ng43 = "RamDataOut after INC %b";
static unsigned int ng44[] = {16777213U, 0U};
static const char *ng45 = "RamDataOut after INC_OVERFLOW %b";
static unsigned int ng46[] = {6U, 0U};
static const char *ng47 = "RamDataOut after DEC %b";
static const char *ng48 = "RamDataOut after DEC_UNDERFLOW %b";
static unsigned int ng49[] = {7U, 0U};
static const char *ng50 = "RamDataOut after ROTL %b";
static const char *ng51 = "Starting to read 12 RAM cells:";
static int ng52[] = {12, 0};
static const char *ng53 = "RamDataOut at cell %d: %b";
static const char *ng54 = "Result %d";



static void Initial_24_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(24, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2248);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_25_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 4376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(25, ng0);
    t4 = (t0 + 2248);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 2248);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_28_2(char *t0)
{
    char t4[8];
    char t5[8];
    char t47[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    int t15;
    char *t16;
    unsigned int t17;
    int t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    int t22;
    int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t48;

LAB0:    t1 = (t0 + 4624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);

LAB4:    xsi_set_current_line(29, ng0);
    xsi_vlogfile_write(1, 0, 0, ng2, 1, t0);
    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB5;

LAB6:    xsi_set_current_line(33, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng1)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB7;

LAB8:    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng7)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB9;

LAB10:    xsi_set_current_line(35, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng9)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB11;

LAB12:    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng11)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng13)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB15;

LAB16:    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng15)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB17;

LAB18:    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng17)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB19;

LAB20:    xsi_set_current_line(40, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng19)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB21;

LAB22:    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng21)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB23;

LAB24:    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng23)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB25;

LAB26:    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 2408);
    t6 = (t0 + 2408);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 2408);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng25)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB27;

LAB28:    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(46, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB29;

LAB1:    return;
LAB5:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB6;

LAB7:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB8;

LAB9:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB10;

LAB11:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB12;

LAB13:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB14;

LAB15:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB16;

LAB17:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB18;

LAB19:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB20;

LAB21:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB22;

LAB23:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB24;

LAB25:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB26;

LAB27:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB28;

LAB29:    xsi_set_current_line(55, ng0);
    xsi_set_current_line(55, ng0);
    t3 = ((char*)((ng4)));
    t6 = (t0 + 2568);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 32);

LAB30:    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng26)));
    memset(t4, 0, 8);
    xsi_vlog_signed_leq(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB43;

LAB44:    xsi_set_current_line(70, ng0);

LAB47:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2888);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);

LAB45:    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng29)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB31:    xsi_set_current_line(56, ng0);

LAB33:    xsi_set_current_line(57, ng0);
    t9 = (t0 + 2568);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 1608);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 4);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB34:    xsi_set_current_line(59, ng0);
    t3 = (t0 + 1048U);
    t6 = *((char **)t3);
    t3 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = (t3 + 4);
    t14 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t3);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t7);
    t24 = *((unsigned int *)t8);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t7);
    t28 = *((unsigned int *)t8);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB36;

LAB35:    if (t29 != 0)
        goto LAB37;

LAB38:    t10 = (t4 + 4);
    t32 = *((unsigned int *)t10);
    t33 = (~(t32));
    t34 = *((unsigned int *)t4);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB39;

LAB40:
LAB41:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2568);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB30;

LAB36:    *((unsigned int *)t4) = 1;
    goto LAB38;

LAB37:    t9 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB38;

LAB39:    xsi_set_current_line(60, ng0);

LAB42:    xsi_set_current_line(61, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3048);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);
    goto LAB41;

LAB43:    xsi_set_current_line(66, ng0);

LAB46:    xsi_set_current_line(67, ng0);
    xsi_vlogfile_write(1, 0, 0, ng27, 1, t0);
    goto LAB45;

LAB48:    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB49;
    goto LAB1;

LAB49:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng30, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB53;

LAB50:    if (t29 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t5) = 1;

LAB53:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB54;

LAB55:
LAB56:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB58;
    goto LAB1;

LAB52:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB53;

LAB54:    xsi_set_current_line(86, ng0);

LAB57:    xsi_set_current_line(87, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB56;

LAB58:    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB59:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng31, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB63;

LAB60:    if (t29 != 0)
        goto LAB62;

LAB61:    *((unsigned int *)t5) = 1;

LAB63:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB64;

LAB65:
LAB66:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng32)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB68;
    goto LAB1;

LAB62:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB63;

LAB64:    xsi_set_current_line(99, ng0);

LAB67:    xsi_set_current_line(100, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB66;

LAB68:    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB69:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng33, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB73;

LAB70:    if (t29 != 0)
        goto LAB72;

LAB71:    *((unsigned int *)t5) = 1;

LAB73:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB74;

LAB75:
LAB76:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng34)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng35)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB78;
    goto LAB1;

LAB72:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB73;

LAB74:    xsi_set_current_line(112, ng0);

LAB77:    xsi_set_current_line(113, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB76;

LAB78:    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB79;
    goto LAB1;

LAB79:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng36, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB83;

LAB80:    if (t29 != 0)
        goto LAB82;

LAB81:    *((unsigned int *)t5) = 1;

LAB83:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB84;

LAB85:
LAB86:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(132, ng0);
    t2 = ((char*)((ng34)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng37)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB88;
    goto LAB1;

LAB82:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB83;

LAB84:    xsi_set_current_line(126, ng0);

LAB87:    xsi_set_current_line(127, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB86;

LAB88:    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB89;
    goto LAB1;

LAB89:    xsi_set_current_line(138, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng38, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB93;

LAB90:    if (t29 != 0)
        goto LAB92;

LAB91:    *((unsigned int *)t5) = 1;

LAB93:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB94;

LAB95:
LAB96:    xsi_set_current_line(143, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(146, ng0);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB98;
    goto LAB1;

LAB92:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB93;

LAB94:    xsi_set_current_line(140, ng0);

LAB97:    xsi_set_current_line(141, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB96;

LAB98:    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB99;
    goto LAB1;

LAB99:    xsi_set_current_line(151, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng40, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB103;

LAB100:    if (t29 != 0)
        goto LAB102;

LAB101:    *((unsigned int *)t5) = 1;

LAB103:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB104;

LAB105:
LAB106:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(160, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(161, ng0);
    t2 = ((char*)((ng35)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(162, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB108;
    goto LAB1;

LAB102:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB103;

LAB104:    xsi_set_current_line(153, ng0);

LAB107:    xsi_set_current_line(154, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB106;

LAB108:    xsi_set_current_line(163, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(164, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB109;
    goto LAB1;

LAB109:    xsi_set_current_line(165, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng41, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB113;

LAB110:    if (t29 != 0)
        goto LAB112;

LAB111:    *((unsigned int *)t5) = 1;

LAB113:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB114;

LAB115:
LAB116:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(172, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(173, ng0);
    t2 = ((char*)((ng42)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(174, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB118;
    goto LAB1;

LAB112:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB113;

LAB114:    xsi_set_current_line(167, ng0);

LAB117:    xsi_set_current_line(168, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB116;

LAB118:    xsi_set_current_line(176, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB119;
    goto LAB1;

LAB119:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng43, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(179, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB123;

LAB120:    if (t29 != 0)
        goto LAB122;

LAB121:    *((unsigned int *)t5) = 1;

LAB123:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB124;

LAB125:
LAB126:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(185, ng0);
    t2 = ((char*)((ng44)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(186, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(187, ng0);
    t2 = ((char*)((ng42)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(188, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(189, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB128;
    goto LAB1;

LAB122:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB123;

LAB124:    xsi_set_current_line(180, ng0);

LAB127:    xsi_set_current_line(181, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB126;

LAB128:    xsi_set_current_line(190, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(191, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB129;
    goto LAB1;

LAB129:    xsi_set_current_line(192, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng45, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(193, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB133;

LAB130:    if (t29 != 0)
        goto LAB132;

LAB131:    *((unsigned int *)t5) = 1;

LAB133:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB134;

LAB135:
LAB136:    xsi_set_current_line(197, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(199, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(200, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(201, ng0);
    t2 = ((char*)((ng46)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(202, ng0);
    t2 = ((char*)((ng21)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(203, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB138;
    goto LAB1;

LAB132:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB133;

LAB134:    xsi_set_current_line(194, ng0);

LAB137:    xsi_set_current_line(195, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB136;

LAB138:    xsi_set_current_line(204, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(205, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB139;
    goto LAB1;

LAB139:    xsi_set_current_line(206, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng47, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(207, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB143;

LAB140:    if (t29 != 0)
        goto LAB142;

LAB141:    *((unsigned int *)t5) = 1;

LAB143:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB144;

LAB145:
LAB146:    xsi_set_current_line(211, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(213, ng0);
    t2 = ((char*)((ng32)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(214, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(215, ng0);
    t2 = ((char*)((ng46)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(216, ng0);
    t2 = ((char*)((ng23)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(217, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB148;
    goto LAB1;

LAB142:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB143;

LAB144:    xsi_set_current_line(208, ng0);

LAB147:    xsi_set_current_line(209, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB146;

LAB148:    xsi_set_current_line(218, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(219, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB149;
    goto LAB1;

LAB149:    xsi_set_current_line(220, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng48, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(221, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB153;

LAB150:    if (t29 != 0)
        goto LAB152;

LAB151:    *((unsigned int *)t5) = 1;

LAB153:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB154;

LAB155:
LAB156:    xsi_set_current_line(225, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    xsi_set_current_line(227, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 24);
    xsi_set_current_line(228, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(229, ng0);
    t2 = ((char*)((ng49)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(230, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(231, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB158;
    goto LAB1;

LAB152:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB153;

LAB154:    xsi_set_current_line(222, ng0);

LAB157:    xsi_set_current_line(223, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB156;

LAB158:    xsi_set_current_line(232, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(233, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB159;
    goto LAB1;

LAB159:    xsi_set_current_line(234, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng50, 2, t0, (char)118, t3, 24);
    xsi_set_current_line(235, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2728);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB163;

LAB160:    if (t29 != 0)
        goto LAB162;

LAB161:    *((unsigned int *)t5) = 1;

LAB163:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB164;

LAB165:
LAB166:    xsi_set_current_line(243, ng0);
    xsi_vlogfile_write(1, 0, 0, ng51, 1, t0);
    xsi_set_current_line(244, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(245, ng0);
    xsi_set_current_line(245, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB168:    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng52)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB169;

LAB170:    xsi_set_current_line(256, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB181;

LAB182:
LAB183:    xsi_set_current_line(261, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng54, 2, t0, (char)119, t6, 32);
    xsi_set_current_line(262, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB162:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB163;

LAB164:    xsi_set_current_line(236, ng0);

LAB167:    xsi_set_current_line(237, ng0);
    t43 = (t0 + 2888);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = ((char*)((ng1)));
    memset(t47, 0, 8);
    xsi_vlog_signed_add(t47, 32, t45, 32, t46, 32);
    t48 = (t0 + 2888);
    xsi_vlogvar_assign_value(t48, t47, 0, 0, 32);
    goto LAB166;

LAB169:    xsi_set_current_line(246, ng0);

LAB171:    xsi_set_current_line(247, ng0);
    t9 = (t0 + 2568);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 1608);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 4);
    xsi_set_current_line(248, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB172;
    goto LAB1;

LAB172:    xsi_set_current_line(249, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 2408);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 2408);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 2568);
    t37 = (t16 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_get_array_select_value(t4, 24, t7, t10, t13, 2, 1, t38, 32, 1);
    memset(t5, 0, 8);
    t39 = (t3 + 4);
    t40 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t39);
    t24 = *((unsigned int *)t40);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t40);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB174;

LAB173:    if (t29 != 0)
        goto LAB175;

LAB176:    t42 = (t5 + 4);
    t32 = *((unsigned int *)t42);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB177;

LAB178:
LAB179:    xsi_set_current_line(253, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t0 + 1048U);
    t8 = *((char **)t7);
    xsi_vlogfile_write(1, 0, 0, ng53, 3, t0, (char)119, t6, 32, (char)118, t8, 24);
    xsi_set_current_line(245, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 2568);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB168;

LAB174:    *((unsigned int *)t5) = 1;
    goto LAB176;

LAB175:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB176;

LAB177:    xsi_set_current_line(250, ng0);

LAB180:    xsi_set_current_line(251, ng0);
    t43 = ((char*)((ng1)));
    t44 = (t0 + 3208);
    xsi_vlogvar_assign_value(t44, t43, 0, 0, 32);
    goto LAB179;

LAB181:    xsi_set_current_line(257, ng0);

LAB184:    xsi_set_current_line(258, ng0);
    t9 = (t0 + 2888);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng9)));
    memset(t5, 0, 8);
    xsi_vlog_signed_add(t5, 32, t11, 32, t12, 32);
    t13 = (t0 + 2888);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    goto LAB183;

}


extern void work_m_00000000002887486359_1685954650_init()
{
	static char *pe[] = {(void *)Initial_24_0,(void *)Always_25_1,(void *)Initial_28_2};
	xsi_register_didat("work_m_00000000002887486359_1685954650", "isim/testbenchRAM_isim_beh.exe.sim/work/m_00000000002887486359_1685954650.didat");
	xsi_register_executes(pe);
}
