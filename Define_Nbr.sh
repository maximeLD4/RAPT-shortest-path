#!/bin/bash

rm   ./Headers/Define_Nbr.h
echo "#ifndef DEFINE_NBR_H">>./Headers/Define_Nbr.h
echo "#define DEFINE_NBR_H">>./Headers/Define_Nbr.h
echo "#define NBR_ROUTES $(($((wc -l ./Gtfstxt/routes.txt)| cut -f1 -d' ')))">>./Headers/Define_Nbr.h
echo "#define NBR_CALENDAR $((wc -l ./Gtfstxt/calendar.txt)| cut -f1 -d' ')">>./Headers/Define_Nbr.h
echo "#define NBR_CALENDAR_DATE $((wc -l ./Gtfstxt/calendar_dates.txt)| cut -f1 -d' ')">>./Headers/Define_Nbr.h
echo "#define NBR_STOP_TIMES $((wc -l ./Gtfstxt/stop_times.txt)| cut -f1 -d' ')">>./Headers/Define_Nbr.h
echo "#define NBR_STOPS $((wc -l ./Gtfstxt/stops.txt)| cut -f1 -d' ')">>./Headers/Define_Nbr.h
echo "#define NBR_TRANSFERS $((wc -l ./Gtfstxt/transfers.txt)| cut -f1 -d' ')">>./Headers/Define_Nbr.h
echo "#define NBR_TRIPS $((wc -l ./Gtfstxt/trips.txt)| cut -f1 -d' ')">>./Headers/Define_Nbr.h
echo "#endif">>./Headers/Define_Nbr.h
