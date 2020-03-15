#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt-Br");

	List list;
	list.Add("teste");
	list.Add("mais um");
	list.Add("mais dois");

	string obj = list.Remove(0);
}
