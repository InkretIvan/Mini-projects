#include <bits/stdc++.h>

using namespace std;

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

	for(int i=0;i<index;i++){
		if(lines[i]=="lol") MyWriteFile << 1 << endl;
		else MyWriteFile << 2 << endl;
	}
	
	
	return 0;
}
