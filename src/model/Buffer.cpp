#include "Buffer.h"
#include <QString>

Buffer::Buffer(int sampleRate, QString name) {
   this->name = name;
   this->sampleRate = sampleRate;
}

Buffer::~Buffer() { }

//	Calculate the duration (in seconds) of the buffer
double Buffer::getDuration() {
   return (double)getNumberOfSamples()/(double)sampleRate;
}

// Return the name that was assigned to the buffer
const QString &Buffer::getName() {
	return name;
}
