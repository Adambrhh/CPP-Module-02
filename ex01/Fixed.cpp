/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:07 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/20 10:32:27 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : fixedComma(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const src)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedComma = src << fractionalBits;;
}

Fixed::Fixed(float const src)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedComma = roundf(src * (1 << fractionalBits));
}

Fixed& Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixedComma = src.getRawBits();
	return (*this);
}

int	Fixed::toInt() const
{
	return (this->fixedComma >> fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float)this->fixedComma / (1 << fractionalBits));
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
