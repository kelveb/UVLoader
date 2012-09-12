#ifndef UVL_SCEFUNCS
#define UVL_SCEFUNCS

#include "types.h"

/** \name IO Constants
 *  \todo Use toolchain
 *  @{
*/
#define PSP2_SEEK_SET    0
#define PSP2_SEEK_CUR    1
#define PSP2_SEEK_END    2
#define PSP2_O_RDONLY    0x0001
#define PSP2_O_WRONLY    0x0002
#define PSP2_O_RDWR      (PSP2_O_RDONLY | PSP2_O_WRONLY)
#define PSP2_O_NBLOCK    0x0004
#define PSP2_O_DIROPEN   0x0008
#define PSP2_O_APPEND    0x0100
#define PSP2_O_CREAT     0x0200
#define PSP2_O_TRUNC     0x0400
#define PSP2_O_EXCL      0x0800
#define PSP2_O_NOWAIT    0x8000
#define PSP2_STM_RWXU    00700
#define PSP2_STM_RUSR    00400
#define PSP2_STM_WUSR    00200
#define PSP2_STM_XUSR    00100
#define PSP2_STM_RWU     (PSP2_STM_RUSR | PSP2_STM_WUSR)
#define PSP2_STM_RU      (PSP2_STM_RUSR)
/** @}*/

#ifdef GENERATE_STUBS
#define STUB_FUNCTION(type, name, high, low) \
    type __attribute__((naked, section(".sceStub.text.uvl"))) name () \
    { \
        __asm__ ("movw r12, #" #low" \n" \
                 "movt r12, #" #high" \n" \
                 "bx r12\n" \
                 "nop"); \
    }
#else
#define STUB_FUNCTION(type, name, high, low) type __attribute__((naked)) name ()
#endif

// some names from https://github.com/pspdev/pspsdk

void uvl_scefuncs_resolve_all ();

#endif
