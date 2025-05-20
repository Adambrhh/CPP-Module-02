/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:15 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/20 14:01:52 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixedComma;
	static const int	fractionalBits = 8;
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(int const src);
	Fixed(float const src);
// opérateur de comparaison
	bool	operator>(Fixed const &src) const;
	bool	operator<(Fixed const &src) const;
	bool	operator>=(Fixed const &src) const;
	bool	operator<=(Fixed const &src) const;
	bool	operator==(Fixed const &src) const;
	bool	operator!=(Fixed const &src) const;
	Fixed&	operator=(Fixed const & src);
// opérateurs de arithmétiques
	Fixed	operator+(Fixed const & src) const;
	Fixed	operator-(Fixed const & src) const;
	Fixed	operator*(Fixed const & src) const;
	Fixed	operator/(Fixed const & src) const;
// opérateurs d'incrémentation et de décrémentation
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	~Fixed();
	int				toInt() const;
	float			toFloat() const;
// min & max
	Fixed&			min(Fixed& a, Fixed& b);
	Fixed const&	min(Fixed const & a, Fixed const & b);
	Fixed&			max(Fixed& a, Fixed& b);
	Fixed const&	max(Fixed const & a, Fixed const & b);
	int				getRawBits() const;
	void			setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, Fixed const &value);

#endif