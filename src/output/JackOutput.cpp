#include "output/JackOutput.h"
#include "model/BufferRef.h"
#include "model/StandardBuffer.h"
#include <sstream>

JackOutput::JackOutput() {
   start();
}

JackOutput::~JackOutput() {
   stop();
}

// Return a reference to a Buffer that should be filled with output
WritableBufferRef JackOutput::getNextOutputBuffer(jack_nframes_t frames)
{
   jack_default_audio_sample_t *out = (jack_default_audio_sample_t *) jack_port_get_buffer (outputPort, frames);
   return WritableBufferRef(new WritableBuffer(frames, 44100, "", out));
}

void JackOutput::start()  {
   log("Initialising Jack output");

   jack_status_t status;
   jack_options_t options = JackNullOption;

   if ((client = jack_client_open("sndj", options , &status )) == 0) {
      log("Couldn't connect to jack!");
      failure();
   }
   jack_set_process_callback(client, processCallback, this);
   jack_on_shutdown(client, shutdownCallback, this);
   sampleRate = jack_get_sample_rate(client);
   std::stringstream s;
   s << "sample rate is " << sampleRate;
   log(s.str());

   outputPort = jack_port_register(client, "output", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

   if (jack_activate(client)) {
      log("Couldn't activate client!");
      failure();
   }

   if ((ports = jack_get_ports(client, NULL, NULL, JackPortIsPhysical | JackPortIsInput)) == NULL) {
      log("There were no physical ports accepting input!");
      failure();
   }
   if (jack_connect (client, jack_port_name(outputPort), ports[0])) {
      log("Couldn't connect to the desired output port!?");
      failure();
   }

   // connected to jack, ready for output
}


void JackOutput::serverShutdown()
{
   log("Jack server was shut down.");
}

void JackOutput::stop() {
   log("Detaching client from Jack server");
   jack_client_close(client);
}

void JackOutput::shutdownCallback(void *arg) {
   JackOutput *output = static_cast<JackOutput*>(arg);
   output->serverShutdown();
}

int JackOutput::processCallback(jack_nframes_t frames, void *arg)
{
   JackOutput *output = static_cast<JackOutput*>(arg);
   WritableBufferRef buffer(output->getNextOutputBuffer(frames));
   output->fillBuffer(buffer);
   return 0;
}

void JackOutput::failure() {
   log("Jack output error!");
   //throw new Exception(); TODO FIXME
}

