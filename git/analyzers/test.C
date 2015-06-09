std::string str(int i){
	ostringstream stream; TString str;
	stream<<i;
	str = stream.str();
	return str.Data();
}
void test(){
	std::cout<<"Hello"+str(3)<<std::endl;
}
