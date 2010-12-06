/*!===================================================================== */
/*!
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
/*!===================================================================== */

#include <Foundation/commonsvcs/nevot/NClockCatalog.hpp>
#include <Foundation/commonsvcs/nevot/NIClock.hpp>


using namespace Cdmw::CommonSvcs::nevot;


class NClockCatalogImpl 
{
    static NClockCatalogImpl* M_clockcatalog_singleton;
    NClockCatalog::NClockEntries m_clock_entries;
public:

    //-------------------------------------------------------------------------
    ~NClockCatalogImpl()
    {
        this->m_clock_entries.clear();
    }

    //-------------------------------------------------------------------------
    static NClockCatalogImpl* instance()
    {
        if( 0 == M_clockcatalog_singleton )
        {
            M_clockcatalog_singleton = new NClockCatalogImpl();
        }

        return M_clockcatalog_singleton;
    }

    //-------------------------------------------------------------------------
    NClockCatalog::NClockEntry get_entry(const std::string& with_name) 
        throw (NUnknownEntry)
    {
        NClockCatalog::const_iterator
            it_end =  this->m_clock_entries.end(),
            it = this->m_clock_entries.find(with_name);

        if(it==it_end)
            throw NUnknownEntry();

        return *it;
    }

    //-------------------------------------------------------------------------
    NClock_sptr get_clock(const std::string& with_name) 
        throw (NUnknownEntry)
    {
        NClockCatalog::const_iterator
            it_end =  this->m_clock_entries.end(),
            it = this->m_clock_entries.find(with_name);

        if(it==it_end)
            throw NUnknownEntry();

        return it->second;
    }

    //-------------------------------------------------------------------------
    NClockCatalog::NClockEntries   available_entries(NClockCatalog::NClockEntries& entries)
    {
        NClockCatalog::NClockEntries out(this->m_clock_entries);
        return out;
    }

    //-------------------------------------------------------------------------
    void    add(NClockCatalog::NClockEntry entry)
    {
        const std::string& entry_name = entry.first;
        NClockCatalog::const_iterator
            it_end =  this->m_clock_entries.end(),
            it = this->m_clock_entries.find(entry_name);

        if(it!=it_end)
        {
            delete_entry(entry_name);
        }

        this->m_clock_entries[entry_name] = entry.second;
    }

    //-------------------------------------------------------------------------
    void delete_entry(const std::string& with_name) 
        throw (NUnknownEntry)
    {
        this->m_clock_entries.erase(with_name);
    }

    //-------------------------------------------------------------------------
    NClockCatalog::const_iterator begin() const
    {
        return this->m_clock_entries.begin();
    }

    //-------------------------------------------------------------------------
    NClockCatalog::const_iterator end() const
    {
        return this->m_clock_entries.end();
    }

};

//sets sigleton instance to NULL
NClockCatalogImpl* NClockCatalogImpl::M_clockcatalog_singleton = 0;

//-----------------------------------------------------------------------------
NClockCatalog::NClockEntry NClockCatalog::get_entry(const std::string& with_name) 
    throw (NUnknownEntry)
{
    return NClockCatalogImpl::instance()->get_entry(with_name);
}

//-----------------------------------------------------------------------------
NClock_sptr NClockCatalog::get_clock(const std::string& with_name) 
    throw (NUnknownEntry)
{
    return NClockCatalogImpl::instance()->get_clock(with_name);
}

//-----------------------------------------------------------------------------
void    NClockCatalog::available_entries(NClockEntries& entries)
{
    NClockCatalogImpl::instance()->available_entries(entries);
}

//-----------------------------------------------------------------------------
void    NClockCatalog::add(NClockEntry& entry)
{
    NClockCatalogImpl::instance()->add(entry);
}

//-----------------------------------------------------------------------------
void    NClockCatalog::remove(const std::string& with_name) 
    throw (NUnknownEntry)
{
    NClockCatalogImpl::instance()->delete_entry(with_name);
}

//-----------------------------------------------------------------------------

NClockCatalog::const_iterator NClockCatalog::begin()
{
    return NClockCatalogImpl::instance()->begin();
}

//-----------------------------------------------------------------------------

NClockCatalog::const_iterator NClockCatalog::end()
{
    return NClockCatalogImpl::instance()->end();
}

//-----------------------------------------------------------------------------
// EOF
//-----------------------------------------------------------------------------

