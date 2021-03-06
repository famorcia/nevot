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

#ifndef NEVOT_SYSTEMCLOCK_HPP
#define NEVOT_SYSTEMCLOCK_HPP

#include "nevot/NTimeT.hpp"
#include "nevot/NClockProperty.hpp"
#include "nevot/NTimeUnavailable.hpp"
#include "nevot/shared_ptr.hpp"

namespace nevot 
{
    /*!
    * @brief Interface Clock: this class provides the basic clock interface, a source of time readings
    */
    class NSystemClock
    {
    public:

        /*!
        * @brief The known properties of the clock.
        * @return reference to clock's properties.
        * @exception no CORBA exception if error occurs in setting properties
        */
        static nevot_std::shared_ptr<NClockProperty> properties();

        /*!
        * @brief Provides a measure of the current time. The time unit is 100
        * nanosecond i.e. 10e-7 seconds.
        *
        * @return TimeT with current time
        * @exception no CORBA exception if error occurs in setting properties
        * @exception nevot::TimeUnavailable if time is not available
        *  with required security assurance.
        */
        static NTimeBase::NTimeT current_time() throw(NTimeUnavailable);

    };
} // namespace nevot

#endif // NEVOT_SYSTEMCLOCK_HPP
