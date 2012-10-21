/* ===================================================================== */
/*
 * This file is part of CARDAMOM (R) which is jointly developed by THALES
 * and SELEX SISTEMI INTEGRATI.
 * Copyright (C) SELEX SISTEMI INTEGRATI 2010-2012. All rights reserved.
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

#ifndef NEVOT_UTIL_HPP
#define NEVOT_UTIL_HPP

#include "nevot/NTimeUnavailable.hpp"
#include "nevot/NTimeBase.hpp"

#include <string>
#include <stdexcept>

namespace nevot 
{

    /*!
    * @namespace nevot::util
    * @brief Namespace that contains a lot of useful functions to work with
    * NTimeBase::NTimeT.
    *
    * The namespace @code util @endcode maintains some functions that are
    * not strictly related with CORBA Enhanced View of Time implementation.
    */
    namespace util {

        /*!
        * @brief Auxililary function to compute current machine time.
        */
        NTimeBase::NTimeT compute_current_time();

        /*!
        * @brief Auxililary function to retrieve offset
        * from GMT (+ if East,- if West).
        */
        int compute_time_displacement_factor();

        /*!
        *
        */
        int compute_daylight();

#if 0


        /*!
        * @brief Retrieve the "virtual" time related to a Controlled clock.
        * @param theControlledClock The reference ControlledClock.
        * @param when Time to convert.
        * @return The time in ControlledClock base.
        * @exception CosClockService::TimeUnavailable This exception can be raised
        *            if operation is unavailable (time in the past or in the future).
        */

        //    NTimeBase::NTimeT
        //    real2controlled (CdmwStd::shared_ptr<nevot::NControlledClock_T<Cdmw::OsSupport::Mutex> > theControlledClock, NTimeBase::NTimeT when)
        //        throw (NTimeUnavailable);
        NTimeBase::NTimeT
            real2controlled (nevot::NControlledClock_ptr theControlledClock, NTimeBase::NTimeT when)
            throw (NTimeUnavailable);

        /*!
        * @brief Retrieve the actual time related to a Controlled clock.
        * @param theControlledClock The reference ControlledClock.
        * @param when Time to convert.
        * @return The time in GMT base.
        * @exception CosClockService::TimeUnavailable This exception can be raised
        *            if operation is unvailable (time in the past or in the future).
        */
        NTimeBase::NTimeT 
            controlled2real(nevot::NControlledClock_ptr theControlledClock, NTimeBase::NTimeT when)
            throw (NTimeUnavailable);

        /*!
        * @brief mult a NTimeT with a double and return a double.
        */
        double mult(NTimeBase::NTimeT, double);

        /*!
        * @brief add a NTimeT with a double and return a double.
        */
        double add(NTimeBase::NTimeT, double);

        /*!
        * @brief divide a NTimeT with a double and return a double.
        */
        double divide(NTimeBase::NTimeT, NTimeBase::NTimeT );

        /*!
        * @brief conversion NTimeT vs double.
        */
        double convert(NTimeBase::NTimeT);

        /*!
        * @brief Conversion from seconds to TimetT.
        * @exception range_error The exception is thrown if seconds are negatives.
        */
        NTimeBase::NTimeT seconds2TimeT(double seconds)
            throw  (std::range_error);

        /*!
        * @brief Conversion from TimetT to seconds.
        * @param val The value in NTimeT.
        */
        double TimeT2seconds(NTimeBase::NTimeT val);

        std::string TimeT2string(const NTimeBase::NTimeT& time2convert);
#endif

    } // namespace util
} // namespace nevot

#endif /* NEVOT_UTIL_HPP */
