/* ===================================================================== */
/*
 * This file is part of CARDAMOM (R) which is jointly developed by THALES
 * and SELEX SISTEMI INTEGRATI.
 * Copyright (C) SELEX SISTEMI INTEGRATI 2010. All rights reserved.
 *
 * CARDAMOM is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * CARDAMOM is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Library General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with CARDAMOM; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
/* ===================================================================== */

#include "nevot/NUtil.hpp"
#include "nevot/NTimeBase.hpp"
#include "nevot/NEVoT.hpp"

#include <stdexcept>
#include <sstream>
#include <cmath>

using namespace std;
using namespace nevot;

///////////////////////////////////////////////////////////////////////////////
// Return the current gregorian time
NTimeBase::NTimeT 
nevot::util::compute_current_time()
{
    NTimeBase::NTimeT out=0;
    /*
    Cdmw::OsSupport::OS::Timeval tv;
    try
    {
        tv=Cdmw::OsSupport::OS::get_time();
        util::CdmwTimeval2TimeT(tv, out);
    }
    catch(...)
    {
        out=(NTimeBase::NTimeT)(-1);
    }
    */
    return out;
}
#if 0
///////////////////////////////////////////////////////////////////////////////

int
nevot::util::compute_time_displacement_factor()
{
    // Set the Time Displacement Factor. The TZ environment variable is
    // read to set the time zone. We convert the timezone value from seconds
    // to minutes.

    ::tzset ();
    long arg = timezone / 60;

    //CORBA::Short newarg = static_cast<CORBA::Short> (arg);
    short newarg = (short) arg;

    return newarg;
}

///////////////////////////////////////////////////////////////////////////////

int
nevot::util::compute_daylight()
{
    return util::get_isdst();
}

///////////////////////////////////////////////////////////////////////////////

double
nevot::util::convert(NTimeBase::NTimeT value)
{
#if defined(WIN32) && (_MSC_VER < 1300)
    return (unsigned long)(value & clock::macro::Mask32);
#else
#   if 0
    return (double)value;
#   else
    long double tmp_val=value;
    double out_value = tmp_val;
    /*
    std::cerr<<"\nTimeT...:"<<value<<std::endl;
    std::cerr<<"ldouble.:"<<tmp_val<<std::endl;
    std::cerr<<"double..:"<<out_value<<std::endl;
    std::cerr<<"d(T)....:"<<(double)value<<std::endl;
    //*/
    return out_value;
#   endif
#endif
}

///////////////////////////////////////////////////////////////////////////////

double
nevot::util::mult(NTimeBase::NTimeT val1, double val2)
{
    double out = 0;
    out = convert(val1) * val2;
    return out;
}
///////////////////////////////////////////////////////////////////////////////

double
nevot::util::add(NTimeBase::NTimeT val1, double val2)
{
    double out = 0;
    out = convert(val1)+val2;
    return out;
}

///////////////////////////////////////////////////////////////////////////////


double
nevot::util::divide(NTimeBase::NTimeT val1, NTimeBase::NTimeT val2)
{
    double num = convert(val1);
    double den = convert(val2);
    return num/den;
}

///////////////////////////////////////////////////////////////////////////////

NTimeBase::NTimeT
nevot::util::seconds2TimeT(double seconds)
throw(std::range_error)
{
    if( seconds < 0 || seconds > 1.8e11 )
        throw   std::range_error("Error: negative seconds!");

#ifdef WIN32
    NTimeBase::NTimeT        
        out = (NTimeBase::NTimeT)(seconds * 1.0e7);
#else
    NTimeBase::NTimeT        
        out = (NTimeBase::NTimeT)(roundl(seconds * 1.0e7));
#endif
    return  out;
}


///////////////////////////////////////////////////////////////////////////////

double
nevot::util::TimeT2seconds(NTimeBase::NTimeT utc)
{
    double
        out = nevot::util::convert(utc);
    out*=1.0e-7;
    return out;
}

///////////////////////////////////////////////////////////////////////////////
NTimeBase::NTimeT
nevot::util::real2controlled (
                        nevot::NControlledClock_ptr clock_ptr,
                        NTimeBase::NTimeT x)
    throw (nevot::NTimeUnavailable)
{
    // assuming that time equation is:
    //
    //    y - y0 = rate * ( x - x0 )
    //

    if( !clock_ptr )
        throw nevot::NTimeUnavailable();

    NTimeBase::NTimeT x0, y0;

    clock_ptr->get_time_origins (x0, y0);

    ldouble rate = clock_ptr->get_rate(),
    abs_rate = fabsl(rate);

    if (rate == 0.0) // CCR187
    {
        return y0; // y = y0
    }

    if (x0 > x)
    {
        //throw CosClockService::TimeUnavailable(); //SPCR214
        CDMW_WARN ( Cdmw::Logging::Logger::Get_Logger ( NEVOTSERVICE_LOGGER ),
                            "real2controlled(): the clock parameter is in the past (i.e. below the current clock origin)," 
                          << "so the result will be calculated with the new speed and origin.");
    }

    NTimeBase::NTimeT
        delta = static_cast<NTimeBase::NTimeT>(llabs(x - x0)); //SPCR214

    NTimeBase::NTimeT out = 0;

    if(rate>=0.0)
    {
        out = (NTimeBase::NTimeT) ( abs_rate * delta) + y0;
    }
    else
    {
        out = (NTimeBase::NTimeT) ( abs_rate * delta);
        if( out > y0 )
            throw nevot::NTimeUnavailable();
        out = y0 - out;
    }
    return out;
}

///////////////////////////////////////////////////////////////////////////////

NTimeBase::NTimeT
nevot::util::controlled2real(
                        nevot::NControlledClock_ptr clock_ptr,
                        NTimeBase::NTimeT y)
    throw (nevot::NTimeUnavailable)
{
    // assuming that time equation is:
    //
    //    y - y0 = rate * ( x - x0 )
    //

    CDMW_ASSERT(clock_ptr);
    if( !clock_ptr )
        throw nevot::NTimeUnavailable();

    NTimeBase::NTimeT
        x0, y0;

    clock_ptr->get_time_origins (x0,
                                 y0);

    ldouble rate = clock_ptr->get_rate();

    if (rate == 0.0)
    {
        throw nevot::NTimeUnavailable();
    }

    NTimeBase::NTimeT
        delta = 0;

    if (rate >= 0.0)
    {
      if ( y < y0 )
          throw nevot::NTimeUnavailable();
      else
        delta = y - y0;
    }
    else
    {
      if ( y > y0 )
          throw nevot::NTimeUnavailable();
      else
        delta = y0 - y;
    }

    NTimeBase::NTimeT
        out = (NTimeBase::NTimeT) (delta / rate) + x0;

    return out;
}

///////////////////////////////////////////////////////////////////////////////

std::string
nevot::util::TimeT2string(const NTimeBase::NTimeT& tmp )
{
    cdmw_tm tm;
    nevot::util::TimeT2cdmw_tm(tmp,tm);
    char buffer[100];
    nevot::util::asctime_r(tm,buffer);
    return std::string(buffer);
}
#endif

