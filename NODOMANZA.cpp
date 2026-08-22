#include "NODOMANZA.h"

namespace Serpientejuego
{
	NODOMANZA::NODOMANZA(int dire_x, int dire_y):NODO(dire_x, dire_y)
	{
		this->viva = true;
	}

	bool NODOMANZA::getviva()
	{
		return viva;
	}

	void NODOMANZA::setviva(bool n)
	{
		this->viva = n;
	}
}

