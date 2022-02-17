#include <bits/stdc++.h>

using namespace std;

int pomak;
string remake(string str);
string milisecToStr(int mili);
int strToMilisec(string str);

int main() {
	printf("UPUTE:\n");
	printf("Otvoriti srt file s titlovima, ctrl+a da sve oznacite i zatim ctrl+c da kopirate\n");
	printf("napraviti novi file titlovi.srt ili ime po volji, unutra zalijepiti sadrzaj prvog filea\n");
	printf("slijediti upute dolje\n");
	printf("-----------------\n");
	
	int index=0;
	vector<string> lines;
	string myText,filename;
	printf("Unesite path do trazene datoteke (npr. titlovi.srt): \n");
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
	printf("gotovo:)\n");
	system("PAUSE");
	
	return 0;
}

string remake(string str){
	string prva="",druga="";
	for(int i=0;i<12;i++){
		prva+=str[i];
		druga+=str[i+17];
	}
	
	//cout << prva << " " << druga << endl;
	
	int prvaNum=strToMilisec(prva)+pomak;
	int drugaNum=strToMilisec(druga)+pomak;
	
	//cout << prvaNum << " " << drugaNum << endl;
	
	prva=milisecToStr(prvaNum);
	druga=milisecToStr(drugaNum);
	
	//cout << prva << " " << druga << endl << endl;

	str=prva+" --> "+druga;
	
	//cout << str << endl;
	
	return str;
}

int strToMilisec(string str){
	int hour,min,sec,mili;
	hour=(str[0]-'0')*10+(str[1]-'0');
	min=(str[3]-'0')*10+(str[4]-'0');
	sec=(str[6]-'0')*10+(str[7]-'0');
	mili=(str[9]-'0')*100+(str[10]-'0')*10+(str[11]-'0');
	mili+=sec*1000+min*1000*60+hour*1000*60*60;	
	return mili;
}

string milisecToStr(int mili){
	//cout << mili << endl;
	
	int hour,min,sec;
	hour=mili/3600000;
	mili%=3600000;
	min=mili/60000;
	mili%=60000;
	sec=mili/1000;
	mili%=1000;
	
	//cout << hour << " " << min << " " << sec << " " << mili << endl;
	
	string hourStr,minStr,secStr,miliStr;
	string ret="";
	
	hourStr=to_string(hour);
	minStr=to_string(min);
	secStr=to_string(sec);
	miliStr=to_string(mili);
  		
   //cout << hourStr << " " << minStr << " " << secStr << " " << miliStr << endl;
  	
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
