#include<dirent.h>
#include<string.h>
#include<string>
#include<iostream>
#include<sys/stat.h>
using namespace std;
class mp3{
public:
void explore( string Desktop){
	DIR *dir;
	struct dirent *entry;
	struct stat info;
	dir = opendir(Desktop.c_str());
	if(!dir)
	{ cout<<"not found";
	}
	while(      (entry = readdir(dir))  != NULL){
		if(entry->d_name[0] != '.'){
			string path = string(Desktop) + "/" + string(entry->d_name);
			cout<<"Entry= " << path <<endl;
			stat(path.c_str(),&info);   //
			if(S_ISDIR(info.st_mode)){
				explore(path) ;
			}
                  if(entry->d_type==DT_REG){
			  if(entry->d_name[strlen(entry->d_name)-1]=='3')
			  cout<<entry->d_name<<" "<<endl;
		  }
		}
       closedir(dir);

	}


}




};
                                    

int main(){ mp3 m;
      string s;
      cout<<"Enter the path..."<<endl;
      cin>>s;
       m.explore(s);


	
	return 0;
}
