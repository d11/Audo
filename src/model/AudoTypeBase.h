#pragma once

#include <typeinfo>

class QString;

class AudoTypeBase
{
public:
   AudoTypeBase(const std::type_info & id);
   virtual ~AudoTypeBase();
   bool operator==(const AudoTypeBase & other) const;
   bool operator!=(const AudoTypeBase & other) const;

   QString getTypeName() const;

private:
   const std::type_info & m_id;
};
