#include <util/log/logger.h>

class StreamLogger : public Logger{
   private:
      const std::ostream &logStream;
   public:

   StreamLogger(const std::ostream &s) : Logger(), logStream(s) { }
   ~StreamLogger();

   void log(const std::string &msg) {
      (*logStream) << msg << std::endl;
   }
};
