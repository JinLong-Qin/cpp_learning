#include "012_Circle2.h"

int Circle2::get_R(){
	return m_r;
}

void Circle2::set_R(int r){
	m_r = r;
}

Point Circle2::getCenter(){
	return m_center;
}

void Circle2::setCenter(Point p){
	m_center = p;
}
