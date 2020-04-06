#include "printapierror.hpp"

#ifdef NT
#pragma pack(push, 1)
#endif

#include <names.h>
#include <nsfdb.h>
#include <nsfdata.h>
#include <osfile.h>
#include <lapiplat.h>

#ifdef NT
#pragma pack(pop)
#endif

int main(int argc, char *argv[])
{
  if (argc < 2 || argc > 3) {
    printf("\nUsage:  %s  [server name - optional] <database filename>\n", argv[0]);
    return 0;
  }

  char *db_name = argv[argc - 1];
  char *path_name = db_name;
  char pname[MAXPATH] = "";
  char *server_name = pname;

  if (argc == 3) {
    server_name = argv[1];
  }

  STATUS error = NotesInitExtended(argc, argv);
  if (error) {
    fprintf(stderr, "\nError initializing Notes.\n");
    return 1;
  }

  if (strcmp(server_name, "")) {
    if (error = OSPathNetConstruct(NULL, server_name, db_name, pname)) {
      PrintAPIError(error);
      NotesTerm();
      return 1;
    }
    path_name = pname;
  }

  DBHANDLE db_handle = NULLHANDLE;
  if (error = NSFDbOpen(path_name, &db_handle)) {
    PrintAPIError(error);
    NotesTerm();
    return 1;
  }

  char buffer[NSF_INFO_SIZE] = "";
  if (error = NSFDbInfoGet(db_handle, buffer)) {
    PrintAPIError(error);
    NSFDbClose(db_handle);
    NotesTerm();
    return 1;
  }

  char title[NSF_INFO_SIZE] = "";
  NSFDbInfoParse(buffer, INFOPARSE_TITLE, title, NSF_INFO_SIZE - 1);

  printf("\n\nIBM C API for %s Sample Application", NOTESAPI_VERSION);
  printf("\n\n\nThe title for the database, %s, is:\n\n%s\n\n", path_name, title);

  if (error = NSFDbClose(db_handle)) {
    PrintAPIError(error);
    NotesTerm();
    return 1;
  }

  NotesTerm();
  return 0;
}
