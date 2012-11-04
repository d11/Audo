#include "AudoTypeBase.h"

#include <QString>
#include <typeinfo>

AudoTypeBase::AudoTypeBase(const std::type_info & id)
 : m_id(id)
{ }

AudoTypeBase::~AudoTypeBase()
{ }

QString AudoTypeBase::getTypeName() const
{
   return m_id.name();
}

bool AudoTypeBase::operator==(const AudoTypeBase & other) const
{
   return m_id == other.m_id;
}

bool AudoTypeBase::operator!=(const AudoTypeBase & other) const
{
   return !(*this == other);
}
