#include <X11/Xlib.h>
#include <cstdio>
#include <iostream>

int main()
{
	Display *d = XOpenDisplay(NULL);
	if (d == NULL)
	{
		printf("Unable to open display\n");
		return -1;
	}
	std::cout << "Hello World\n";
	return 0;
}