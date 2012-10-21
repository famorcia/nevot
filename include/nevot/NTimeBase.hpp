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

#ifndef NEVOT_NTIMEBASE_HPP
#define NEVOT_NTIMEBASE_HPP

#include "nevot/NTimeT.hpp"

namespace nevot 
{
    namespace NTimeBase
    {
        /*! 
        *  @brief InaccuracyT represents the value of inaccuracy in time in units of 
        *         100 nanoseconds
        */
        typedef NTimeT InaccuracyT;


        /*! 
        *  @brief TdfT is of size 16 bits short type and holds the time displacement factor 
        *         in the form of minutes of displacement from the Greenwich Meridian.
        */
        typedef short TdfT;

        /*! 
        *  @brief UtcT defines the structure of the time value that is used universally in this 
        *         service. The basic value of time is of type NTimeT that is held in the time field
        */
        struct UtcT {
            NTimeT       time;               
            unsigned long   inacclo;
            unsigned short  inacchi;
            TdfT        tdf;
        };

        /*! 
        *  @brief This type holds a time interval represented as two NTimeT values corresponding 
        *         to the lower and upper bound of the interval.
        */
        struct IntervalT {
            NTimeT lower_bound;
            NTimeT upper_bound;
        };

    } // namespace NTimeBase
} // namespace nevot


#endif //! NEVOT_NTIMEBASE_HPP
