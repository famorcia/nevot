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
/* ===================================================================== */

#ifndef NEVOT_HPP
#define NEVOT_HPP

namespace nevot 
{
    /*! \brief This class contains the controller methods for service 
    *         initialization/finalization.
    */
    class NEVoT
    {
    public:
        /*! \brief Initialize the service.
        *
        *  \note This method should be called just after the 
        *        entry point of your application
        */
        static bool init (int argc, char **argv);


        /*! \brief Finalize the service.
        *
        *  \note This method should be called just before the 
        *        shutdown of your application.
        *        If the "finish" is not called the resources 
        *        are cleanly removed automatically by the framework.
        */
        static bool finish();
    };
} // namespace nevot

#endif // NEVOT_HPP
