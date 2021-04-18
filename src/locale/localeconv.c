#include <locale.h>
#include <limits.h>
#include <langinfo.h>
#include "locale_impl.h"

static const struct lconv posix_lconv = {
	.decimal_point = ".",
	.thousands_sep = "",
	.grouping = "",
	.int_curr_symbol = "",
	.currency_symbol = "",
	.mon_decimal_point = "",
	.mon_thousands_sep = "",
	.mon_grouping = "",
	.positive_sign = "",
	.negative_sign = "",
	.int_frac_digits = CHAR_MAX,
	.frac_digits = CHAR_MAX,
	.p_cs_precedes = CHAR_MAX,
	.p_sep_by_space = CHAR_MAX,
	.n_cs_precedes = CHAR_MAX,
	.n_sep_by_space = CHAR_MAX,
	.p_sign_posn = CHAR_MAX,
	.n_sign_posn = CHAR_MAX,
	.int_p_cs_precedes = CHAR_MAX,
	.int_p_sep_by_space = CHAR_MAX,
	.int_n_cs_precedes = CHAR_MAX,
	.int_n_sep_by_space = CHAR_MAX,
	.int_p_sign_posn = CHAR_MAX,
	.int_n_sign_posn = CHAR_MAX,
};

struct lconv *localeconv(void)
{
	const struct lconv current_lconv = {
		.decimal_point = LCTRANS_FAILSAFE("decimal_point", ".", LC_NUMERIC, CURRENT_LOCALE),
		.thousands_sep = LCTRANS_FAILSAFE("thousands_sep", ".", LC_NUMERIC, CURRENT_LOCALE),
		.grouping = LCTRANS_FAILSAFE("grouping", ".", LC_NUMERIC, CURRENT_LOCALE),
		.int_curr_symbol = LCTRANS_FAILSAFE("int_curr_symbol", ".", LC_MONETARY, CURRENT_LOCALE),
		.currency_symbol = LCTRANS_FAILSAFE("currency_symbol", ".", LC_MONETARY, CURRENT_LOCALE),
		.mon_decimal_point = LCTRANS_FAILSAFE("mon_decimal_point", ".", LC_MONETARY, CURRENT_LOCALE),
		.mon_thousands_sep = LCTRANS_FAILSAFE("mon_thousands_sep", ".", LC_MONETARY, CURRENT_LOCALE),
		.mon_grouping = LCTRANS_FAILSAFE("mon_grouping", ".", LC_MONETARY, CURRENT_LOCALE),
		.positive_sign = LCTRANS_FAILSAFE("positive_sign", ".", LC_MONETARY, CURRENT_LOCALE),
		.negative_sign = LCTRANS_FAILSAFE("negative_sign", ".", LC_MONETARY, CURRENT_LOCALE),
		.int_frac_digits = LCTRANS_FAILSAFE("int_frac_digits", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.frac_digits = LCTRANS_FAILSAFE("frac_digits", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.p_cs_precedes = LCTRANS_FAILSAFE("p_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.p_sep_by_space = LCTRANS_FAILSAFE("p_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.n_cs_precedes = LCTRANS_FAILSAFE("n_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.n_sep_by_space = LCTRANS_FAILSAFE("n_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.p_sign_posn = LCTRANS_FAILSAFE("p_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.n_sign_posn = LCTRANS_FAILSAFE("n_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.int_p_cs_precedes = LCTRANS_FAILSAFE("int_p_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.int_p_sep_by_space = LCTRANS_FAILSAFE("int_p_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.int_n_cs_precedes = LCTRANS_FAILSAFE("int_n_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.int_n_sep_by_space = LCTRANS_FAILSAFE("int_n_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.int_p_sign_posn = LCTRANS_FAILSAFE("int_p_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
		.int_n_sign_posn = LCTRANS_FAILSAFE("int_n_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE),
	};

	return (void *)&current_lconv;
}
