#ifndef _LOCALE_IMPL_H
#define _LOCALE_IMPL_H

#include <locale.h>
#include <stdlib.h>
#include "libc.h"
#include "pthread_impl.h"

#define LOCALE_NAME_MAX 23

struct __locale_map {
	const void *map;
	size_t map_size;
	char name[LOCALE_NAME_MAX+1];
	const struct __locale_map *next;
};

extern hidden volatile int __locale_lock[1];

extern hidden const struct __locale_map __c_dot_utf8;
extern hidden const struct __locale_struct __c_locale;
extern hidden const struct __locale_struct __c_dot_utf8_locale;

hidden const struct __locale_map *__get_locale(int, const char *);
hidden const char *__mo_lookup(const void *, size_t, const char *);
hidden const char *__lctrans(const char *, const struct __locale_map *);
hidden const char *__lctrans_failsafe(const char * msg, const char * failsafe, const struct __locale_map *);
hidden int __lcint_failsafe(const char* msg, int failsafe, const struct __locale_map *lm);
hidden const char *__lctrans_cur(const char *);
hidden const char *__lctrans_impl(const char *, const struct __locale_map *);
hidden int __loc_is_allocated(locale_t);
hidden char *__gettextdomain(void);

#define LOC_MAP_FAILED ((const struct __locale_map *)-1)

#define LCTRANS_FAILSAFE(msg, failsafe, lc, loc) __lctrans_failsafe(msg, failsafe, (loc)->cat[(lc)])
#define LCINT_FAILSAFE(msg, failsafe, lc, loc) __lcint_failsafe(msg, failsafe, (loc)->cat[(lc)])
#define LCTRANS(msg, lc, loc) __lctrans(msg, (loc)->cat[(lc)])
#define LCTRANS_CUR(msg) __lctrans_cur(msg)

#define C_LOCALE ((locale_t)&__c_locale)
#define UTF8_LOCALE ((locale_t)&__c_dot_utf8_locale)

#define CURRENT_LOCALE (__pthread_self()->locale)

#define CURRENT_UTF8 (!!__pthread_self()->locale->cat[LC_CTYPE])

#undef MB_CUR_MAX
#define MB_CUR_MAX (CURRENT_UTF8 ? 4 : 1)

#endif
