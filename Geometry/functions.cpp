double area(vector<Point>v){	// Return the area of the convex hull.
	double ret=0.0;
	int n=v.size();
	for(int i=0; i<v.size(); i++){
		ret+=v[i].x*(v[(i+1+n)%n].y-v[(i-1+n)%n].y);
	}
	return abs(ret/2);
}

double perimeter(vector<Point> v){	// Return the perimeter of the convex hull.
	double ans=0.0;
	v.pb(v[0]);
	for(int i=0; i<v.size()-1; i++){
		ans+=sqrt((v[i].x-v[i+1].x)*(v[i].x-v[i+1].x)+(v[i].y-v[i+1].y)*(v[i].y-v[i+1].y));
	}
	return ans;
}

Point rotate(Point c, Point po, double ang){	// Rotate po, around c by ang.
	/*
	 * C is the center of the rotation
	 * Po is the point to be rotated by ang in rad .
	 * Ang is the angle in radians to be rotated counter-clockwise.
	 */
	Point p;
	p.x=c.x+(po.x-c.x)*cos(ang)-(po.y-c.y)*sin(ang);
	p.y=c.y+(po.x-c.x)*sin(ang)-(po.y-c.y)*cos(ang);
	return p;
}
