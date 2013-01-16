#pragma once
#include "Field.h"

/**
@class Player
Class which represents the football player.
*/
ref class Player
{
	/// Contains mutex handle
	HANDLE hMutex;
	/// Football field
	Field* field;
	/// Player number
	int num;
	/// Color mark (true - blue, false - red)
	bool color;
	/// Max player step
	int MAX_STEP;

	public:
		/// Player action cycle
		void Play() {
			while(1) {
				WaitForSingleObject(hMutex, INFINITE);
				System::Threading::Thread::BeginCriticalRegion();
				try {
					int a =  (field->position[num].X - field->position[0].X) *
							 (field->position[num].X - field->position[0].X) +
							 (field->position[num].Y - field->position[0].Y) *
							 (field->position[num].Y - field->position[0].Y);
					a = int(sqrt(double(a)));
					// если возле мяча более трех своих игроков - пойдем защищать ворота
					int k_nap = 0;
					for (int i=1; i<=22; i++) {
						if (i % 2 == num % 2) {
							int a_temp = (field->position[i].X - field->position[0].X) *
										 (field->position[i].X - field->position[0].X) +
										 (field->position[i].Y - field->position[0].Y) *
										 (field->position[i].Y - field->position[0].Y);
							a_temp = int(sqrt(double(a_temp))); //вычисляем расстояние от очередного игрока до мяча
							if (a_temp<=a)
								k_nap++;
						}
					}
					if (k_nap<=5) {
						if (a >= MAX_STEP + 10) { //меняем координаты игрока
							field->position[num].X += MAX_STEP * (field->position[0].X - field->position[num].X) / a;
							field->position[num].Y += MAX_STEP * (field->position[0].Y - field->position[num].Y) / a;
						}
						else
						{
							//определяем позицию вражеских ворот
							int positionVOR_X,
								positionVOR_Y = 200;
							if (color) 
								positionVOR_X = 590;
							else positionVOR_X = 5;

							a =  (field->position[num].X - positionVOR_X) *
								 (field->position[num].X - positionVOR_X) +
								 (field->position[num].Y - positionVOR_Y) *
								 (field->position[num].Y - positionVOR_Y);
							a = int(sqrt(double(a)));
							int delta_X = MAX_STEP * (positionVOR_X - field->position[num].X) / a;
							int delta_Y = MAX_STEP * (positionVOR_Y - field->position[num].Y) / a;
							field->position[num].X += delta_X;
							field->position[num].Y += delta_Y;
							// идем к воротам
							field->position[0].X = field->position[num].X + delta_X;
							field->position[0].Y = field->position[num].Y + delta_Y;
						}
					}
					else {
						//определяем позицию своих ворот
						int positionVOR_X,
							positionVOR_Y = 200;
						if (!color)
							positionVOR_X = 590; 
						else positionVOR_X = 5;
						a =  (field->position[num].X - positionVOR_X) *
							 (field->position[num].X - positionVOR_X) +
							 (field->position[num].Y - positionVOR_Y) *
							 (field->position[num].Y - positionVOR_Y);
						a = int(sqrt(double(a)));
						int delta_X = MAX_STEP * (positionVOR_X - field->position[num].X) / (a * 2);
						int delta_Y = MAX_STEP * (positionVOR_Y - field->position[num].Y) / (a * 2);
						field->position[num].X += delta_X;
						field->position[num].Y += delta_Y;
					}
				}
				catch(...)
				{
					//System::Threading::Thread::EndCriticalRegion();
					//ReleaseMutex( hMutex );
				}
				//__finally
				//{
					System::Threading::Thread::EndCriticalRegion();
				//}
				ReleaseMutex(hMutex);
				System::Threading::Thread::Sleep(150);
			}
			return;
		}

		/// Player class constructor
		/// @param i - Player number
		/// @param col - Player color
		/// @param v - Max player step
		/// @param f - Field
		/// @param hMut - Mutex handle
		Player(int i, bool col, int v, Field* f, HANDLE hMut) {
			hMutex = hMut;
			field = f;
			num = i;
			color = col;
			MAX_STEP = v;
		}
};
