#include <bits/stdc++.h>

using namespace std;

int main() {
	int pomak;
	string myText,filename;
	printf("Unesite path do trazene datoteke:\n");
    getline(cin, filename);
    printf("Unesite pomak u milisekundama, negativnu vrijednost za pomak unatrag:\n");
    cin >> pomak;
    fstream MyReadFile( filename.c_str() );
  
	/*while(getline(MyReadFile,myText)){
		if(myText=="lol") MyReadFile << 1 << endl;
		else MyReadFile << 2 << endl;
	}*/
	
	for(int i=0;i<5;i++){
		MyReadFile >> myText;
		if(myText=="lol") MyReadFile << 1 << endl;
		else MyReadFile << 2 << endl;
	}
	
	MyReadFile.close();
	
	return 0;
}
