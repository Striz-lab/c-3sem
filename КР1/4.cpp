

std::string GetRegex() {return "(0|1(10)*(0|11)(01*01|01*00(10)*(0|11))*1)*";}

//https://stackoverflow.com/questions/34476333/regular-expression-for-binary-numbers-divisible-by-5
// (0|111|100((1|00)0)*011|(101|100((1|00)0)*(1|00)1)(1((1|00)0)*(1|00)1)*(01|1((1|00)0)*011)|(110|100((1|00)0)*010|(101|100((1|00)0)*(1|00)1)(1((1|00)0)*(1|00)1)*(00|1((1|00)0)*010))(1|0(1((1|00)0)*(1|00)1)*(00|1((1|00)0)*010))*0(1((1|00)0)*(1|00)1)*(01|1((1|00)0)*011))*

// (0|1(01*0)*1)*
