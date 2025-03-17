/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:49/18 by kfreyer           #+#    #+#             */
/*   Updated: 2025/02/17 08:49:18 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 1 ) {
        std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < argc; i++) {
			// creates a std::string object =str= and initializes it with the C-style string argv[i].
			// The std::string constructor is used to handle the conversion from a C-style string to a C++ string
            std::string str = argv[i]; //
            for (size_t j = 0; j < str.length(); j++)
			    // https://en.cppreference.com/w/cpp/string/byte/toupper
			    // std::toupper expects an argument that fits the unsigned char range.
			    // undefined if the argument's value is neither representable as unsigned char nor equal to EOF
			    // the return type of std::toupper is int, therefore another cast
			    // To use these functions safely with plain chars (or signed chars), the argument should first be converted to unsigned char
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
        }
    }
    std::cout << std::endl;
    return 0;
}
