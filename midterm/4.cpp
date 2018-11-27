//PREPEND BEGIN
#include<iostream>
#include<cstring>

using namespace std;

char** split(const char *s, char c, int &n);

int main()
{
    char s[100];
    int n;
    char sep;
    cin.getline(s, 100);
    sep = getchar();
    char** p = split(s, sep, n);
    cout << n << endl;
      if (p) {
      for (int i = 0; i < n; ++i){
          cout << p[i] << endl;
          delete[] p[i];
      }
      delete[] p;
    }
    return 0;
}
//PREPEND END

//TEMPLATE BEGIN
char** split(const char *s, char c, int &n){
    // TODO
    n = 0;
    int len = strlen(s);
    char *n_s = new char[len];
    bool check = 0;
    int ll = 0;
    for (int i = 0;i < len; i++) {
    	n_s[i] = s[i];
    	if (n_s[i] == c) n_s[i] = '\0'; 
    	if (n_s[i] != '\0' && check == 0) {
    		ll = i;
			n++;
			check = 1;
		}
		else if(n_s[i] == '\0'){
			check = 0;
		}
	}
	if (n == 0) return NULL;
	
	int l = 0;
	char **p = new char* [n];
	char *ptr = n_s;
	check = 0;
	for (int i = 0;i < len; i++) {
		if (n_s[i] != '\0' && check == 0) {
            // p[l] = ptr;
			strcpy(p[l]=new char[99],ptr); // change
			l++;
			check = 1;
		}
		else if(n_s[i] == '\0'){
			check = 0;
		}
		ptr++;
	}
	return p;
}
//TEMPLATE END