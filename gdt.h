/*
This header file declares all the necessary bits to initialize and load the GDT (global decriptor table)
*/

#ifndef __gdt_h__
#define __gdt_h__

#include "types.h"

enum gdt_entry_type
{
    ACCESSED    = 1 << 0,
    WR          = 1 << 1,
    EC          = 1 << 2,
    CS          = 1 << 3
};

/*
    GDT entry structure (bit representation):
    0-15    : Segment limit - low portion       | WORD 
    16-31   : Base address - low portion        | WORD
    32-39   : Base address - mid portion        | BYTE
    40-43   : Type (Page 2758 in IA-32 manual)  | BYTE 
    44      : S (system/cs-ds)                  | "  "
    45-6    : DPL (privilege ring 0 to 3)       | "  "
    47      : P (present in memory)             | "  "
    48-51   : Segment limit - high portion      | BYTE
    52      : AVL (available bit)               | "  " (flags)
    53      : L (32/64 bit segment)             | "  " (flags)
    54      : D/B (16 bit/32 bit)               | "  " (flags)
    55      : G (granularity)                   | "  " (flags)
    56-63   : Base address - high portion       | BYTE
*/

/*
    base structure:
    0x0000FFFF low
    0x00FF0000 mid
    0xFF000000 high
*/

/*
    limit structure:
    0x0000FFFF low
    0x000F0000 high
*/

struct gdt_entry
{
    word limit_lo;
    word base_lo;
    byte base_mid;
    byte type_s_dpl_p;
    byte limit_hi_flags;
    byte base_hi;
} __attribute__((packed));

inline word limit_lo(dword limit)
{
    word result;

    result = limit & 0x0000FFFF; 

    return result;
}

inline word base_lo(dword base)
{
    word result;

    result = base & 0x0000FFFF;

    return result;
}

inline byte base_mid(dword base)
{
    byte result;

    result = (base & 0x00FF0000) >> 4*4;

    return result;
}

inline byte limit_hi_flags(dword limit, byte flags)
{
    byte limit_hi, result;

    //take bits 16-19 from limit and put them in limit_hi
    limit_hi = (limit & 0x000F0000) >> (4*4);

    //or limit_hi and flags together
    result = limit_hi | (flags << 4);

    return result;
}

inline byte base_hi(dword base)
{
    byte result;

    result = (base & 0xFF000000) >> (4*6);

    return result;
}

inline byte flags(byte avl, byte l, byte db, byte g)
{
    byte result;

    result = ((avl & 1) << 0) |
             ((l & 1)   << 2) |
             ((db & 1)  << 3) |
             ((g & 1)   << 4);

    return result;
}

inline byte type(byte ds_cs, byte ec, byte rw, byte a)
{
    byte result;

    result = ((a & 1)       << 0) |
             ((rw & 1)      << 1) |
             ((ec & 1)      << 2) |
             ((ds_cs & 1)   << 3);

    return result;
}

inline byte type_s_dpl_p(byte type, byte s, byte dpl, byte p)
{
    byte result;

    result = (type                )|
             ((s & 1)         << 4)|
             ((dpl & (1|2))   << 5)|
             ((p & 1)         << 7);

    return result;
}

struct gdt_entry gdt_entry(dword base, dword limit, byte flags, byte type_s_dpl_p);

extern void load_gdt(dword gdt_ptr, word table_size);

void gdt_init();

struct gdt_entry gdt[6];

#endif