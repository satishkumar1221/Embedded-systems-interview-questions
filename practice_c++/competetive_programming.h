#pragma once

#include<iostream>
#include <stdint.h>
#include <vector>
#define numbersafterpoint(x) x
/*Each Register will have a different union*/
union thirtytwobit_register_access
{
	uint32_t access_wholeregister; 
	struct reg_access
	{
		/*Bitwise Access */
		uint32_t firstelement : 1; 
		uint32_t secondelement : 3; 
		uint32_t thirdelement : 5;
		uint32_t fourth_element : 16; // non writable access 
	};
	

};//Access 32 bit register
//This is how we aceess register in embedded systems
#define access_32_bit_register *(volatile(thirtytwobit_register_access *)0xFFFF0022) 
#define float_to_integer(x) 
//Macro to Access 32 bit register

namespace generic_programming
{
	typedef enum
	{
		little_endian,
		big_endian
	}endian;

	class memory_operations
	{
	public:
		memory_operations();
		void mem_copy(const void* source,  void* dest, int size);
		void mem_copy_overlapprot( const void* source,  void* dest, int size);
		void mem_move(const void* source,  void* dest, int size);
	};

	class endianness_control
	{
		public:
			endian check_endianness();
			uint32_t endian_specificcode_little_big(uint32_t pim); 

	};

	class data_type_converisions
	{
		public :
			double fixed_to_float(double number, uint8_t value_after_point);
			double float_to_fixed(double number, uint8_t value_after_point);
			//uint32_t float_to_int(); 
			char * dec_to_hex(uint32_t number);
			char * dec_to_bin(uint32_t number);
			//uint32_t 



	};

	class competetive_programming
	{
	public:
	
	};
};

namespace embedded
{
	using namespace generic_programming;
	class register_access_functions : public memory_operations , public endianness_control
	{
		public:
		void embedded();


	}
	



}; 


