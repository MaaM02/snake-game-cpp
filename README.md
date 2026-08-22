# 🐍 Juego de la Serpiente (Snake Game in C++ / CLI)

Juego clásico de la serpiente desarrollado en **C++** utilizando la interfaz gráfica **Windows Forms (C++/CLI)** en **Visual Studio 2022**. El proyecto destaca por la implementación de **estructuras de datos dinámicas avanzadas** para la simulación del comportamiento y crecimiento de la serpiente, junto con técnicas avanzadas de renderizado gráfico de 2D sin parpadeo.

---

## 🛠️ Tecnologías y Herramientas Utilizadas

* **Lenguaje:** C++ / C++ CLI (Common Language Infrastructure).
* **Entorno de Desarrollo:** Visual Studio 2022.
* **Librerías Gráficas:** `System::Drawing` (`BufferedGraphics`, `Bitmap`, `Graphics`).
* **Framework:** .NET / Windows Forms.

---

## 📑 Estructura del Código y Componentes Principales

### 1. Lista Doblemente Enlazada (`NODO.hpp`)
* **Clase `NODO`**: Representa cada segmento individual del cuerpo de la serpiente o elemento del juego.
* **Atributos:**
  * Coordenadas `(x, y)` en la cuadrícula.
  * Punteros `siguiente` y `anterior` para navegación bidireccional.
* **Renderizado:** Método `Dibujar()` con recortes de imagen tipo Sprite usando `System::Drawing::Rectangle`.

### 2. Herencia y Comportamiento de la Manzana (`NODOMANZA.h` / `NODOMANZA.cpp`)
* **Clase `NODOMANZA`**: Hereda públicamente de la clase `NODO`.
* **Encapsulamiento:** Maneja el estado del objetivo (`viva` / `muerta`) mediante métodos `getviva()` y `setviva()`.

### 3. Lógica Principal y Gestión del Cuerpo (`Serpiente.h` / `Serpiente.cpp`)
* **Clase `SERPIENTE`**: Modela el comportamiento completo del jugador empleando punteros.
* **Características Clave:**
  * **Crecimiento Dinámico:** Extensión de la lista doblemente enlazada al colisionar con la manzana.
  * **Algoritmo Recursivo:** Actualización de posiciones (`actualizarpos`) y liberación limpia de memoria (`EliminarCompletamente`).
  * **Detección de Colisiones:** Comprueba impacto contra los límites del mapa y automordeduras (colisión del nodo cabeza contra su propia lista).
  * **Lógica Visual de Esquinas:** Evaluación topológica de los nodos vecinos (`anterior` y `siguiente`) para dibujar texturas de giro específicas (`n1`, `n2`, `n3`, `n4`) según la dirección.

### 4. Interfaz Gráfica y Game Loop (`MyForm.h`)
* **Doble Buffer (`BufferedGraphics`):** Minimiza el parpadeo visual (*flickering*) al renderizar en memoria antes de volcar la imagen al formulario.
* **Menú Integrado y Dificultad:** Control del flujo de ejecución mediante panel de bienvenida antes de iniciar y configuración del intervalo de tiempo (`Timer`).
* **Captura de Eventos:** Interrupción y respuesta de teclado (`KeyDown`) para el movimiento en 4 direcciones (Up, Down, Left, Right).

---

## 🎮 Características del Juego

* **Pantalla de Bienvenida:** Menú de inicio con selección de dificultad (*Lento*, *Intermedio*, *Rápido*).
* **Control de Velocidad:** Menú desplegable dinámico (`MenuStrip`) para ajustar la dificultad en tiempo real.
* **Conteo de Puntuación:** Cálculo dinámico basado en la longitud conseguida por la serpiente.
* **Gráficos por Capas:** Renderizado de sprites personalizados para la cabeza, esquinas de giro, cuerpo recto y manzana.

---

## 🚀 Cómo Ejecutar el Proyecto

1. Clona este repositorio:
   ```bash
   git clone [https://github.com/MaaM02/snake-game-cpp.git](https://github.com/MaaM02/snake-game-cpp.git)
