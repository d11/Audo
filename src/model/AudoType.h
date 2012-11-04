#pragma once

#include "model/AudoTypeBase.h"

#include <QString>

template< class T >
class AudoType : public AudoTypeBase
{
public:
   AudoType() : AudoTypeBase(typeid(T)) { };
   virtual ~AudoType() { };

};
