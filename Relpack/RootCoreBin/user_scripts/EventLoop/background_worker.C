#ifndef __CINT__
#include <EventLoop/BackgroundWorker.h>
#endif

void background_worker (int socket)
{
  EL::BackgroundWorker::execute (socket);
}
