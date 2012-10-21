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

#ifndef NEVOT_NEXECUTOR_HPP
#define NEVOT_NEXECUTOR_HPP

#include "nevot/NIClock.hpp"
#include "nevot/NPeriodic.hpp"
#include "nevot/NController.hpp"

namespace nevot 
{
    namespace NPeriodicExecution
    {
        /*!
         * @brief Executor is a factory for controller.
         */
        class NExecutor : public virtual NIClock
        {
        public:

            virtual NController_sptr enable_periodic_execution(const nevot_std::shared_ptr<NPeriodic>& on );

            virtual	~NExecutor(){
            }

        private:
            class Impl;
            std::auto_ptr<Impl> m_pimpl;

            NExecutor(const NExecutor&);
            NExecutor& operator=(const NExecutor&);
        };

        typedef nevot_std::shared_ptr<NExecutor>    NExecutor_sptr;

    } // namespace NPeriodicExecution
} // namespace nevot


#endif //! NEVOT_NCLOCKSERVICE_NEXECUTOR_HPP
