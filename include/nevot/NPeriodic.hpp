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

#ifndef NEVOT_NPERIODICEXECUTION_PERIODIC_HPP
#define NEVOT_NPERIODICEXECUTION_PERIODIC_HPP

#include "nevot/any.hpp"

namespace nevot 
{
    namespace NPeriodicExecution 
    {
        /*!
        * @brief Interface NPeriodic: this class provides base (conceptually abstract) for
        *        objects that can be invoked periodically
        */
        class NPeriodic
        {
        public:
            NPeriodic();
            virtual ~NPeriodic();

            //! @return false terminates periodic execution
            virtual bool do_work(nevot_std::any& aparam) = 0;       

        private:
            NPeriodic(const NPeriodic&);
            NPeriodic& operator=(const NPeriodic&);
        };

    } // namespace NPeriodicExecution
} // namespace nevot

#endif //! NEVOT_NPERIODICEXECUTION_PERIODIC_HPP
