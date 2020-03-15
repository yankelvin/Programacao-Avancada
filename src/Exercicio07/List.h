#pragma once
#include <string>

using namespace std;

class List
{
private:
	string arr[100];
	int Count;

public:
	List()
	{
		Count = 0;
	}

	void Add(string element)
	{
		if (Count == 100)
			Count = 0;

		arr[Count++] = element;
	}

	void Add(int index, string element)
	{
		if (Count == 100)
			Count = 0;

		arr[index] = element;
		Count++;
	}

	void Clear()
	{
		for (int i = 0; i < 100; i++)
		{
			arr[i] = "";
		}

		Count = 0;
	}

	bool Contains(string element)
	{
		for (int i = 0; i < 100; i++)
		{
			if (arr[i]._Equal(element))
				return true;
		}

		return false;
	}

	string Get(int index)
	{
		if (index > 0 && index < 100)
		{
			return arr[index];
		}
	}

	int IndexOf(string element)
	{
		for (int i = 0; i < 100; i++)
		{
			if (arr[i]._Equal(element))
				return i;
		}

		return -1;
	}

	bool IsEmpty()
	{
		return Count == 0;
	}

	string Remove(int index)
	{
		if (index < 0 || index >= Count)
		{
			return "";
		}

		string aux = arr[index];
		for (int i = index; i < Count - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		arr[Count - 1] = "";
		Count--;
		return aux;
	}

	int Size()
	{
		return Count;
	}
};

class List2
{
private:
	List arr[100];
	int Count;

public:
	List2()
	{
		Count = 0;
	}

	void Add(List element)
	{
		if (Count == 100)
			Count = 0;

		arr[Count++] = element;
	}

	void Add(int index, List element)
	{
		if (Count == 100)
			Count = 0;

		arr[index] = element;
		Count++;
	}

	void Clear()
	{
		for (int i = 0; i < 100; i++)
		{
			arr[i] = {};
		}

		Count = 0;
	}

	bool Contains(List element)
	{
		for (int i = 0; i < 100; i++)
		{
			if (arr[i]. element)
				return true;
		}

		return false;
	}

	List Get(int index)
	{
		if (index > 0 && index < 100)
		{
			return arr[index];
		}
	}

	int IndexOf(List element)
	{
		for (int i = 0; i < 100; i++)
		{
			if (arr[i] == element)
				return i;
		}

		return -1;
	}

	bool IsEmpty()
	{
		return Count == 0;
	}

	List Remove(int index)
	{
		if (index < 0 || index >= Count)
		{
			return ;
		}

		List aux = arr[index];
		for (int i = index; i < Count - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		arr[Count - 1] = "";
		Count--;
		return aux;
	}

	int Size()
	{
		return Count;
	}
};