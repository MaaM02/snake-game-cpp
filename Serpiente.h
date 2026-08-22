#pragma once
#include "Nodo.hpp"

namespace Serpientejuego
{
	public class SERPIENTE
	{
	
	private: 
		NODO* cabeza; 
		bool perder; 
	public: 
		SERPIENTE();
		~SERPIENTE();
	private:
		void actualizarpos(NODO* A, int dire_x, int dire_y);
	public:
		void Mover(int dire_x, int dire_y, bool v);
		int getposicion_x();
		int getposicion_y();
		void setperder(bool n);
		bool getperder();
		bool comer(int x, int y);
		void Eliminar();
		int puntos();
		void EliminarCompletamente(NODO* A);
		void Dibujar(System::Drawing::BufferedGraphics^ g, System::Drawing::Bitmap^ figura, System::Drawing::Bitmap^ rojo, System::Drawing::Bitmap^ n1, System::Drawing::Bitmap^ n2, System::Drawing::Bitmap^ n3, System::Drawing::Bitmap^ n4);

	};
}