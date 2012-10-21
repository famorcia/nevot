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

#ifndef NEVOT_NCONTROLLER_HPP
#define NEVOT_NCONTROLLER_HPP

#include "nevot/NTimeT.hpp"
#include "nevot/NPeriodic.hpp"
#include "nevot/shared_ptr.hpp"
#include "nevot/any.hpp"
#include "nevot/NControllerUpdateStrategy.hpp"

#include <exception>
#include <memory>

namespace nevot 
{
    namespace NPeriodicExecution 
    {
        /*!
        * @brief Interface NController: this class provides control for periodic execution
        */
        class NController
        {
        public:

            // Exception TimePast{}
            class TimePast: public std::exception
            {
            public:
                TimePast() throw() {};
            };

            // Exception NotAllowedStatus{}
            class NotAllowedStatus: public std::exception
            {
            public:
                NotAllowedStatus() throw() {};
            };

            //! Constructor
            NController( );

            //! Destructor
            virtual ~NController();                                                     

            void start( NTimeBase::NTimeT period,
                NTimeBase::NTimeT with_offset,
                unsigned long execution_limit,
                nevot_std::any& any_param ) throw (NotAllowedStatus); //! 0 = no limit

            void start_at( NTimeBase::NTimeT period,
                NTimeBase::NTimeT at_time,
                unsigned long execution_limit ) //! 0 = no limit
                throw(NotAllowedStatus,TimePast);                

            void pause();
            void resume();
            void resume_at(NTimeBase::NTimeT at_time) throw(TimePast);
            unsigned long executions();
            void stop();
            void terminate();
            
            //bool is_paused() const;

            void set_update_strategy( NControllerUpdateStrategy id );// throw ( NControllerUpdateStrategyRegistry::UnknownStrategy );
            NControllerUpdateStrategy get_update_strategy() const;
        
        private:
            NController(const NController&);
            NController& operator=(const NController&);
            class   Impl;
            std::auto_ptr<Impl> m_pimpl;
        };

        typedef nevot_std::shared_ptr<NController>    NController_sptr;

    } // namespace NPeriodicExecution
} // namespace nevot


#endif  // NEVOT_NPERIODICEXECUTION_NCONTROLLER_HPP
