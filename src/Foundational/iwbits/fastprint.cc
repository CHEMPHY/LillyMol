#include <stdio.h>

#include "iwbits.h"
#include "iwbits_support.h"

#include "iwstring.h"

static const char * byte_form_space [] = {
         " 0 0 0 0 0 0 0 0",
         " 0 0 0 0 0 0 0 1",
         " 0 0 0 0 0 0 1 0",
         " 0 0 0 0 0 0 1 1",
         " 0 0 0 0 0 1 0 0",
         " 0 0 0 0 0 1 0 1",
         " 0 0 0 0 0 1 1 0",
         " 0 0 0 0 0 1 1 1",
         " 0 0 0 0 1 0 0 0",
         " 0 0 0 0 1 0 0 1",
         " 0 0 0 0 1 0 1 0",
         " 0 0 0 0 1 0 1 1",
         " 0 0 0 0 1 1 0 0",
         " 0 0 0 0 1 1 0 1",
         " 0 0 0 0 1 1 1 0",
         " 0 0 0 0 1 1 1 1",
         " 0 0 0 1 0 0 0 0",
         " 0 0 0 1 0 0 0 1",
         " 0 0 0 1 0 0 1 0",
         " 0 0 0 1 0 0 1 1",
         " 0 0 0 1 0 1 0 0",
         " 0 0 0 1 0 1 0 1",
         " 0 0 0 1 0 1 1 0",
         " 0 0 0 1 0 1 1 1",
         " 0 0 0 1 1 0 0 0",
         " 0 0 0 1 1 0 0 1",
         " 0 0 0 1 1 0 1 0",
         " 0 0 0 1 1 0 1 1",
         " 0 0 0 1 1 1 0 0",
         " 0 0 0 1 1 1 0 1",
         " 0 0 0 1 1 1 1 0",
         " 0 0 0 1 1 1 1 1",
         " 0 0 1 0 0 0 0 0",
         " 0 0 1 0 0 0 0 1",
         " 0 0 1 0 0 0 1 0",
         " 0 0 1 0 0 0 1 1",
         " 0 0 1 0 0 1 0 0",
         " 0 0 1 0 0 1 0 1",
         " 0 0 1 0 0 1 1 0",
         " 0 0 1 0 0 1 1 1",
         " 0 0 1 0 1 0 0 0",
         " 0 0 1 0 1 0 0 1",
         " 0 0 1 0 1 0 1 0",
         " 0 0 1 0 1 0 1 1",
         " 0 0 1 0 1 1 0 0",
         " 0 0 1 0 1 1 0 1",
         " 0 0 1 0 1 1 1 0",
         " 0 0 1 0 1 1 1 1",
         " 0 0 1 1 0 0 0 0",
         " 0 0 1 1 0 0 0 1",
         " 0 0 1 1 0 0 1 0",
         " 0 0 1 1 0 0 1 1",
         " 0 0 1 1 0 1 0 0",
         " 0 0 1 1 0 1 0 1",
         " 0 0 1 1 0 1 1 0",
         " 0 0 1 1 0 1 1 1",
         " 0 0 1 1 1 0 0 0",
         " 0 0 1 1 1 0 0 1",
         " 0 0 1 1 1 0 1 0",
         " 0 0 1 1 1 0 1 1",
         " 0 0 1 1 1 1 0 0",
         " 0 0 1 1 1 1 0 1",
         " 0 0 1 1 1 1 1 0",
         " 0 0 1 1 1 1 1 1",
         " 0 1 0 0 0 0 0 0",
         " 0 1 0 0 0 0 0 1",
         " 0 1 0 0 0 0 1 0",
         " 0 1 0 0 0 0 1 1",
         " 0 1 0 0 0 1 0 0",
         " 0 1 0 0 0 1 0 1",
         " 0 1 0 0 0 1 1 0",
         " 0 1 0 0 0 1 1 1",
         " 0 1 0 0 1 0 0 0",
         " 0 1 0 0 1 0 0 1",
         " 0 1 0 0 1 0 1 0",
         " 0 1 0 0 1 0 1 1",
         " 0 1 0 0 1 1 0 0",
         " 0 1 0 0 1 1 0 1",
         " 0 1 0 0 1 1 1 0",
         " 0 1 0 0 1 1 1 1",
         " 0 1 0 1 0 0 0 0",
         " 0 1 0 1 0 0 0 1",
         " 0 1 0 1 0 0 1 0",
         " 0 1 0 1 0 0 1 1",
         " 0 1 0 1 0 1 0 0",
         " 0 1 0 1 0 1 0 1",
         " 0 1 0 1 0 1 1 0",
         " 0 1 0 1 0 1 1 1",
         " 0 1 0 1 1 0 0 0",
         " 0 1 0 1 1 0 0 1",
         " 0 1 0 1 1 0 1 0",
         " 0 1 0 1 1 0 1 1",
         " 0 1 0 1 1 1 0 0",
         " 0 1 0 1 1 1 0 1",
         " 0 1 0 1 1 1 1 0",
         " 0 1 0 1 1 1 1 1",
         " 0 1 1 0 0 0 0 0",
         " 0 1 1 0 0 0 0 1",
         " 0 1 1 0 0 0 1 0",
         " 0 1 1 0 0 0 1 1",
         " 0 1 1 0 0 1 0 0",
         " 0 1 1 0 0 1 0 1",
         " 0 1 1 0 0 1 1 0",
         " 0 1 1 0 0 1 1 1",
         " 0 1 1 0 1 0 0 0",
         " 0 1 1 0 1 0 0 1",
         " 0 1 1 0 1 0 1 0",
         " 0 1 1 0 1 0 1 1",
         " 0 1 1 0 1 1 0 0",
         " 0 1 1 0 1 1 0 1",
         " 0 1 1 0 1 1 1 0",
         " 0 1 1 0 1 1 1 1",
         " 0 1 1 1 0 0 0 0",
         " 0 1 1 1 0 0 0 1",
         " 0 1 1 1 0 0 1 0",
         " 0 1 1 1 0 0 1 1",
         " 0 1 1 1 0 1 0 0",
         " 0 1 1 1 0 1 0 1",
         " 0 1 1 1 0 1 1 0",
         " 0 1 1 1 0 1 1 1",
         " 0 1 1 1 1 0 0 0",
         " 0 1 1 1 1 0 0 1",
         " 0 1 1 1 1 0 1 0",
         " 0 1 1 1 1 0 1 1",
         " 0 1 1 1 1 1 0 0",
         " 0 1 1 1 1 1 0 1",
         " 0 1 1 1 1 1 1 0",
         " 0 1 1 1 1 1 1 1",
         " 1 0 0 0 0 0 0 0",
         " 1 0 0 0 0 0 0 1",
         " 1 0 0 0 0 0 1 0",
         " 1 0 0 0 0 0 1 1",
         " 1 0 0 0 0 1 0 0",
         " 1 0 0 0 0 1 0 1",
         " 1 0 0 0 0 1 1 0",
         " 1 0 0 0 0 1 1 1",
         " 1 0 0 0 1 0 0 0",
         " 1 0 0 0 1 0 0 1",
         " 1 0 0 0 1 0 1 0",
         " 1 0 0 0 1 0 1 1",
         " 1 0 0 0 1 1 0 0",
         " 1 0 0 0 1 1 0 1",
         " 1 0 0 0 1 1 1 0",
         " 1 0 0 0 1 1 1 1",
         " 1 0 0 1 0 0 0 0",
         " 1 0 0 1 0 0 0 1",
         " 1 0 0 1 0 0 1 0",
         " 1 0 0 1 0 0 1 1",
         " 1 0 0 1 0 1 0 0",
         " 1 0 0 1 0 1 0 1",
         " 1 0 0 1 0 1 1 0",
         " 1 0 0 1 0 1 1 1",
         " 1 0 0 1 1 0 0 0",
         " 1 0 0 1 1 0 0 1",
         " 1 0 0 1 1 0 1 0",
         " 1 0 0 1 1 0 1 1",
         " 1 0 0 1 1 1 0 0",
         " 1 0 0 1 1 1 0 1",
         " 1 0 0 1 1 1 1 0",
         " 1 0 0 1 1 1 1 1",
         " 1 0 1 0 0 0 0 0",
         " 1 0 1 0 0 0 0 1",
         " 1 0 1 0 0 0 1 0",
         " 1 0 1 0 0 0 1 1",
         " 1 0 1 0 0 1 0 0",
         " 1 0 1 0 0 1 0 1",
         " 1 0 1 0 0 1 1 0",
         " 1 0 1 0 0 1 1 1",
         " 1 0 1 0 1 0 0 0",
         " 1 0 1 0 1 0 0 1",
         " 1 0 1 0 1 0 1 0",
         " 1 0 1 0 1 0 1 1",
         " 1 0 1 0 1 1 0 0",
         " 1 0 1 0 1 1 0 1",
         " 1 0 1 0 1 1 1 0",
         " 1 0 1 0 1 1 1 1",
         " 1 0 1 1 0 0 0 0",
         " 1 0 1 1 0 0 0 1",
         " 1 0 1 1 0 0 1 0",
         " 1 0 1 1 0 0 1 1",
         " 1 0 1 1 0 1 0 0",
         " 1 0 1 1 0 1 0 1",
         " 1 0 1 1 0 1 1 0",
         " 1 0 1 1 0 1 1 1",
         " 1 0 1 1 1 0 0 0",
         " 1 0 1 1 1 0 0 1",
         " 1 0 1 1 1 0 1 0",
         " 1 0 1 1 1 0 1 1",
         " 1 0 1 1 1 1 0 0",
         " 1 0 1 1 1 1 0 1",
         " 1 0 1 1 1 1 1 0",
         " 1 0 1 1 1 1 1 1",
         " 1 1 0 0 0 0 0 0",
         " 1 1 0 0 0 0 0 1",
         " 1 1 0 0 0 0 1 0",
         " 1 1 0 0 0 0 1 1",
         " 1 1 0 0 0 1 0 0",
         " 1 1 0 0 0 1 0 1",
         " 1 1 0 0 0 1 1 0",
         " 1 1 0 0 0 1 1 1",
         " 1 1 0 0 1 0 0 0",
         " 1 1 0 0 1 0 0 1",
         " 1 1 0 0 1 0 1 0",
         " 1 1 0 0 1 0 1 1",
         " 1 1 0 0 1 1 0 0",
         " 1 1 0 0 1 1 0 1",
         " 1 1 0 0 1 1 1 0",
         " 1 1 0 0 1 1 1 1",
         " 1 1 0 1 0 0 0 0",
         " 1 1 0 1 0 0 0 1",
         " 1 1 0 1 0 0 1 0",
         " 1 1 0 1 0 0 1 1",
         " 1 1 0 1 0 1 0 0",
         " 1 1 0 1 0 1 0 1",
         " 1 1 0 1 0 1 1 0",
         " 1 1 0 1 0 1 1 1",
         " 1 1 0 1 1 0 0 0",
         " 1 1 0 1 1 0 0 1",
         " 1 1 0 1 1 0 1 0",
         " 1 1 0 1 1 0 1 1",
         " 1 1 0 1 1 1 0 0",
         " 1 1 0 1 1 1 0 1",
         " 1 1 0 1 1 1 1 0",
         " 1 1 0 1 1 1 1 1",
         " 1 1 1 0 0 0 0 0",
         " 1 1 1 0 0 0 0 1",
         " 1 1 1 0 0 0 1 0",
         " 1 1 1 0 0 0 1 1",
         " 1 1 1 0 0 1 0 0",
         " 1 1 1 0 0 1 0 1",
         " 1 1 1 0 0 1 1 0",
         " 1 1 1 0 0 1 1 1",
         " 1 1 1 0 1 0 0 0",
         " 1 1 1 0 1 0 0 1",
         " 1 1 1 0 1 0 1 0",
         " 1 1 1 0 1 0 1 1",
         " 1 1 1 0 1 1 0 0",
         " 1 1 1 0 1 1 0 1",
         " 1 1 1 0 1 1 1 0",
         " 1 1 1 0 1 1 1 1",
         " 1 1 1 1 0 0 0 0",
         " 1 1 1 1 0 0 0 1",
         " 1 1 1 1 0 0 1 0",
         " 1 1 1 1 0 0 1 1",
         " 1 1 1 1 0 1 0 0",
         " 1 1 1 1 0 1 0 1",
         " 1 1 1 1 0 1 1 0",
         " 1 1 1 1 0 1 1 1",
         " 1 1 1 1 1 0 0 0",
         " 1 1 1 1 1 0 0 1",
         " 1 1 1 1 1 0 1 0",
         " 1 1 1 1 1 0 1 1",
         " 1 1 1 1 1 1 0 0",
         " 1 1 1 1 1 1 0 1",
         " 1 1 1 1 1 1 1 0",
         " 1 1 1 1 1 1 1 1",
   };

#ifdef OLD_STUFF____
static void
append_string_form_word (IWString & buffer,
                         unsigned int zword)
{
  const unsigned char * s = reinterpret_cast<const unsigned char *>(&zword);

  for (unsigned int i = 0; i < IW_BYTES_PER_WORD; i++)
  {
    buffer.strncat(byte_form_space[s[i]], 16);
  }

  return;
}
#endif

int
IW_Bits_Base::printon_fast (std::ostream & os,
                            int include_space) const
{
  IWString tmp;

  if (! append_string_form_fast(tmp, include_space))
    return 0;

  os << tmp;

  return os.good();
}

int
IW_Bits_Base::append_string_form_fast(IWString & buffer, int include_space) const
{
  assert (ok());

  int chars_needed;
  if (include_space)
    chars_needed = _nbits + _nbits;
  else
    chars_needed = _nbits;

  buffer.make_room_for_extra_items(chars_needed);

  for (int i = 0; i < _whole_bytes; i++)
  {
    buffer.strncat(byte_form_space[_bits[i]], 16);
  }

  if (_extra_bits)
    byte_string_form(buffer, _bits[_whole_bytes], _extra_bits, '1', '0', include_space);

  return 1;
}
