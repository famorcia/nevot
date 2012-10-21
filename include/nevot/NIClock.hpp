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

#ifndef NEVOT_NICLOCK_HPP
#define NEVOT_NICLOCK_HPP

#include "nevot/NTimeBase.hpp"
#include "nevot/NClockProperty.hpp"
#include "nevot/NTimeUnavailable.hpp"
#include "nevot/shared_ptr.hpp"

namespace nevot 
{
    class NIClock 
    {
    public:
    	virtual ~NIClock(){

    	}

        /*!
        * @brief The known properties of the clock.
        * @return reference to clock's properties.
        * @exception no exception if error occurs in setting properties
        */
        virtual nevot_std::shared_ptr<NClockProperty> properties() const = 0;

        /*!
        * @brief Provides a measure of the current time. The time unit is 100
        * nanosecond i.e. 10e-7 seconds.
        *
        * @return TimeT with current time
        * @exception no CORBA exception if error occurs in setting properties
        * @exception nevot::TimeUnavailable if time is not available
        *  with required security assurance.
        */
        virtual NTimeBase::NTimeT current_time() throw(NTimeUnavailable) = 0;
    };

    //! smart pointer for clock objects
    typedef nevot_std::shared_ptr<NIClock>    NClock_sptr;

} // namespace nevot

#endif // NEVOT_NICLOCK_HPP

