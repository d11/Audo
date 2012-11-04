
#include "output/JackOutput.h"

JackOutput::JackOutput() : StreamLogger(std::cerr) {
   start();
}

JackOutput::~JackOutput() {
   stop();
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
   //jack_set_process_callback(client, processCallback, 0); TODO make work
   //jack_on_shutdown(client, shutdownCallback, 0); TODO make work
   sampleRate = jack_get_sample_rate(client);
   log("sample rate is " + sampleRate);

   jack_port_t *outputPort = jack_port_register(client, "output", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

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


void JackOutput::stop() {
   log("stopping");
   jack_client_close(client);
}
void JackOutput::shutdownCallback(void *arg) {
   log("Server shut down or disconnected!");
   failure();
}
int JackOutput::processCallback(jack_nframes_t frames, void *arg) {

}
void JackOutput::failure() {
   log("FAAAILUUUURE!!");
   //throw new Exception(); TODO FIXME
}

