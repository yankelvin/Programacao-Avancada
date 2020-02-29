#include <iostream>

using namespace std;


class List
{
private:
	int arr[10];
	int length;

public:
	List()
	{
		length = 0;
	}

	void Add(int element)
	{
		int size = sizeof(arr) / sizeof(arr[0]);
		if ((length + 1) >= size)
			Resize(size * 2);

		arr[length] = element;

		length++;
	}

	void Add(int index, int element)
	{
		int size = sizeof(arr) / sizeof(arr[0]);

		for (int i = length; i >= index; i--)
		{
			if (i == index)
			{
				arr[index] = element;
				length++;
				return;
			}
			else
			{
				if ((i + 1) >= size)
					Resize(size * 2);
				else
					arr[i + 1] = arr[i];
			}
		}
	}

	void Clear()
	{
		for (int i = 0; i < length; i++)
			arr[i] = NULL;

		length = 0;
	}

	bool Contains(int element)
	{
		for (int i = 0; i < length; i++)
			if (arr[i] == element)
				return true;

		return false;
	}

	int Get(int index)
	{
		return arr[index];
	}

	int IndexOf(int element)
	{
		for (int i = 0; i < length; i++)
			if (arr[i] == element)
				return i;

		return -1;
	}

	bool IsEmpty()
	{
		return length == 0 ? true : false;
	}

	int LastIndexOf(int element)
	{
		for (int i = length; i >= 0; i--)
			if (arr[i] == element)
				return i;

		return -1;
	}

	int Remove(int index)
	{
		for (int i = index; i < length; i++)
		{
			if (i == index)
			{
				int element = arr[i];
				arr[i] = NULL;
				length--;
				return element;
			}
			else
			{
				arr[i] = arr[i + 1];
			}
		}
	}

	int Size()
	{
		return length;
	}

	void Resize(int length)
	{}
};

int main()
{
	setlocale(LC_ALL, "pt-Br");

	cout << "Hello World!\n";

	List teste;
	teste.Add(5);
	teste.Add(2);
}
