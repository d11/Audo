#include "AudioReader.h"
#include <sndfile.hh>

#include <QDebug>


Buffer &AudioReader::loadAudio(const char *filePath) {
   SNDFILE *inputFile;
   SF_INFO inputFormat;
   inputFile = sf_open(filePath, SFM_READ, &inputFormat);
   if (NULL == inputFile) return NULL;
   qDebug() << "Opened sound file";

   int sampleRate = inputFormat.samplerate;
   long frameCount = inputFormat.frames;

   // TODO multiple channels
   int channels = inputFormat.channels;
   if (channels != 1)
      qDebug() << "Warning - multiple channels not implemented";

   StandardBuffer *buff = new StandardBuffer(frameCount, sampleRate, "Test Buffer 2");

   // read into temp array
   double *tempData = new double[frameCount*channels];

   int read = sf_readf_double(inputFile, tempData, frameCount);

   qDebug() << "read " << read << " frames into temp memory";

   // copy to buffer
   buff->copyData(tempData, 0, frameCount);

   delete[] tempData;
   if (sf_close(inputFile) != 0) qDebug() << "Error closing file";

   return *buff;
}
