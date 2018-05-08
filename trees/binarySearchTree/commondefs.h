
#ifndef commondefs_h
#define commondefs_h

#define UINT    unsigned int
#define INT     int
#define VOID    void
#define Memset  memset
#define BOOL    UINT
#define FALSE   0
#define TRUE    1
#define CALLOC  calloc
#define FREE(x) { free(x); x = NULL; }
#define NEW     new
#define DELETE  delete
#define ASSERT  assert
#define NEWLINE "\n"

#endif /* commondefs_h */

