/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:07 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/19 16:57:51 by abarahho         ###   ########.fr       */
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

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedComma = src.fixedComma;
}

Fixed& Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixedComma = src.fixedComma;
	return (*this);
}

int	Fixed::getRawBits() const
{
	
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedComma);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedComma = raw;
}

// Default constructor called
// Copy constructor called
// Destructor called
// getRawBits member function called