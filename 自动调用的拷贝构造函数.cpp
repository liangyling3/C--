operator = (const C & c) {
	this->A::operator = (c) 
	//调用A中的operator = 要把全名写出来，此处的(c)是参数;
	b = c.b;
	d = c.d;
	return * this;
}
