#pragma once

#include <stdexcept>
#include <boost/shared_ptr.hpp>

// Reference-counting Smart Pointer
template <class T>
struct Ref {
   typedef boost::shared_ptr<T> type;
};


/*
class Ref {
   private:
      T *mPtr;
      int mRefCount;

   public:
      Ref<T>(T *ptr) : mPtr(ptr), mRefCount(1) { }

      virtual ~Ref<T>()
      {
         if (!--mRefCount) 
         {
            delete mPtr;
         }
      }

      // Copy constructor
      Ref<T>(Ref<T> & other) : mPtr(other.mPtr), mRefCount(++other.mRefCount) { }

      // Copy Assignment
      Ref<T> operator=(const Ref<T>& other)
      {
         if (this != &other) {
            throw std::runtime_error("May not reassign smart pointer");
         }
         return *this;
      }

      // Equality
      bool operator==(const Ref<T>& other) const
      {
         return (mPtr == other.mPtr);
      }
      bool operator!=(const Ref<T>& other) const
      {
         return !(*this == other);
      }

      T &operator *() const { return *mPtr; }
      T *operator ->() const { return mPtr; }
};
*/
