#include <bits/stdc++.h>

using namespace std;

int pomak;
string remake(string str);
string milisecToStr(int mili);
int strToMilisec(string str);

int main() {
	int index=0;
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
	string prva="",druga="";
	for(int i=0;i<12;i++){
		prva+=str[i];
		druga+=str[i+17];
	}
	int prvaNum=strToMilisec(prva)+pomak;
	int drugaNum=strToMilisec(druga)+pomak;
	
	prva=milisecToStr(prvaNum);
	druga=milisecToStr(drugaNum);

	str=prva+" --> "+druga;
	
	return str;
}

int strToMilisec(string str){
	
	return 0;
}

string milisecToStr(int mili){
	
	return "";
}
