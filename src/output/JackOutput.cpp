
#include "output/JackOutput.h"
#include "model/BufferRef.h"
#include "model/StandardBuffer.h"

JackOutput::JackOutput() : StreamLogger(std::cerr) {
   start();
}

JackOutput::~JackOutput() {
   stop();
}

// Return a reference to a Buffer that should be filled with output
BufferRef JackOutput::getNextOutputBuffer(jack_nframes_t frames)
{
   jack_default_audio_sample_t *out = (jack_default_audio_sample_t *) jack_port_get_buffer (outputPort, frames);
   return BufferRef(new StandardBuffer(frames, 44100, "", out));
}

void JackOutput::start()  {
   log("starting");

   jack_status_t status;
   jack_options_t options = JackNullOption;

   if ((client = jack_client_open("sndj", options , &status )) == 0) {
      log("Couldn't connect to jack!");
      failure();
   }
   // TODO: check what '0' does  etc
   jack_set_process_callback(client, processCallback, this);
   //jack_on_shutdown(client, shutdownCallback, 0); TODO make work
   sampleRate = jack_get_sample_rate(client);
   log("sample rate is " + sampleRate);

   outputPort = jack_port_register(client, "output", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

   if (jack_activate(client)) {
      log("Couldn't activate client!");
      failure();
   }

   /* TODO FIXME
   if ((ports = jack_get_ports(client, NULL, NULL, JackPortIsPhysical | JackPortIsInput)) == NULL) {
      log("There were no physical ports accepting input!");
      failure();
   }
   */
   if (jack_connect (client, jack_port_name(outputPort), ports[0])) {
      log("Couldn't connect to the desired output port!?");
      failure();
   }

   // connected to jack, ready for output


}

void JackOutput::fillBuffer(BufferRef buffer)
{
   long n = buffer->getNumberOfSamples();

   // TODO
}

void JackOutput::stop() {
   log("stopping");
   jack_client_close(client);
}
void JackOutput::shutdownCallback(void *arg) {
   //log("Server shut down or disconnected!");
   //failure();
}
int JackOutput::processCallback(jack_nframes_t frames, void *arg) {
   //log("processCallback");
   JackOutput *output = static_cast<JackOutput*>(arg);
   BufferRef buffer = output->getNextOutputBuffer(frames);
   output->fillBuffer(buffer);
   return 0;
}
void JackOutput::failure() {
   log("Jack Output error!");
   //throw new Exception(); TODO FIXME
}

