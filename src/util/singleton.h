#pragma once

template <class T>
class Singleton {
   public:
      static T& getInstance() {
         static T instance;
         return instance;
      }
   private:
      Singleton();                            // Hide constructor
      Singleton(const Singleton&);            // Hide copy ctor
      Singleton& operator=(const Singleton&); // Hide assignment
      ~Singleton();                           // Hide dtor

};
