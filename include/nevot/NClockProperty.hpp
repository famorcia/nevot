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

#ifndef NEVOT_NCLOCKPROPERTY_HPP
#define NEVOT_NCLOCKPROPERTY_HPP

#include <string>

namespace nevot
{
    class NIClock;

    class NClockProperty
    {
        unsigned long m_resolution;                 //! units = nanoseconds
        short m_precision;                          /*! ceiling of log_2(seconds signified by least
                                                    * significant bit of time readout
                                                    */ 
        unsigned short m_width;                     //! no. of bbits in readout - usually <= 64
        std::string m_stability_description;

        enum Coordination {
            Uncoordinated = 0,                      //!only static characterization is available
            Coordinated = 1,                        //! measured against another source
            Faulty = 2                              //! e.g., there is a bit stuck
        };
        Coordination m_coordination;

        //! The following are only applicable for coordinated clocks
        struct Offset {
            long long measured;                     //! units = 100 nanoseconds
            long long deliberate;                   //! units = 100 nanoseconds

            Offset(const Offset& d) { init(d); }
            Offset& operator=(const Offset& d) 
            {
                init(d);
                return *this;
            }
        private:
            void init(const Offset& d) {
                measured   = d.measured;
                deliberate = d.deliberate;
            }

        };
        Offset m_offset;

        enum Measurement {
            Not_Determined = 0,                     //! has not been measured
            Discontinuous = 1,                      //! e.g., one clock is paused
            Available = 2                           //! has been measured
        };
        Measurement m_measurement;

        typedef float Hz;
        struct Skew {
            Measurement available;
            Hz measured;                            //! only meaningful if available = Available - in Hz
            Hz deliberate;                          //! in Hz

            Skew(const Skew& d) { init(d); }
            Skew& operator=(const Skew& d) 
            {
                init(d);
                return *this;
            }
        private:
            void init(const Skew& d) {
                available  = d.available;
                measured   = d.measured;
                deliberate = d.deliberate;
            }
        };
        Skew m_skew;

        typedef float HzPerSec;
        struct Drift {
            Measurement available;
            HzPerSec measured;                      /*! meaningful if available = Available
                                                    * in Hz/sec
                                                    */
            HzPerSec deliberate;                    //! in Hz/sec

            Drift(const Drift& d) { init(d); }
            Drift& operator=(const Drift& d) 
            {
                init(d);
                return *this;
            }
        private:
            void init(const Drift& d) {
                available  = d.available;
                measured   = d.measured;
                deliberate = d.deliberate;
            }
        };    
        Drift m_drift;

        enum TimeScale {
            Unknown = -1,
            TAI = 0,                                //! International Atomic Time
            UT0 = 1,                                //! diurnal day
            UT1 = 2,                                //! + polar wander
            UTC = 3,                                //! TAI + leap seconds
            TT = 4,                                 //! terrestrial time
            TDB = 5,                                //! Barycentric Dynamical Time
            TCG = 6,                                //! Geocentric Coordinate Time
            TCB = 7,                                //! Barycentric Coordinate Time
            Sidereal = 8,                           //! hour angle of vernal equinox
            Local = 9,                              //! UTC + time zone
            GPS = 10,                               //! Global Positioning System
            Other = 0x7fff                          //! e.g. mission
        };
        TimeScale m_timescale;

        enum Stratum {
            unspecified = 0,
            primary_reference = 1,
            secondary_reference_base = 2
        };
        Stratum m_stratum;

        // CdmwStd::shared_ptr<NIClock> CoordinationSource;           //! what clock is coordinating with

        std::string m_comments;

    public:   
        //Resolution
        unsigned long get_resolution() const { return (m_resolution); };
        void set_resolution(unsigned long resolution) { m_resolution = resolution; };

        //Precision
        short get_precision() const { return (m_precision); };
        void set_precision(short precision) { m_precision = precision; };

        //Width
        unsigned short get_width() const { return (m_width); };
        void set_width(unsigned short width) { m_width = width; };

        //Stability_Description
        std::string get_stability_description() const { return (m_stability_description); };
        void set_stability_description(std::string stability_description) { m_stability_description = stability_description; };

        //Coordination
        Coordination get_coordination() const { return (m_coordination); };
        void set_coordination(Coordination coordination) { m_coordination = coordination; };

        //Offset
        Offset get_offset() const { return (m_offset); };
        void set_offset(Offset offset) { m_offset = offset; };

        //Measurement
        Measurement get_measurement() const { return (m_measurement); };
        void set_measurement(Measurement measurement) { m_measurement = measurement; };

        //Skew
        Skew get_skew() const { return (m_skew); };
        void set_skew(Skew skew) { m_skew = skew; };

        //Drift
        Drift get_drift() const { return (m_drift); };
        void set_drift(Drift drift) { m_drift = drift; };

        //TimeScale
        TimeScale get_timeScale() const { return (m_timescale); };
        void set_timeScale(TimeScale timescale) { m_timescale = timescale; };

        //Stratum
        Stratum get_stratum() const { return (m_stratum); };
        void set_stratum(Stratum stratum) { m_stratum = stratum; };

        //Comments
        std::string get_comments() const { return (m_comments); };
        void set_comments(const std::string& comments) { m_comments = comments; };

    }; // class NClockProperty

} // namespace nevot

#endif // NEVOT_NCLOCKPROPERTY_HPP
