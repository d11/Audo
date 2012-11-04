#pragma once

class Logger {
   public:
      Logger() {};
      virtual ~Logger() {};
      virtual void log() = 0;
};
