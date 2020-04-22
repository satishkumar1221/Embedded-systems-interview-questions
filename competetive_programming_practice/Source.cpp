#include <iostream> 

//implement memory manager
bool overlap_detection;

int overlap_p(void* a, void* b, size_t n)
{
	char* x = (char *)a;
	char *y = (char *)b;
	
}

void myownmemorycopy(void* source, void* dest, uint32_t size)
{
	char* src = (char*)source;
	char* dst = (char*)dest; 
	for (int i = 0; i < size / (sizeof(int)); i++)
	{
		src[i] = dst[i]; 
		i++;
	}
}

void myownmemorycopy_overlapprotection(void* source, void* dest,uint32_t sizet)
{
	char* src = (char*)source;
	char* dst = (char*)dest;
	char temp_buffer[100];
	int itr=0;
	/*Source is copied to the temporary buffer*/
	for (itr = 0; itr < (sizeof(sizet) / sizeof(int));itr++)
	{
		temp_buffer[itr] = src[itr]; 
		/*Check for the overlap protection */
		
	}
	/*Avoid overlap by using a temporary buffer*/
	while (itr < (sizeof(size_t) / sizeof(int)))
	{
		dst[itr] = temp_buffer[itr];
	}
}

void my_own_memory_allocator()
{

}

