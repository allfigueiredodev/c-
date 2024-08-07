/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:06:27 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 18:06:28 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {

    public:
        Array<T>(void);
        Array<T>(unsigned int size);
        Array<T>(const Array<T>& Array);
        Array<T>& operator=(const Array<T>& rhs);
        ~Array(void);
        size_t size(void) const;
        T& getIndex(int index) const;
        void    fillArrIndex(T data, int index);
        const T& operator[](size_t index) const;
        void addBack(T data);
        T& operator[](size_t index);

    private:
        T*      _arr;
        size_t  _size;

};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Array<T>& data);

#include "Array.tpp"

#endif