#pragma once

#include <X11/Xlib.h>
#include <cstdio>
#include <iostream>

#define KEY_ESCAPE     9
#define KEY_SPACEBAR  65
#define KEY_UP       111
#define KEY_RIGHT    114
#define KEY_DOWN     116
#define KEY_LEFT     113

class StartWindow
{
private:
	int 			x_;              // Posição x da janela em relação à janela pai ou à tela (se a janela pai for StartDefaultRootWindow)
	int 			y_;             	// Posição y da janela em relação à janela pai ou à tela (se a janela pai for StartDefaultRootWindow)
	unsigned int 	width_;      	// Largura da janela
	unsigned int 	height_;     	// Altura da janela
	unsigned int 	border_width_;	// Largura da borda da janela
	unsigned long 	border_;   		// Valor do pixel da cor da borda
	unsigned long 	background_; 	// Valor do pixel da cor de fundo da janela
public:
	Display* 		display;       	// Ponteiro para a estrutura Display que representa a conexão com o servidor X
	Window			window;
	StartWindow(int x, int y, unsigned int width, unsigned int height, unsigned int border_width, unsigned long border, unsigned long backgound);
	~StartWindow();
};

StartWindow::StartWindow(int x, int y, unsigned int width, unsigned int height, unsigned int border_width, unsigned long border, unsigned long backgound)
{
	display = XOpenDisplay(NULL);
	if (display == NULL)
	{
		fprintf(stderr, "Erro ao abrir o display\n");
		exit ;
	}
	this->x_ = x;
	this->y_ = x;
	this->width_ = width;
	this->height_ = height;
	this->border_width_ = border_width;
	this->border_ = border;
	this->background_ = backgound;
	window = XCreateSimpleWindow(display, DefaultRootWindow(display), x_, y_, width_, height_, border_width_,border_, background_);
}

StartWindow::~StartWindow()
{
}
