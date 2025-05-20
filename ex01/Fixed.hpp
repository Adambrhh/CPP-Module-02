/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:15 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/20 10:19:30 by abarahho         ###   ########.fr       */
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
	Fixed&	operator=(Fixed const & src); 	
	~Fixed();
	int		toInt() const;
	float	toFloat() const;
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, Fixed const &value);

#endif