#include <pspuser.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <cassert>
#include <iostream>
#include <string>
using namespace std ;

#include "../../src/minIni.h"
#include "callback.h"

#define printf pspDebugScreenPrintf

PSP_MODULE_INFO("minIniPSP Test C++", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(void)
{
  string s;
  
  setup_callbacks();
  pspDebugScreenInit();
  
  sceIoChdir("ms0:/minIniTest");
  minIni ini("test.ini");
  
  /* string reading */
  s = ini.gets( "first", "string" , "aap" );
  assert(s == "noot");
  s = ini.gets( "second", "string" , "aap" );
  assert(s == "mies");
  s = ini.gets( "first", "dummy" , "aap" );
  assert(s == "aap");
  printf("1. String reading tests passed\n");


  /* value reading */
  long n;
  n = ini.getl("first", "val", -1 );
  assert(n==1);
  n = ini.getl("second", "val", -1);
  assert(n==2);
  n = ini.getl("first", "dummy", -1);
  assert(n==-1);
  printf("2. Value reading tests passed\n");


  /* string writing */
  bool b;
  b = ini.put("first", "alt", "flagged as \"correct\"");
  assert(b);
  s = ini.gets("first", "alt", "aap");
  assert(s=="flagged as \"correct\"");

  b = ini.put("second", "alt", "correct");
  assert(b);
  s = ini.gets("second", "alt", "aap");
  assert(s=="correct");

  b = ini.put("third", "alt", "correct");
  assert(b);
  s = ini.gets("third", "alt", "aap" );
  assert(s=="correct");
  printf("3. String writing tests passed\n");

  /* section/key enumeration */
  printf("4. section/key enumeration; file contents follows\n");
  string section;
  for (int is = 0; section = ini.getsection(is), section.length() > 0; is++) {
    printf(" [%s]\n", section.c_str());
    for (int ik = 0; s = ini.getkey(section, ik), s.length() > 0; ik++) {
      printf("\t%s\n", s.c_str());
    }
  }

  /* string deletion */
  b = ini.del("first", "alt");
  assert(b);
  b = ini.del("second", "alt");
  assert(b);
  b = ini.del("third");
  assert(b);
  printf("5. string deletion passed\n");

  while( true )
  {
    sceDisplayWaitVblank();
  }

  return 0;
}
