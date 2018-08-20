/**
	bool array template
*/

//class version

#ifndef _GLIBCXX_CSRTING
#include <cstring>
#endif

class bool_array
{
public:

	typedef unsigned int bool_array_size_t;
	typedef unsigned int bool_array_data_t;

	static const int DEFAULT_SIZE = 16 * sizeof(int);

	/*
	class bool_array_operator
	{
		bool_array *obj;
		unsigned index,offset;
		
		public:

		bool_array_operator(bool_array *obj,unsigned index)
		{
			bool_array_operator(obj,index / sizeof(unsigned),index % sizeof(unsigned));
		}

		bool_array_operator(bool_array *obj,unsigned index,unsigned offset)
		{
			this->index = index;
			this->offset = offset;
			this->obj = obj;
		}

	};
	*/

private:

	bool_array_data_t *data;
	bool_array_size_t data_size;

public:

	bool_array(bool_array_size_t n = DEFAULT_SIZE)
	{
		data_size = (n + sizeof(unsigned) - 1) / sizeof(unsigned);
		data = new unsigned[data_size];
		std::memset(data,0,sizeof(data));
	}

	bool_array(bool arr[],bool_array_size_t n)
	{
		data_size = (n + sizeof(unsigned) - 1) / sizeof(unsigned);
		data = new unsigned[data_size];
		std::memset(data,0,sizeof(data));
		for(int i = 0;i < n;++i)
			data[i / sizeof(unsigned)] |= 1 << (i % sizeof(unsigned));
	}

	~bool_array()
	{
		delete[] data;
	}

	bool operator[](bool_array_size_t index)
	{
		return data[index / sizeof(unsigned)] & (1 << (index % sizeof(unsigned)));
	}

	bool_array_operator operator[](int index)
	{
		return bool_array_operator(this,index);
	}

	int size()
	{
		return data_size * sizeof(unsigned);
	}

};

int main()
{
	return 0;
}
