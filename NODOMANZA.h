#pragma once
#include "Nodo.hpp"
namespace Serpientejuego
{
	public class NODOMANZA: public NODO
	{
		bool viva;
	public:
		NODOMANZA(int dire_x, int dire_y);
		bool getviva();
		void setviva(bool n);

	};
}
