#pragma once

// Reference-counting Smart Pointer
template <typename T>
class Ref {
   private:
      T& mPtr;
      int mRefCount;

   public:
      Ref<T>(const T& ptr) : mPtr(ptr), mRefCount(1) { }

      // Copy constructor
      Ref<T>(const Ref<T>& other) { }

      // Copy Assignment
      Ref<T> operator=(const Ref<T>& other)
      {
         if (this != &other) {
            
         }
         return *this;
      }

      // Equality
      bool operator==(const Ref<T>& other)
      {
         return (mPtr == other.Get())
      }

      T Get() const
      {
         return mPtr

};
