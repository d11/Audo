#pragma once

#include <stdexcept>

// Reference-counting Smart Pointer
template <class T>
class Ref {
   private:
      T *mPtr;
      int mRefCount;

   public:
      Ref<T>(T *ptr) : mPtr(ptr), mRefCount(1) { }

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
