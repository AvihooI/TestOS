#include "gdt.h"

struct gdt_entry gdt_entry(dword base, dword limit, byte flags, byte type_s_dpl_p)
{
    struct gdt_entry result;

    result.base_lo = base_lo(base);
    result.base_mid = base_mid(base);
    result.base_hi = base_hi(base);
    result.limit_lo = limit_lo(limit);
    result.limit_hi_flags = limit_hi_flags(limit, flags);
    result.type_s_dpl_p = type_s_dpl_p;

    return result;
}

void gdt_init()
{
    qword* gdt_d;
    byte flags_;
    flags_ = flags(0,0,1,1);

    /*
        we need this since the two first entries (not actually entries)
        contain the size of the table and the address to the table
    */
    gdt_d = (qword*)gdt; 
    gdt_d[0] = 6*8; //size of the table
    gdt_d[1] = (qword)&gdt; //address of the table

    //ring 0 data segment
    gdt[2] = gdt_entry(0, 4*1024*1024,flags_, type_s_dpl_p(type(0, 0, 1, 0), 0, 0, 1));
    //ring 0 code segment
    gdt[3] = gdt_entry(0, 4*1024*1024,flags_, type_s_dpl_p(type(1, 0, 1, 0), 0, 0, 1));
    //ring 3 data segment
    gdt[4] = gdt_entry(0, 4*1024*1024,flags_, type_s_dpl_p(type(0, 0, 1, 0), 0, 3, 1));
    //ring 3 code segment
    gdt[5] = gdt_entry(0, 4*1024*1024,flags_, type_s_dpl_p(type(1, 0, 1, 0), 0, 3, 1));

    //load the gdt table
    load_gdt((dword)gdt, 6*8);
}