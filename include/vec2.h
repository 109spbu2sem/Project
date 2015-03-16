struct vec2
{
	double x,y;
	vec2(double _x,double _y);
	vec2 operator +(const vec2& v)
	{
		vec2 v_res(x,y);
		v_res.x += v.x;
		v_res.y += v.y;
		return v_res;
	}

};
