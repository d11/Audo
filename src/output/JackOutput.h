#pragma once

#include <cmath>
#include <iostream>
#include <exception>

#include <jack/jack.h>

#include "output/Output.h"
#include "model/WritableBuffer.h"

class JackOutput : public Output {

   public:
      JackOutput();
      ~JackOutput();

   private:

      void start();
      void stop();
      void serverShutdown();

      static void shutdownCallback(void *arg);

      // Precondition:
      //    nframes == jack_get_buffer_size()
      //    nframes == pow(2,x)
      // Parameters:
      //       nframes 	number of frames to process
      //       arg 	pointer to a client supplied data
      // Returns:
      //    zero on success, non-zero on error
      static int processCallback(jack_nframes_t frames, void *arg);

      WritableBufferRef getNextOutputBuffer(jack_nframes_t frames);

      void failure();

      jack_port_t   * m_outputPort;
      jack_client_t * m_client;
      const char   ** m_ports;
      jack_nframes_t  m_sampleRate;
};

//int main(int argc, char *argv[]) {

//   JackOutput jo();

//   int n    = 512; // buffer size
//   int k    = 0; // index variable
//   double f = 50.0; // 'frequency' ... sort of
//   char b   = 1; // going up?

//   unsigned char buf[n];

//   while(1) {
//      k = 0;
//      while (k < n) {
//         buf[k] = (int)(k/10+100*sin(f*(double)k/(double)n*M_PI*2));
//         ++k;
//      }
//      if (b) f *= 1.05;
//      else f *= 0.90;

//      if (f > 180.0) b = 0;
//      if (f < 10.0) b = 1;

//      write(fhandle,buf,n);
//   }
//   return 0;
//}
