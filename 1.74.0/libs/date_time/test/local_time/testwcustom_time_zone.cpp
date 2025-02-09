/* Copyright (c) 2003-2005 CrystalClear Software, Inc.
 * Subject to the Boost Software License, Version 1.0. 
 * (See accompanying file LICENSE_1_0.txt or http://www.boost.org/LICENSE_1_0.txt)
 * Author: Jeff Garland, Bart Garst
 * $Date: 2020/09/08 20:02:32 $
 */

#include "boost/date_time/local_time/local_time.hpp"
#include "../testfrmwk.hpp"
#include <iostream>

int
main()
{

  using namespace boost::gregorian;
  using namespace boost::posix_time;
  using namespace boost::local_time;

  typedef custom_time_zone_base<wchar_t> wcustom_time_zone;

  boost::shared_ptr<dst_calc_rule> 
    rule1(new partial_date_dst_rule(partial_date(30,Apr),
                                    partial_date(30,Oct)));
  
  boost::shared_ptr<dst_calc_rule> 
    rule2(new first_last_dst_rule(first_last_dst_rule::start_rule(Sunday,Apr),
                                  first_last_dst_rule::end_rule(Sunday,Oct)));
  boost::shared_ptr<dst_calc_rule> 
    rule3(new last_last_dst_rule(last_last_dst_rule::start_rule(Sunday,Mar),
                                 last_last_dst_rule::end_rule(Sunday,Oct)));
  boost::shared_ptr<dst_calc_rule> rule4; // no daylight savings
  
  wtime_zone_names pst(L"Pacific Standard Time",
                      L"PST", 
                      L"Pacific Daylight Time" ,
                      L"PDT");
  wtime_zone_names mst(L"Mountain Standard Time",
                      L"MST", 
                      L"" ,
                      L"");
  
  dst_adjustment_offsets of(hours(1), hours(2), hours(2));
  dst_adjustment_offsets of2(hours(0), hours(0), hours(0)); // no daylight savings

  wtime_zone_ptr tz1(new wcustom_time_zone(pst, hours(-8), of, rule1));
  wtime_zone_ptr tz2(new wcustom_time_zone(pst, hours(-8), of, rule2));
  wtime_zone_ptr tz3(new wcustom_time_zone(pst, hours(-8), of, rule3));
  wtime_zone_ptr tz4(new wcustom_time_zone(mst, hours(-7), of2, rule4));

  check("out string", 
        tz1->dst_zone_abbrev() == std::wstring(L"PDT"));
  check("out string", 
        tz1->std_zone_abbrev() == std::wstring(L"PST"));
  check("out string", 
        tz1->std_zone_name() == std::wstring(L"Pacific Standard Time"));
  check("out string", 
        tz1->dst_zone_name() == std::wstring(L"Pacific Daylight Time"));

  check("dst offset", tz1->dst_offset() == hours(1));
  check("base offset", tz1->base_utc_offset() == hours(-8));
  check("has dst", tz1->has_dst());

  check("dst start time", 
        tz1->dst_local_start_time(2003) == ptime(date(2003,Apr,30),hours(2)));
  check("dst end time", 
        tz1->dst_local_end_time(2003) == ptime(date(2003,Oct,30),hours(2)));

  check("tz1 to posix string", 
       tz1->to_posix_string() == std::wstring(L"PST-08PDT+01,120/02:00,303/02:00"));
  check("tz2 to posix string", 
       tz2->to_posix_string() == std::wstring(L"PST-08PDT+01,M4.1.0/02:00,M10.5.0/02:00"));
  check("tz3 to posix string", 
        tz3->to_posix_string() == std::wstring(L"PST-08PDT+01,M3.5.0/02:00,M10.5.0/02:00"));
  check("tz4 to posix string", 
        tz4->to_posix_string() == std::wstring(L"MST-07"));

  // test start/end for non-dst zone
  check("has dst in non-dst zone", !tz4->has_dst());
  check("dst start in non-dst zone", 
        tz4->dst_local_start_time(2005) == ptime(not_a_date_time));
  check("dst end in non-dst zone",
        tz4->dst_local_end_time(2005) == ptime(not_a_date_time));


  return printTestStats();
}


