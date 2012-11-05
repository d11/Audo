#pragma once

#include <cmath>
#include <utility>

class SampleInterval 
{
public:
   SampleInterval(long s0, long s1) : m_pair(std::min(s0, s1), std::max(s0, s1))
   { }
private:
   std::pair<long, long> m_pair;
};

