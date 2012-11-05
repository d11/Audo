#pragma once

#include "util/log/Logger.h"

class StreamLogger : public Logger {
   public:

   StreamLogger(std::ostream & s) : Logger(), m_logStream(s) { };
   virtual ~StreamLogger() {};

   void log(const std::string & msg) {
      m_logStream << msg << std::endl;
   }

   private:
      std::ostream & m_logStream;
};
