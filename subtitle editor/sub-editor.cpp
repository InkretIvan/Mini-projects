#include <bits/stdc++.h>

using namespace std;

string remake(string str);
string milisecToStr(int mili);
int strToMilisec(string str);

int main() {
	int pomak,index=0;
	vector<string> lines;
	string myText,filename;
	printf("Unesite path do trazene datoteke:\n");
    getline(cin, filename);
    printf("Unesite pomak u milisekundama, negativnu vrijednost za pomak unatrag:\n");
    cin >> pomak;
    ifstream MyReadFile( filename.c_str() );
	
	while(getline(MyReadFile,myText)){
		lines.push_back(myText);
		index++;
	}
	
	MyReadFile.close();
	
	ofstream MyWriteFile( filename.c_str() );
	MyWriteFile.clear();

	string linijePrije[2]={"",""};
	for(int i=0;i<index;i++){
		string str=lines[i];
		if(i==0){
			MyWriteFile << str << endl;
			linijePrije[0]=str;
			continue;
		}
		if(i==1){
			str=remake(str);
			linijePrije[1]=str;
			MyWriteFile << str << endl;
			continue;
		}
		if(linijePrije[0]==""){
			str=remake(str);
			linijePrije[0]=linijePrije[1];
	    	linijePrije[1]=str;
			MyWriteFile << str << endl;	
			continue;
		}
		linijePrije[0]=linijePrije[1];
		linijePrije[1]=str;
		MyWriteFile << str << endl;
	}
	
	
	return 0;
}

string remake(string str){
	
	
	return str;
}

int strToMilisec(string str){
	
	return 0;
}

string milisecToStr(int mili){
	
	return "";
}
