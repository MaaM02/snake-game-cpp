#pragma once
#include "Serpiente.h"
namespace Serpientejuego
{

	SERPIENTE::SERPIENTE()
	{
		cabeza = new NODO(150, 175); 
		cabeza->siguiente = new NODO(200, 175);
		cabeza->siguiente->anterior = cabeza;
		cabeza->siguiente->siguiente = new NODO(250, 175); 
		cabeza->siguiente->siguiente->anterior = cabeza->siguiente;
		perder = false; 
	}

	int SERPIENTE::getposicion_x()
	{
		return cabeza->x;
	}

	int SERPIENTE::getposicion_y()
	{
		int posi = 0;
		posi = cabeza->y;
		return posi;
	}

	bool SERPIENTE::getperder()
	{
		return perder;
	}

	void SERPIENTE::setperder(bool n)
	{
		perder = n;

		if (perder == true)
		{
			Eliminar();
		}
	}

	bool SERPIENTE::comer(int x, int y)
	{
		return cabeza->x == x && cabeza->y == y; 
	}

	void SERPIENTE::EliminarCompletamente(NODO* A)
	{
		if (A != nullptr)
		{
			EliminarCompletamente(A->siguiente);
			delete A;
		}
	}

	void SERPIENTE::Eliminar()
	{
		NODO* aux = cabeza->siguiente->siguiente->siguiente;
		cabeza->siguiente->siguiente->siguiente = nullptr;

		if (aux != nullptr)
		{
			EliminarCompletamente(aux->siguiente);
			delete aux; 
		}
	}

	void SERPIENTE::actualizarpos(NODO* A, int dire_x, int dire_y)
	{
		perder = false; 

		if (A != nullptr)
		{
			actualizarpos(A->siguiente, A->x, A->y);
			A->x = dire_x;
			A->y = dire_y; 
		}
	}

	int SERPIENTE::puntos()
	{
		NODO* aux = cabeza;
		int puntos = 0;

		while (aux != nullptr)
		{
			puntos++; 
			aux = aux->siguiente;
		}
		return (puntos-3) *100; 
	}

	void SERPIENTE::Mover(int dire_x, int dire_y, bool v)
	{
		NODO* aux = cabeza;
		bool centinela = true;

		while (aux != nullptr && !v)
		{
			if (aux->siguiente == nullptr)
			{
				aux->siguiente = new NODO(-50, -50);
				aux->siguiente->anterior = aux;
				aux = nullptr;
			}
			
			if (aux != nullptr)
			{
				aux = aux->siguiente;
			}
		}

		aux = cabeza; 

		while (centinela && aux != nullptr)
		{
			if (dire_x == aux->x && dire_y == aux->y)
			{
				centinela = false;
			}
			aux = aux->siguiente; 
		}

		if (centinela)
		{
			perder = false;
			actualizarpos(cabeza->siguiente, cabeza->x, cabeza->y);
			cabeza->x = dire_x;
			cabeza->y = dire_y; 
		}
		else
		{
			setperder(true);
		}

	}

	void SERPIENTE::Dibujar(System::Drawing::BufferedGraphics^ g, System::Drawing::Bitmap^ figura, System::Drawing::Bitmap^ rojo, System::Drawing::Bitmap^ n1, System::Drawing::Bitmap^ n2, System::Drawing::Bitmap^ n3, System::Drawing::Bitmap^ n4)
	{
		NODO* aux = cabeza->siguiente;

		if (perder == true)
		{
			cabeza->Dibujar(g, rojo);
		}
		else
		{
			cabeza->Dibujar(g, figura);
		}

		while (aux != nullptr)
		{
			if (aux->siguiente != nullptr && aux->anterior != nullptr)
			{
				// n4: Esquina Abajo - Derecha (Down - Right)
				if ((aux->siguiente->x == aux->x && aux->siguiente->y == aux->y + 50 && aux->anterior->x == aux->x + 50 && aux->anterior->y == aux->y) ||
					(aux->anterior->x == aux->x && aux->anterior->y == aux->y + 50 && aux->siguiente->x == aux->x + 50 && aux->siguiente->y == aux->y))
				{
					aux->Dibujar(g, n4);
				}
				else
				{
					// n1: Esquina Abajo - Izquierda (Down - Left)
					if ((aux->siguiente->x == aux->x && aux->siguiente->y == aux->y + 50 && aux->anterior->x == aux->x - 50 && aux->anterior->y == aux->y) ||
						(aux->anterior->x == aux->x && aux->anterior->y == aux->y + 50 && aux->siguiente->x == aux->x - 50 && aux->siguiente->y == aux->y))
					{
						aux->Dibujar(g, n1);
					}
					else
					{
						// n2: Esquina Arriba - Izquierda (Up - Left) <-- AQUÍ ESTABA EL CAMBIO (y - 50)
						if ((aux->siguiente->x == aux->x && aux->siguiente->y == aux->y - 50 && aux->anterior->x == aux->x - 50 && aux->anterior->y == aux->y) ||
							(aux->anterior->x == aux->x && aux->anterior->y == aux->y - 50 && aux->siguiente->x == aux->x - 50 && aux->siguiente->y == aux->y))
						{
							aux->Dibujar(g, n2);
						}
						else
						{
							// n3: Esquina Arriba - Derecha (Up - Right)
							if ((aux->siguiente->x == aux->x && aux->siguiente->y == aux->y - 50 && aux->anterior->x == aux->x + 50 && aux->anterior->y == aux->y) ||
								(aux->anterior->x == aux->x && aux->anterior->y == aux->y - 50 && aux->siguiente->x == aux->x + 50 && aux->siguiente->y == aux->y))
							{
								aux->Dibujar(g, n3);
							}
							else
							{
								// Si no es ninguna esquina, dibuja el cuerpo normal
								aux->Dibujar(g, figura);
							}
						}
					}
				}
			}
			else
			{
				aux->Dibujar(g, figura);
			}

			aux = aux->siguiente;
		}
	}

	SERPIENTE::~SERPIENTE()
	{
		EliminarCompletamente(cabeza);
	}
}

