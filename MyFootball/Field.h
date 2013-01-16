#pragma once
/**
@class Field
Class which represents the football game field.
*/
class Field
{
	public:
		/// Players positions on the field
		struct POS {
			/// Coord X
			int X;
			/// Coord Y
			int Y;
		} position[23];
		/// Field class constructor
		Field() {
			position[0].X = 290;
			position[0].Y = 190;
			for (int i=1; i<23; i++) {
				position[i].X = 0;
				position[i].Y = 0;
			}
		}
};
