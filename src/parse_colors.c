/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:58:55 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 20:17:12 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Helper function to skip whitespace and determine the sign
static void skipWhitespaceAndSign(const char **str, bool *negative) {
    while (**str && ft_isspace(**str)) {
        (*str)++;
    }

    if (**str == '-') {
        *negative = true;
        (*str)++;
    } else if (**str == '+') {
        (*str)++;
    }
}

// Helper function to determine the base
static int determineBase(const char **str, int base) {
    if (base == 0) {
        if (**str == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X')) {
            base = 16;
            (*str) += 2;
        } else if (**str == '0') {
            base = 8;
        } else {
            base = 10;
        }
    } else if (base == 16) {
        // If base is explicitly set to 16, we accept it as a hexadecimal input
        (*str) += 2; // Skip "0x" or "0X" prefix if present
    }
    return base;
}

// Helper function to parse the string and calculate the result
static long parseAndCalculate(const char **str, int base) {
    long result = 0;

    while (**str) {
        char digit = *(*str);

        if (ft_isdigit(digit)) {
            digit -= '0';
        } else if (ft_isalpha(digit)) {
            digit = ft_tolower(digit) - 'a' + 10;
        } else {
            break;  // Invalid character
        }

        if (digit >= base) {
            break;  // Invalid digit for the specified base
        }

        result = result * base + digit;
        (*str)++;
    }

    return result;
}

// Main custom_strtol function
long custom_strtol(const char *str, char **endptr, int base) {
    // Skip leading whitespace and determine the sign
    bool negative = false;
    skipWhitespaceAndSign(&str, &negative);

    // Determine the base
    base = determineBase(&str, base);

    // Parse and calculate the result
    long result = parseAndCalculate(&str, base);

    // Set endptr if provided
    if (endptr != NULL) {
        *endptr = (char *)str;
    }

    // Apply sign
    if (negative) {
        result = -result;
    }

    return result;
}
