#pragma once
#include <string>
#include "ui/limage.h"
#include "ui/lcolor.h"
#include "foenum.h"
#include "assets.h"
#include "point.h"
class Field; // This is for avoiding cyclic includes

class FO{
	protected:
		FOType type;
		FOWhat what;
		Field* currField;
		Point pos;
		int order=-1; // Нужно для Field
	public:
		FOType getType() const;
		FOWhat getWhat() const;
		Field* getField();
		Point getPos() const;

		void setPos(Point p);

		FO(Point p, Field* currField);
		virtual ~FO();

		virtual void update();
		virtual std::pair<LImage*, LColor> getImage(Assets* ass) const;

		static std::string whatToLocalizedString(FOWhat);

		friend class Field;
};
