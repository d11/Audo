#pragma once

#include "util/log/Logger.h"

class StreamLogger : public Logger{
   private:
      std::ostream &logStream;
   public:

   StreamLogger(std::ostream &s) : Logger(), logStream(s) { };
   virtual ~StreamLogger() {};

   void log(const std::string &msg) {
      logStream << msg << std::endl;
   }
};
