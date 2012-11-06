#pragma once

#include <cmath>
#include <utility>
#include "util/AudoTypes.h"

class SampleInterval 
{
public:
   SampleInterval(t_audoNSamples s0, t_audoNSamples s1) : m_pair(std::min(s0, s1), std::max(s0, s1))
   { }
   t_audoNSamples getStart() const { return m_pair.first; }
   t_audoNSamples getEnd() const { return m_pair.second; }
private:
   std::pair<t_audoNSamples, t_audoNSamples> m_pair;
};

