#include <locale.h>
#include <limits.h>
#include <langinfo.h>
#include "locale_impl.h"

struct lconv *localeconv(void)
{
	struct lconv *current_lconv;
	current_lconv = malloc(sizeof(struct lconv));

	current_lconv->decimal_point = (char*)LCTRANS_FAILSAFE("decimal_point", ".", LC_NUMERIC, CURRENT_LOCALE);
	current_lconv->thousands_sep = (char*)LCTRANS_FAILSAFE("thousands_sep", "", LC_NUMERIC, CURRENT_LOCALE);
	current_lconv->grouping = (char*)LCTRANS_FAILSAFE("grouping", "", LC_NUMERIC, CURRENT_LOCALE);
	current_lconv->int_curr_symbol = (char*)LCTRANS_FAILSAFE("int_curr_symbol", "", LC_MONETARY, CURRENT_LOCALE);
	current_lconv->currency_symbol = (char*)LCTRANS_FAILSAFE("currency_symbol", "", LC_MONETARY, CURRENT_LOCALE);
	current_lconv->mon_decimal_point = (char*)LCTRANS_FAILSAFE("mon_decimal_point", "", LC_MONETARY, CURRENT_LOCALE);
	current_lconv->mon_thousands_sep = (char*)LCTRANS_FAILSAFE("mon_thousands_sep", "", LC_MONETARY, CURRENT_LOCALE);
	current_lconv->mon_grouping = (char*)LCTRANS_FAILSAFE("mon_grouping", "", LC_MONETARY, CURRENT_LOCALE);
	current_lconv->positive_sign = (char*)LCTRANS_FAILSAFE("positive_sign", "", LC_MONETARY, CURRENT_LOCALE);
	current_lconv->negative_sign = (char*)LCTRANS_FAILSAFE("negative_sign", "", LC_MONETARY, CURRENT_LOCALE);
	current_lconv->int_frac_digits = LCINT_FAILSAFE("int_frac_digits", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->frac_digits = LCINT_FAILSAFE("frac_digits", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->p_cs_precedes = LCINT_FAILSAFE("p_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->p_sep_by_space = LCINT_FAILSAFE("p_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->n_cs_precedes = LCINT_FAILSAFE("n_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->n_sep_by_space = LCINT_FAILSAFE("n_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->p_sign_posn = LCINT_FAILSAFE("p_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->n_sign_posn = LCINT_FAILSAFE("n_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->int_p_cs_precedes = LCINT_FAILSAFE("int_p_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->int_p_sep_by_space = LCINT_FAILSAFE("int_p_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->int_n_cs_precedes = LCINT_FAILSAFE("int_n_cs_precedes", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->int_n_sep_by_space = LCINT_FAILSAFE("int_n_sep_by_space", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->int_p_sign_posn = LCINT_FAILSAFE("int_p_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);
	current_lconv->int_n_sign_posn = LCINT_FAILSAFE("int_n_sign_posn", CHAR_MAX, LC_MONETARY, CURRENT_LOCALE);

	return (void *)current_lconv;
}
