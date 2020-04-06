#ifndef PRINTAPIERROR_HPP
#define PRINTAPIERROR_HPP

#include <stdio.h>

#ifdef NT
#pragma pack(push, 1)
#endif

#include <global.h>
#include <osmisc.h>

#ifdef NT
#pragma pack(pop)
#endif

inline void PrintAPIError(STATUS api_error)

{
  STATUS string_id = ERR(api_error);
  char error_text[200];
  /*WORD text_len = */
  OSLoadString(NULLHANDLE, string_id, error_text, sizeof(error_text));
  fprintf(stderr, "\n%s\n", error_text);
}

#endif // PRINTAPIERROR_HPP
