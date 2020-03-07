#ifndef PRINTAPIERROR_HPP
#define PRINTAPIERROR_HPP

#include <stdio.h>

#pragma pack(push, 1)

#include <global.h>
#include <osmisc.h>

#pragma pack(pop)

inline void PrintAPIError(STATUS api_error)

{
  STATUS string_id = ERR(api_error);
  char error_text[200];
  /*WORD text_len = */
  OSLoadString(NULLHANDLE, string_id, error_text, sizeof(error_text));
  fprintf(stderr, "\n%s\n", error_text);
}

#endif // PRINTAPIERROR_HPP
