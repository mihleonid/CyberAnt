#pragma once
#include <string>
#include <vector>
#include <map>
#include "ui/limage.h"
#include "ui/lcolor.h"
#include "foenum.h"
#include "assets.h"
#include "point.h"
class Field; // This is for avoiding cyclic includes

class FO{
	private:
		static std::map<FOWhat, std::string> whatNamesCache;
	protected:
		FOType type;
		FOWhat what;
		Field* currField;
		Point pos;
		int order=-1; // Нужно для Field
		int health;
		int maxhealth;
	public:
		FOType getType() const;
		FOWhat getWhat() const;
		Field* getField();
		Point getPos() const;
		int getHealth() const;
		int getMaxHealth() const;

		void setPos(Point p);

		FO(Point p, Field* currField);
		virtual ~FO();
		virtual bool damage(int); // Return is deleted

		virtual void update();
		virtual std::pair<LImage*, LColor> getImage(Assets* ass) const;

		static std::string whatToLocalizedString(FOWhat);
		static std::string whatToString(FOWhat);
		static std::vector<FOWhat> getAllWhats();

		friend class Field;
};

