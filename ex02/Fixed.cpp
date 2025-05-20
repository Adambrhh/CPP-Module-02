/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:07 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/20 14:52:08 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : fixedComma(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::Fixed(int const src)
{
	this->fixedComma = src << fractionalBits;;
}

Fixed::Fixed(float const src)
{
	this->fixedComma = roundf(src * (1 << fractionalBits));
}

Fixed& Fixed::operator=(Fixed const &src)
{
	if (this != &src)
		this->fixedComma = src.getRawBits();
	return (*this);
}

// opérateur de comparaison

bool	Fixed::operator>(Fixed const &src) const
{
	return (this->fixedComma > src.fixedComma);
}

bool	Fixed::operator<(Fixed const &src) const
{
	return (this->fixedComma < src.fixedComma);
}

bool	Fixed::operator>=(Fixed const &src) const
{
	return (this->fixedComma >= src.fixedComma);
}

bool	Fixed::operator<=(Fixed const &src) const
{
	return (this->fixedComma <= src.fixedComma);
}

bool	Fixed::operator==(Fixed const &src) const
{
	return (this->fixedComma == src.fixedComma);
}

bool	Fixed::operator!=(Fixed const &src) const
{
	return (this->fixedComma != src.fixedComma);
}

// opérateurs de arithmétiques

Fixed	Fixed::operator+(Fixed const &src) const
{
	return(Fixed(this->fixedComma + src.getRawBits()));
}

Fixed	Fixed::operator-(Fixed const &src) const
{
	return(Fixed(this->fixedComma - src.getRawBits()));
}

Fixed	Fixed::operator*(Fixed const &src) const
{
	return(Fixed((this->fixedComma * src.getRawBits()) >> fractionalBits));
}

Fixed	Fixed::operator/(Fixed const &src) const
{
	if (src.getRawBits() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return (Fixed());
	}
	return(Fixed((this->fixedComma << fractionalBits) / src.getRawBits()));
}

// opérateurs d'incrémentation et de décrémentation

Fixed& Fixed::operator++()
{
	this->fixedComma += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp;
	
	temp = *this;
	this->fixedComma += 1;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->fixedComma -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp;

	temp = *this;
	this->fixedComma -= 1;
	return (temp);
}

// toValue

int	Fixed::toInt() const
{
	return (this->fixedComma >> fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float)this->fixedComma / (1 << fractionalBits));
}

// min & max

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const& Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const& Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	return (b);
}

int	Fixed::getRawBits() const
{
	return (this->fixedComma);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedComma = raw;
}

std::ostream& operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}
