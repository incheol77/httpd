/*------------------------------------------------------------------
  These functions are to be called when the shared NLM starts and
  stops.  By using these functions instead of defining a main()
  and calling ExitThread(TSR_THREAD, 0), the load time of the
  shared NLM is faster and memory size reduced.
   
  You may also want to override these in your own Apache module
  to do any cleanup other than the mechanism Apache modules
  provide.
------------------------------------------------------------------*/
#include "stddef.h"
#include "ws2nlm.h"

int _lib_start_ws()
{
    WSADATA wsaData;
    
    return WSAStartup((WORD) MAKEWORD(2, 0), &wsaData);
}

int _lib_stop_ws()
{
    WSACleanup();
    return 0;
}
