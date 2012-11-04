#include "AudioReader.h"
#include "model/BufferRef.h"
#include <sndfile.h>

#include <QDebug>
#include <QString>

BufferRef AudioReader::loadAudio(const QString & filePath) {

   QByteArray filePathByteArray = filePath.toLocal8Bit();

   SNDFILE *inputFile;
   SF_INFO inputFormat;
   inputFile = sf_open(filePathByteArray.data(), SFM_READ, &inputFormat);
   if (NULL == inputFile) return BufferRef(new StandardBuffer(1,1,"Invalid buffer")); // TODO
   qDebug() << "Opened sound file";

   int sampleRate = inputFormat.samplerate;
   long frameCount = inputFormat.frames;

   // TODO multiple channels
   int channels = inputFormat.channels;
   if (channels != 1)
      qDebug() << "Warning - multiple channels not implemented";

   StandardBuffer *buff = new StandardBuffer(frameCount, sampleRate, "Test Buffer 2");

   // read into temp array
   float *tempData = new float[frameCount*channels];

   int read = sf_readf_float(inputFile, tempData, frameCount);

   qDebug() << "read " << read << " frames into temp memory";

   // copy to buffer
   buff->copyData(tempData, 0, frameCount);

   delete[] tempData;
   if (sf_close(inputFile) != 0) qDebug() << "Error closing file";

   return BufferRef(buff);
}
