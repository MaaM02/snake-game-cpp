#pragma once

namespace Serpientejuego
{
	public class NODO
	{
	public:
		int x;
		int y;
		NODO* siguiente; 
		NODO* anterior; 

		NODO(int xx, int yy)
		{
			x = xx;
			y = yy;
			siguiente = nullptr;
			anterior = nullptr;
		}

		void Dibujar(System::Drawing::BufferedGraphics^ g, System::Drawing::Bitmap^ figura)
		{
			System::Drawing::Rectangle recorte = System::Drawing::Rectangle(0, 0, 50, 50);
			System::Drawing::Rectangle contenedor = System::Drawing::Rectangle(x, y, 50, 50);
			g->Graphics->DrawImage(figura, contenedor, recorte, System::Drawing::GraphicsUnit::Pixel);
		}
	};
}
