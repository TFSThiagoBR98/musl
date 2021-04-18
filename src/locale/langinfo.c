#include <locale.h>
#include <langinfo.h>
#include "locale_impl.h"

static const char c_time[] =
	"Sun\0" "Mon\0" "Tue\0" "Wed\0" "Thu\0" "Fri\0" "Sat\0"
	"Sunday\0" "Monday\0" "Tuesday\0" "Wednesday\0"
	"Thursday\0" "Friday\0" "Saturday\0"
	"Jan\0" "Feb\0" "Mar\0" "Apr\0" "May\0" "Jun\0"
	"Jul\0" "Aug\0" "Sep\0" "Oct\0" "Nov\0" "Dec\0"
	"January\0"   "February\0" "March\0"    "April\0"
	"May\0"       "June\0"     "July\0"     "August\0"
	"September\0" "October\0"  "November\0" "December\0"
	"AM\0" "PM\0"
	"%a %b %e %T %Y\0"
	"%m/%d/%y\0"
	"%H:%M:%S\0"
	"%I:%M:%S %p\0"
	"\0"
	"\0"
	"%m/%d/%y\0"
	"0123456789\0"
	"%a %b %e %T %Y\0"
	"%H:%M:%S";

static const char c_messages[] = "^[yY]\0" "^[nN]\0" "yes\0" "no";
static const char c_numeric[] = ".\0" "";

static const char lc_time_map[] =
	"abday_1\0" "abday_2\0" "abday_3\0" "abday_4\0" "abday_5\0" "abday_6\0" "abday_7\0"
	"day_1\0" "day_2\0" "day_3\0" "day_4\0"
	"day_5\0" "day_6\0" "day_7\0"
	"abmon_1\0" "abmon_2\0" "abmon_3\0" "abmon_4\0" "abmon_5\0" "abmon_6\0"
	"abmon_7\0" "abmon_8\0" "abmon_9\0" "abmon_10\0" "abmon_11\0" "abmon_12\0"
	"mon_1\0"   "mon_2\0" "mon_3\0"    "mon_4\0"
	"mon_5\0"       "mon_6\0"     "mon_7\0"     "mon_8\0"
	"mon_9\0" "mon_10\0"  "mon_11\0" "mon_12\0"
	"am\0" "pm\0"
	"d_t_fmt\0"
	"d_fmt\0"
	"t_fmt\0"
	"t_fmt_ampm\0"
	"era\0"
	"era_year\0"
	"era_d_fmt\0"
	"alt_digits\0"
	"era_d_t_fmt\0"
	"era_t_fmt";

static const char lc_messages_map[] = "yesexpr\0" "noexpr\0" "yesstr\0" "nostr";
static const char lc_numeric_map[] = "decimal_point\0" "thousands_sep";

char *__nl_langinfo_l(nl_item item, locale_t loc)
{
	int cat = item >> 16;
	int idx = item & 65535;
	const char *str;
	const char *failsafe;

	if (item == CODESET) return loc->cat[LC_CTYPE] ? "UTF-8" : "ASCII";

	/* _NL_LOCALE_NAME extension */
	if (idx == 65535 && cat < LC_ALL)
		return loc->cat[cat] ? (char *)loc->cat[cat]->name : "C";
	
	switch (cat) {
	case LC_NUMERIC:
		if (idx > 1) return "";
		str = lc_numeric_map;
		failsafe = c_numeric;
		break;
	case LC_TIME:
		if (idx > 0x31) return "";
		str = lc_time_map;
		failsafe = c_time;
		break;
	case LC_MONETARY:
		if (idx > 0) return "";
		str = "";
		break;
	case LC_MESSAGES:
		if (idx > 3) return "";
		str = lc_messages_map;
		failsafe = c_messages;
		break;
	default:
		return "";
	}

	for (; idx; idx--, str++) for (; *str; str++);
	for (; idx; idx--, failsafe++) for (; *failsafe; failsafe++);

	if (*failsafe) failsafe = LCTRANS_FAILSAFE(str, failsafe, cat, loc);
	return (char *)failsafe;
}

char *__nl_langinfo(nl_item item)
{
	return __nl_langinfo_l(item, CURRENT_LOCALE);
}

weak_alias(__nl_langinfo, nl_langinfo);
weak_alias(__nl_langinfo_l, nl_langinfo_l);
