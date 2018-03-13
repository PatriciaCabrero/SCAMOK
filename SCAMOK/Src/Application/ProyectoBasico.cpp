#include <stdio.h>
#include "Juego.h"

#ifdef _DEBUG || !_WIN32
int main(){
#else
#include <Windows.h>
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
	){
#endif

	Juego* game = new Juego();
	game->run();
	return 0;
}