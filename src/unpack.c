#include <proto/exec.h>

#include "compiler.h"

UBYTE * unpack_nop(UBYTE *packed_data, UBYTE *out_buffer, ULONG out_size)
{
  /* packed data is not packed at all */
  return packed_data;
}

/* asm function */
extern ASM ULONG unpack_rnc1(REG(a0, UBYTE *packed_data),
                             REG(a1, UBYTE *out_data));

UBYTE * unpack_rnc(UBYTE *packed_data, UBYTE *out_buffer, ULONG out_size)
{
  unpack_rnc1(packed_data, out_buffer);
  return out_buffer;
}

extern ASM ULONG inflate(REG(a5, UBYTE *packed_data),
                         REG(a4, UBYTE *out_data));

UBYTE * unpack_dflt(UBYTE *packed_data, UBYTE *out_buffer, ULONG out_size)
{
  inflate(packed_data, out_buffer);
  return out_buffer;
}
