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

#include "NConfig.hpp"

using namespace nevot;

//-------------------------------------------------------------------------///

const unsigned int
nevot::DECIMAL_PRECISION = 10000;

//-------------------------------------------------------------------------///

const unsigned long
nevot::RESOLUTION = 1000;

//-----------------------------------------------------------------------------
const char* nevot::NEVOTSERVICE_LOGGER = "CDMW.FDS.NEVOT";


/*
extern const NTimeBase::TimeT TIME_BASE =
#ifdef  WIN32
//  To construct the current gregorian time from Windows time we need to add the
//  difference of days between 15th October 1582  and 1th Jan 1601 .
 (NTimeBase::TimeT)FIX_ULL(0x146BF33E42C000);
#else
//  To construct the current gregorian time from UNIX time we need to add the
//  difference of days between 15th October 1582 and 1st Jan 1970.
//  This difference is 141427 days (0x2D8539C80 secs, 0x1B21DD213814000 100*nsec).
 (NTimeBase::TimeT)FIX_ULL(0x1B21DD213814000);
#endif
*/
