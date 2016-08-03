#pragma once
#include "pathpartmovable.h"

//Part created as a result of cutter compensation. It has no reference to input G-code
class PathPartOffsetLine :
	public PathPartMovable
{
public:
	//Constructors
	PathPartOffsetLine(Point beginning, Point end, double feed, WorkingPlane p, size_t line);
	~PathPartOffsetLine(void);

	//Getters & setters
	PathPartType GetType(){return LINE_OFFSET;};
	Vector3D GetStartingTangent();
	Vector3D GetEndingTangent();
	Vector3D GetOffsetStartingTangent();
	Vector3D GetOffsetEndingTangent();
	PathPartSimple ToSimple();
	Point GetOffsetStartingPoint(){return startingPoint;};
	Point GetOffsetEndingPoint(){return endingPoint;};
	void SetOffsetStartingPoint(Point& p){throw exception("BUG: Nastaven� offsetu u odsazen� p��mky.");};
	void SetOffsetEndingPoint(Point& p){throw exception("BUG: Nastaven� offsetu u odsazen� p��mky.");};
	PathOffsets& GetOffset(){throw exception("BUG: Snaha o z�sk�n� offsetu u odsazen� p��mky."); return nullOffset;};
	Point GetAdditionalPoin(){throw exception("BUG: Vol�n� dodate�n�ho bodu u p��mky."); return Point();};

	//Convert functions
	PathPartSimple ToOffsetSimple();
	bool IsOffset(){return true;};
	ProcessedData TransformToCommand();

	//Process functions
	void ProcessUnchangedOffsetStart(PathPart* prev, PathPart* next, GCodeInterpreter& in){throw exception("BUG: Vol�n� funkce pro proveden� odsazen� na odsazen�m prvku");};;
	void ProcessChangedOffsetStart(PathPart* prev, PathPart* next, GCodeInterpreter& in){throw exception("BUG: Vol�n� funkce pro proveden� odsazen� na odsazen�m prvku");};
	void ProcessNoOffsetStart(PathPart* prev){throw exception("BUG: Vol�n� funkce pro proveden� odsazen� na odsazen�m prvku");};
	void ProcessUnchangedOffsetEnd(PathPart* next, PathPart* prev, GCodeInterpreter& in){throw exception("BUG: Vol�n� funkce pro proveden� odsazen� na odsazen�m prvku");};
	void ProcessChangedOffsetEnd(PathPart* next, PathPart* prev, GCodeInterpreter& in){throw exception("BUG: Vol�n� funkce pro proveden� odsazen� na odsazen�m prvku");};
	void ProcessNoOffsetEnd(PathPart* next){throw exception("BUG: Vol�n� funkce pro proveden� odsazen� na odsazen�m prvku");};
	void ComputeSpeeds(GCodeInterpreter& in);

private:
	double Astart, Aend;
	double GetSFromStartMovement(double v, double v0, double A, double J, bool save);
	double GetSFromEndMovement(double v, double vb, double A, double J, bool save);
	void GetATFromMovement(double v, double v2, double Ak, double J, double& A, double& T);
};

