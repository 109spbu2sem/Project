struct vec2{
	double x,y;
	vec2(double _x,double _y):x(_x),y(_y){};
	/*vec2 sum(const vec2& v){
		vec2 v_res(x,y);
		v_res.x += v.x;
		v_res.y += v.y;
		return v_res;
	};*/
	vec2 operator +(const vec2 &v){		
		vec2 v_res(x,y);
		v_res.x += v.x;
		v_res.y += v.y;
		return v_res;
	};

};