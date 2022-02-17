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
	
	cout << prva << " " << druga << endl;
	
	int prvaNum=strToMilisec(prva)+pomak;
	int drugaNum=strToMilisec(druga)+pomak;
	
	cout << prvaNum << " " << drugaNum << endl;
	
	prva=milisecToStr(prvaNum);
	druga=milisecToStr(drugaNum);
	
	cout << prva << " " << druga << endl << endl;

	str=prva+" --> "+druga;
	
	return str;
}

int strToMilisec(string str){
	int hour,min,sec,mili;
	hour=(str[0]-'0')*10+(str[1]-'0');
	min=(str[3]-'0')*10+(str[4]-'0');
	sec=(str[6]-'0')*10+(str[7]-'0');
	mili=(str[9]-'0')*100+(str[10]-'0')*10+(str[11]-'0');
	mili+=sec*100+min*100*60+hour*100*60*60;	
	return mili;
}

string milisecToStr(int mili){
	int hour,min,sec;
	hour=mili/360000;
	mili%=360000;
	min=mili/6000;
	mili%=6000;
	sec=mili/100;
	mili%=100;
	
	string hourStr,minStr,secStr,miliStr;
	string ret="";
	
	stringstream ss;  
    ss << hour;  
  	ss >> hourStr;
  	
  	ss << min;  
  	ss >> minStr;
  	
  	ss << sec;  
  	ss >> secStr;
  	
  	ss << mili;  
  	ss >> miliStr;
  	
  	if(hour<10) ret+="0";
  	ret+=hourStr;
  	ret+=":";
  	
  	if(min<10) ret+="0";
  	ret+=minStr;
  	ret+=":";
  	
  	if(sec<10) ret+="0";
  	ret+=secStr;
  	ret+=",";
  	
  	if(mili<10) ret+="00";
  	else if(mili<100) ret+="0";
  	ret+=miliStr;
  	
	
	
	
	return ret;
}

//00:02:05,234 --> 00:02:05,984
