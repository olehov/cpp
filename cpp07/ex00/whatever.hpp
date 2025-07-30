/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:25:24 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/29 12:37:24 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& v1, T& v2)
{
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

template <typename T>
const T& min(const T& v1, const T& v2)
{
	if (v1 < v2)
	{
		return v1;
	}
	else
		return v2;
}

template <typename T>
const T& max(const T& v1, const T& v2)
{
	if (v1 < v2)
	{
		return v2;
	}
	else
		return v1;
}

#endif  //!WHATEVER_HPP