#include "competetive_programming.h"

using namespace generic_programming; 
using namespace std;
/*Macros only accesible through this file */
#define upper_mask 0xFF000000
#define lower_mask 0x000000FF 
#define mid_1mask  0x00FF0000
#define mid_2mask  0x0000FF00

void memory_operations ::mem_copy(const void* source, void* destination, int size)
{
	/*convert the void pointers to a pointer of type char*/
	uint8_t *src = (uint8_t*)source;  
	uint8_t* dest = (uint8_t*)destination;
	for (int i = 0; i < size; i++)
	{
		dest[i] = src[i]; 
	}
	
}

void memory_operations::mem_copy_overlapprot(const void* source,  void* destination, int size)
{
	vector<uint8_t>temporary_buffer; 
	uint8_t* src = (uint8_t*)source;
	uint8_t* dest = (uint8_t*)destination;
	/*To avoid source and destination adress overlap use a temporary buffer*/
	for (int i = 0; i < size; i++)
	{
		temporary_buffer.push_back(src[i]);
	}
	for (int i = 0; i < temporary_buffer.size(); i++)
	{
		dest[i] = temporary_buffer[i];
	}

}
void memory_operations::mem_move(const void* source, void* destination, int size)
{
	vector<uint8_t>temporary_buffer;
	uint8_t* src = (uint8_t*)source;
	uint8_t* dest = (uint8_t*)destination;
	/*To avoid source and destination adress overlap use a temporary buffer*/
	for (int i = 0; i < size; i++)
	{
		temporary_buffer.push_back(src[i]);
	}
	for (int i = 0; i < temporary_buffer.size(); i++)
	{
		dest[i] = temporary_buffer[i];
	}
	
}

endian endianness_control::check_endianness()
{
	uint32_t temp = 0x01;
	uint32_t* ptr = &temp;
	endian temp_var;
	if (*(uint8_t*)ptr == 0x01)
	{
		std::cout << "little endian" << std::endl;
		temp_var = little_endian;
	}
	else
	{
		std::cout << "big endian" << std::endl;
		temp_var = big_endian;
	}
	return(temp_var);
}

uint32_t endianness_control::endian_specificcode_little_big(uint32_t variable )
{
	uint32_t temp = variable;
	temp = ((variable & upper_mask >> 24) | (variable & lower_mask << 24) | (variable & mid_1mask >> 8) | (variable & mid_1mask << 8));
	return(temp);
}

double data_type_converisions::fixed_to_float(double number, uint8_t value_after_point)
{
	
}

double data_type_converisions::float_to_fixed(double number,uint8_t value_after_point)
{
	/*Algorithm in short*/
	/*A fixed point number contains 24 bit value before point and fractional value after the point(.).  */
	/*example 24.666666 (6 values afer the point)*/
	/*step 1 : Find out number of digis after the point */
	/*step 2 : round the floating point number and muliply the number with 2^numberafter the point*/
	return(round(number * (1 << value_after_point)));

}

char * data_type_converisions::dec_to_bin(uint32_t number)
{
	char temp_buffer[sizeof(uint32_t)];
	int i = 0; 
	while (number > 0)
	{
		temp_buffer[i] = (number % 2); 
		number = number / 2; 
		i++; 
	}
	return (temp_buffer); 

}

char* data_type_converisions::dec_to_hex(uint32_t number)
{
	char temp_buffer[sizeof(number)],temp; 
	int i = 0; 
	while (number > 0)
	{
		temp = number % 16;
		if (temp <= 9)
		{
			temp_buffer[i] = 48 + temp; 
			i++;
		}
		else
		{
			temp_buffer[i] = 55 + temp;
			i++;
		}
		number = number / 16; 
	}
	return(temp_buffer);

}