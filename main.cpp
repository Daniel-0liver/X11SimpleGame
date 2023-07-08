#include "X11SimpleGame.hpp"

int main()
{
	StartWindow *s;
	XEvent	e;

	StartWindow(1, 1, 800, 600, 1, 0xffffff, 0x2e2066);
	XSelectInput(s->display, s->window, KeyPressMask);
	XMapWindow(s->display, s->window);
	while (true)
	{
		XNextEvent(s->display, &e);
		if (e.xkey.keycode == KEY_ESCAPE)
			break ;
		else
			std::cout << "Key Pressed : " << e.xkey.keycode << std::endl;
	}
	XCloseDisplay(s->display);
	return 0;
}