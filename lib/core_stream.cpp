#include "core.h"

bool CORE::OpenStream()
{
	if (_streamstate) return false;

	_streamstate = POINTCASE;
	_pointstream = _storage_of_points.getStartingViewer();
	_segmentstream = _storage_of_segments.getStartingViewer();
	_circlestream = _storage_of_circles.getStartingViewer();
	_constrstream = _storage_of_constraints.getStartingViewer();

	return true;

}

bool CORE::StreamIsOpened()
{
	return _streamstate ? true : false;
}

CORE::Primitive CORE::GetFromStream()
{
	CORE::Primitive ans{ 0, PRIMITIVE_NOTHING, 0, 0, 0, 0, 0, Color(0), false };
	switch (_streamstate)
	{
	case POINTCASE:
	{
		if (!_pointstream.canMoveNext()) _streamstate = SEGMENTCASE;
		else
		{
			//CORE::Primitive ans;
			ans.id = _pointstream.getValue().id.getID();
			ans.type = PRIMITIVE_POINT;
			ans.p1_x = *_pointstream.getValue()._x;
			ans.p1_y = *_pointstream.getValue()._y;
			ans.p2_x = 0;
			ans.p2_y = 0;
			ans.r = 0;
			ans.color = _pointstream.getValue().color;
			ans.select = _pointstream.getValue().isSelected();

			if (_pointstream.canMoveNext()) _pointstream.moveNext();
			else _streamstate = SEGMENTCASE;
			return ans;
		}
	}
		// stream of segments
	case SEGMENTCASE:
	{
		if (!_segmentstream.canMoveNext()) _streamstate = CIRCLECASE;
		else
		{
			//CORE::Primitive ans;
			ans.id = _segmentstream.getValue().id.getID();
			ans.type = PRIMITIVE_SEGMENT;
			ans.p1_x = *_segmentstream.getValue()._p1->_x;
			ans.p1_y = *_segmentstream.getValue()._p1->_y;
			ans.p2_x = *_segmentstream.getValue()._p2->_x;
			ans.p2_y = *_segmentstream.getValue()._p2->_y;
			ans.r = 0;
			ans.color = _segmentstream.getValue().color;
			ans.select = _segmentstream.getValue().isSelected();
			

			if (_segmentstream.canMoveNext()) _segmentstream.moveNext();
			else _streamstate = CIRCLECASE;
			return ans;
		}
	}
		// stream of circles
	case CIRCLECASE:
	{
		if (!_circlestream.canMoveNext()) _streamstate = STREAMISCLOSE;
		else
		{
			ans.id = _circlestream.getValue().id.getID();
			ans.type = PRIMITIVE_CIRCLE;
			ans.p1_x = *_circlestream.getValue()._o->_x;
			ans.p1_y = *_circlestream.getValue()._o->_y;
			ans.p2_x = 0;
			ans.p2_y = 0;
			ans.r = *_circlestream.getValue()._r;
			ans.color = _circlestream.getValue().color;
			ans.select = _circlestream.getValue().isSelected();
	
			if (_circlestream.canMoveNext()) _circlestream.moveNext();
			else _streamstate = STREAMISCLOSE;
			return ans;
		}
		break;
	}
	default:
		//return ans;
		throw std::logic_error("Stream is closed");
	}
	return ans;
}

void CORE::CloseStream()
{
	_streamstate = STREAMISCLOSE;
}
