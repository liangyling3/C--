operator = (const C & c) {
	this->A::operator = (c) 
	//����A�е�operator = Ҫ��ȫ��д�������˴���(c)�ǲ���;
	b = c.b;
	d = c.d;
	return * this;
}
