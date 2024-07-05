/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:43:41 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 13:43:43 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include "Classes/Serializer/Serializer.hpp"
#include "Data.h"

void SubjectTest(Data* patient) {
	Data* patientCpy;
	uintptr_t serialized = Serializer::serialize(patient);
	patientCpy = Serializer::deserialize(serialized);
	println(CYAN << "Patient_cpy data: ");
	println(patientCpy->name);
	println(patientCpy->age);
	println(patientCpy->height);
	println(patientCpy->weight);
};

void MyOwnTest(Data* patient) {
	char dataBlob[sizeof(Data)];
	std::memcpy(dataBlob, patient, sizeof(Data));
	// println(GREEN << "Reinterpreting the name: " << reinterpret_cast<char *>(dataBlob));
	println(GREEN << "Reinterpreting the age: " << *reinterpret_cast<int *>(dataBlob + sizeof(std::string)));
	println(GREEN << "Reinterpreting the height: " << *reinterpret_cast<float *>(dataBlob + sizeof(std::string) + sizeof(int)));
	println(GREEN << "Reinterpreting the weight: " << *reinterpret_cast<double *>(dataBlob + sizeof(std::string) + sizeof(int) + sizeof(float)));
};

int main(void){
	Data patient = {"Joseph", 55, 1.77f, 80.8};
	println(ORANGE << "***SUBJECT TEST***");
	std::cout << std::endl;
	SubjectTest(&patient);
	std::cout << std::endl;
	println(ORANGE << "***MY OWN TESTS***");
	std::cout << std::endl;
	MyOwnTest(&patient);
}