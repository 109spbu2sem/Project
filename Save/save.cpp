#include "Save.h"

Save::Save(){
	_way = "test.txt";
};
string Save::fileWay(string way) {
	_way = way;
	return _way;
}
void Save::save(){
	if (_action.StreamIsOpened()) throw std::logic_error("Stream is opened");
	else _action.OpenStream();
	_save.open(_way, ios_base::out | ios_base::trunc);
	unsigned sizePoints = _action.GetFromStream();
	unsigned sizeSegments = _action.GetFromStream();
	unsigned sizeCircles = _action.GetFromStream();
	unsigned sizeConstraints = _action.GetFromStream();
	_save << "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n";
	_save << "<primitive>\n";
	_save << "	<amount>\n";
	_save << "		<point>" << sizePoints << "</point>\n";
	_save << "		<segment>" << sizeSegments << "</segment>\n";
	_save << "		<circle>" << sizeCircles << "</circle>\n";
	_save << "		<constraint>" << sizeConstraints << "</constraint>\n";
	_save << "	</amount>\n";
	_save << "	<coordinates>\n";
	for (unsigned i = 0;; ++i)
		_save << "		<point x=\""
		<< _action.GetFromStream() << "\" y=\""
		<< _action.GetFromStream() << "\">"
		<< " Point</point>\n";
	for (unsigned i = 0;; ++i)
		_save << "		<segment Ax=\""
		<< _action.GetFromStream() << "\" Ay=\""
		<< _action.GetFromStream() << "\" Bx=\""
		<< _action.GetFromStream() << "\" By=\""
		<< _action.GetFromStream() << "\">"
		<< " Segment</segment>\n";
	_save << "	</coordinates>\n";
	_save << "</primitive>\n";

	_save.close();
	_action.CloseStream();
}