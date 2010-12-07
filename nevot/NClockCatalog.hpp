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

#ifndef NEVOT_NCLOCKCATALOG_HPP
#define NEVOT_NCLOCKCATALOG_HPP

#include "nevot/NIClock.hpp"
#include "nevot/NUnknownEntry.hpp"

#include <string>
#include <map>
#include <list>

namespace nevot 
{
    /*!
    *   @brief The ClockCatalog interface allows applications to discover 
    *          and select a clock for use
    *
    *   It is a singleton in order to allow multiple accesses for getting 
    *   Clock references.
    */
    class NClockCatalog
    {
    public:

        //! An alias for the internal representation.
        typedef std::map< std::string, NClock_sptr > NClockEntries;

        /*!
        *  @brief This structure holds the known information about a clock: 
        *         its name and its object reference
        */
        typedef NClockEntries::value_type NClockEntry;

        //! An iterator.
        typedef NClockEntries::const_iterator const_iterator;

        /*!
        *   @brief Return a single clock entry holding the information about 
        *          a particular clock.
        *          The clock entry is selected through the clock name.
        */
        static NClockEntry get_entry(const std::string& with_name) throw (NUnknownEntry);

        /*!
        *   @brief Return a single clock reference.
        *
        *          The clock entry is selected through the clock name.
        */
        static NClock_sptr get_clock(const std::string& with_name) throw (NUnknownEntry);

        /*!
        *  @brief Return the whole catalog to allow the client the application 
        *         of a more specific selection mechanism, as for example by a 
        *         specific property.
        *
        *  @deprecated This acccessor break the insulation will be removed 
        *
        *  @see NClockCatalog::begin(), NClockCatalog::end() 
        */
        static void available_entries(NClockEntries&);

        /*!
        *  @brief add a new clock entry in the catalog.
        *
        *  @note "add" is alias for former operation "register"          
        */
        static void add(NClockEntry& entry);

        /*!
        *   @brief Remove a clock entry from the clock catalog.
        *
        *   @note This operation can not be applied to "standard" clocks
        */
        static void remove(const std::string& with_name) throw (NUnknownEntry);

        /*!
        *   @brief Retrieve the first "pointer" in the clock catalog.
        */
        static const_iterator begin();

        /*!
        *   @brief Retrieve the last "pointer" in the clock catalog.
        */
        static const_iterator end();
    };

} // namespace nevot

#endif // NEVOT_NCLOCKCATALOG_HPP
