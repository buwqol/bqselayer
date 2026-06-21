#ifndef BQSELAYER_SYMCONST_H
#define BQSELAYER_SYMCONST_H
#include "BQSE_CtxCrack.h"
#include "BQSE_PrimTypes.h"
const tChr *BQSE_GetCompiler(enum eCompiler comp);
#ifdef BQSE_IMPL
const tChr *BQSE_GetCompiler(enum eCompiler comp)
{
	switch (comp)
	{
	case eCompiler_MSC: return "Microsoft Visual C";
	case eCompiler_GNUC: return "GNU Compiler";
	case eCompiler_LLVM: return "Clang/LLVM";
	default: return "Unknown";
	}
}
#endif
const tChr *BQSE_GetOperatingSystem(enum eOperatingSystem os);
#ifdef BQSE_IMPL
const tChr *BQSE_GetOperatingSystem(enum eOperatingSystem os)
{
	switch (os)
	{
	case eOperatingSystem_Windows: return "Windows";
	case eOperatingSystem_Linux: return "Linux";
	case eOperatingSystem_MacOS: return "MacOS";
	case eOperatingSystem_FreeBSD: return "FreeBSD";
	case eOperatingSystem_MSDOS: return "MSDOS";
	case eOperatingSystem_Unix: return "Unix";
	default: return "Unknown";
	}
}
#endif
const tChr *BQSE_GetArchitecture(enum eArchitecture arch);
#ifdef BQSE_IMPL
const tChr *BQSE_GetArchitecture(enum eArchitecture arch)
{
	switch (arch)
	{
	case eArchitecture_AMD64: return "AMD64";
	case eArchitecture_Intel86: return "Intel86";
	case eArchitecture_Arm64: return "Arm64";
	case eArchitecture_Arm: return "Arm";
	default: return "Unknown";
	}
}
#endif
enum eMonth
{
	eMonth_Jan,
	eMonth_Feb,
	eMonth_Mar,
	eMonth_Apr,
	eMonth_May,
	eMonth_Jun,
	eMonth_Jul,
	eMonth_Aug,
	eMonth_Sep,
	eMonth_Oct,
	eMonth_Nov,
	eMonth_Dec
};
const tChr *BQSE_GetMonth(enum eMonth mon);
const tChr *BQSE_GetMonthFull(enum eMonth mon);
#ifdef BQSE_IMPL
const tChr *BQSE_GetMonth(enum eMonth mon)
{
	switch (mon)
	{
	case eMonth_Jan: return "Jan";
	case eMonth_Feb: return "Feb";
	case eMonth_Mar: return "Mar";
	case eMonth_Apr: return "Apr";
	case eMonth_May: return "May";
	case eMonth_Jun: return "Jun";
	case eMonth_Jul: return "Jul";
	case eMonth_Aug: return "Aug";
	case eMonth_Sep: return "Sep";
	case eMonth_Oct: return "Oct";
	case eMonth_Nov: return "Nov";
	case eMonth_Dec: return "Dec";
	default: return "Unknown";
	}
}
const tChr *BQSE_GetMonthFull(enum eMonth mon)
{
	switch (mon)
	{
	case eMonth_Jan: return "January";
	case eMonth_Feb: return "February";
	case eMonth_Mar: return "March";
	case eMonth_Apr: return "April";
	case eMonth_May: return "May";
	case eMonth_Jun: return "June";
	case eMonth_Jul: return "July";
	case eMonth_Aug: return "August";
	case eMonth_Sep: return "September";
	case eMonth_Oct: return "October";
	case eMonth_Nov: return "November";
	case eMonth_Dec: return "December";
	default: return "Unknown";
	}
}
#endif
enum eDay
{
	eDay_Sun,
	eDay_Mon,
	eDay_Tue,
	eDay_Wed,
	eDay_Thu,
	eDay_Fri,
	eDay_Sat
};
const tChr *BQSE_GetDay(enum eDay day);
const tChr *BQSE_GetDayFull(enum eDay day);
#ifdef BQSE_IMPL
const tChr *BQSE_GetDay(enum eDay day)
{
	switch (day)
	{
	case eDay_Sun: return "Sun";
	case eDay_Mon: return "Mon";
	case eDay_Tue: return "Tue";
	case eDay_Wed: return "Wed";
	case eDay_Thu: return "Thu";
	case eDay_Fri: return "Fri";
	case eDay_Sat: return "Sat";
	default: return "Unknown";
	}
}
const tChr *BQSE_GetDayFull(enum eDay day)
{
	switch (day)
	{
	case eDay_Sun: return "Sunday";
	case eDay_Mon: return "Monday";
	case eDay_Tue: return "Tuesday";
	case eDay_Wed: return "Wednesday";
	case eDay_Thu: return "Thursday";
	case eDay_Fri: return "Friday";
	case eDay_Sat: return "Saturday";
	default: return "Unknown";
	}
}
#endif
#endif/*BQSELAYER_SYMCONST_H*/